import yaml
import os
import re
from pathlib import Path
import sys

g_pkg_name = None
g_pkg_path = None
g_pkg_include_path = None
g_proj_include_path = None
g_proj_src_path = None
g_target_msgs = None

g_target_msgs_dict = {}
g_target_msgs_fields_dict = {}
g_dual_msg_list = []
g_nonloop_dual_msg_list = []
g_errors = []

g_config_file_name = 'config.yaml'
g_lib_project_name = 'ros2lib'
g_ros2lib_dir_include_ROS2Communication = f'./include/{g_lib_project_name}/ROS2Communication'
g_ros2lib_dir_IROS2Callback             = f'./include/{g_lib_project_name}/interface'
g_ros2lib_dir_src_ROS2Communication     = f'./src/{g_lib_project_name}/ROS2Communication'
g_ros2libTester_dir_include = './../ros2libTester/include'
g_ros2libTester_dir_src = './../ros2libTester/src'

# Load YAML configuration
def load_config():
    with open(g_config_file_name, 'r') as file:
        config = yaml.safe_load(file)

        global g_pkg_name, g_pkg_path, g_pkg_include_path, g_proj_include_path, g_proj_src_path, g_target_msgs
        g_pkg_name = config['args']['custom_msg_pkg_name']
        g_pkg_path = Path(config['args']['custom_msg_pkg_path'])
        g_pkg_include_path = Path(config['args']['custom_msg_pkg_include_path'])
        g_proj_include_path = config['args']['proj_include_path']
        g_proj_src_path = config['args']['proj_src_path']
        g_target_msgs = config['target_msgs']

# Function to create directory if it doesn't exist
def ensure_directory(path):
    os.makedirs(path, exist_ok=True)

# Function to convert CamelCase to snake_case for filenames
def camel_to_snake(name):
    s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
    return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()

# Check if there is a error / if exists, exit
def check_error():
    global g_errors

    if g_errors:
        print("g_errors encountered during file generation : ")
        for error in g_errors:
            print(error)
        
        print("Exiting due to g_errors.")
        sys.exit(1)

# Remove redundances in target_msgs list & intergrate same publish, loop_publish msg to loop
def refine_target_msgs(): 
    global g_target_msgs
    global g_target_msgs_dict, g_dual_msg_list, g_nonloop_dual_msg_list, g_errors

    # Make dictionary, then remove redundance in same category
    for category, msg_names in g_target_msgs.items():
        g_target_msgs_dict[category] = list(set(msg_name.strip() for msg_name in msg_names.split(', ')))
    
    # intergrate same publish, loop_publish msg to loop
    if 'publish' in g_target_msgs_dict and 'loop_publish' in g_target_msgs_dict: 
        loop_publish_msgs = set(g_target_msgs_dict['loop_publish'])

        g_target_msgs_dict['publish'] = [msg for msg in g_target_msgs_dict['publish'] if msg not in loop_publish_msgs]

    # Store pub-sub both use, cli-srv both use case  
    if 'publish' in g_target_msgs_dict and 'loop_publish' in g_target_msgs_dict and 'subscribe' in g_target_msgs_dict:
        pub_sub_common_msgs = (set(g_target_msgs_dict['publish'])) & (set(g_target_msgs_dict['subscribe']))
        loop_pub_set = set(g_target_msgs_dict['loop_publish'])
        sub_set = set(g_target_msgs_dict['subscribe'])
        pub_sub_common_msgs = loop_pub_set & sub_set
        g_dual_msg_list.extend(pub_sub_common_msgs)
        pub_set = set(g_target_msgs_dict['publish'])
        nonloop_pub_sub_common_msgs = pub_set & sub_set
        g_nonloop_dual_msg_list.extend(nonloop_pub_sub_common_msgs)
    else:
        g_errors.append(f'category publish or loop_publish or subscribe does not exist in {g_config_file_name}')

        g_dual_msg_list.extend(pub_sub_common_msgs)
    if 'service_client' in g_target_msgs_dict and 'service_server' in g_target_msgs_dict:
        cli_set = set(g_target_msgs_dict['service_client'])
        srv_set = set(g_target_msgs_dict['service_server'])
        cli_srv_common_msgs = cli_set & srv_set
        g_dual_msg_list.extend(cli_srv_common_msgs)
    else:
        g_errors.append(f'category service_client or service_server does not exist in {g_config_file_name}')

# parse .msg or .srv file and store field information to g_target_msgs_fields_dict
def parse_msg_file(file_path, msg_type, msg_class_name):
    global g_target_msgs_fields_dict 

    with open(file_path, 'r') as file:
        lines = file.readlines()
        last_comment_field = ''
        is_srv_response = False
        for line in lines:
            stripped_line = line.strip()
            parts = stripped_line.split()

            if stripped_line.startswith('#'): # if line starts with '#', regard as Symbolic Constant signal, convert to comment
                last_comment_field = stripped_line.replace(' ', '_')
                last_comment_field = last_comment_field[1:]
            elif '=' in stripped_line: # if line include '=', regard as Symbolic Constant element, convert to comment
                constant_type = parts[0]
                line_without_spaces = stripped_line.replace(" ", "")
                line_without_spaces = line_without_spaces.replace(constant_type, "", 1)
                constant_name = line_without_spaces.split('=')[0]  
                constant_value = line_without_spaces.split('=')[1] 

                # init
                if msg_class_name not in g_target_msgs_fields_dict[msg_type]:
                    g_target_msgs_fields_dict[msg_type][msg_class_name] = {}
                if 'constants' not in g_target_msgs_fields_dict[msg_type][msg_class_name]:
                    g_target_msgs_fields_dict[msg_type][msg_class_name]['constants'] = []

                g_target_msgs_fields_dict[msg_type][msg_class_name]['constants'].append({
                    'field': last_comment_field,
                    'name': constant_name,
                    'value': constant_value
                })
            elif any(stripped_line.startswith(typ) for typ in ['string',  'bool', 'byte', 'int8', 'int32', 'float32', 'float64']): # if line has this types, reard as field, convert to sample code
                field_type = parts[0]
                field_name = parts[1]

                # init
                if msg_class_name not in g_target_msgs_fields_dict[msg_type]:
                    g_target_msgs_fields_dict[msg_type][msg_class_name] = {}
                if 'fields' not in g_target_msgs_fields_dict[msg_type][msg_class_name]:
                    g_target_msgs_fields_dict[msg_type][msg_class_name]['fields'] = []

                if is_srv_response:
                    if 'responseFields' not in g_target_msgs_fields_dict[msg_type][msg_class_name]:
                        g_target_msgs_fields_dict[msg_type][msg_class_name]['responseFields'] = [] 

                    g_target_msgs_fields_dict[msg_type][msg_class_name]['responseFields'].append({
                        'type': field_type,
                        'name': field_name
                    })
                else: 
                    g_target_msgs_fields_dict[msg_type][msg_class_name]['fields'].append({
                        'type': field_type,
                        'name': field_name
                    })
            elif msg_type == 'srv' and stripped_line.startswith('-'): # if line starts with '-', regard as response msg, convert to sample code
                is_srv_response = True
        
# Check if message .hpp files exist in the include path & fine field of msg_class 
def check_hpp_existence():
    global g_pkg_name, g_pkg_path, g_pkg_include_path
    global g_target_msgs_dict, g_target_msgs_fields_dict, g_errors

    g_target_msgs_fields_dict['msg'] = {}
    g_target_msgs_fields_dict['srv'] = {}

    # Remove repeatition 
    msg_names_set = set()
    for category, msg_names in g_target_msgs_dict.items():
        msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
        for msg_class_name in msg_names:
            msg_names_set.add((msg_type, msg_class_name))

    isErrorDetected = False
    for msg_type, msg_class_name in msg_names_set:
        file_name = camel_to_snake(msg_class_name) + '.hpp'
        file_dir = str(g_pkg_include_path) + f'\{msg_type}'
        file_path = Path(file_dir) / f'{file_name}'
        if file_path.exists():
            msg_file_name = msg_class_name + f'.{msg_type}'
            msg_file_dir = str(g_pkg_path) + f'/{msg_type}'
            msg_file_path = Path(msg_file_dir) / f'{msg_file_name}'
            if msg_file_path.exists():
                parse_msg_file(msg_file_path, msg_type, msg_class_name)
            else:
                isErrorDetected = True
                g_errors.append(f"Error : '{msg_class_name}' in config.yaml cause error.")
                g_errors.append(f"Error : '{msg_file_name}' does not exist in {msg_file_dir}.")
        else:
            isErrorDetected = True
            g_errors.append(f"Error : '{msg_class_name}' in config.yaml cause error.")
            g_errors.append(f"Error : '{file_name}' does not exist in {file_dir}.")

    if isErrorDetected:
        g_errors.append("Recommend : Make sure msg name / custom msg package build / topic, srv inclusion in custom msg CMakeLists.txt.")
        check_error()

# Check if path is exist
def check_path_existence():
    global g_proj_include_path, g_proj_src_path
    global g_errors
    global g_ros2lib_dir_include_ROS2Communication, g_ros2lib_dir_IROS2Callback, g_ros2lib_dir_src_ROS2Communication

    paths_to_check = [
        Path(g_ros2lib_dir_include_ROS2Communication),
        Path(g_ros2lib_dir_IROS2Callback),
        Path(g_ros2lib_dir_src_ROS2Communication),
        Path(g_ros2libTester_dir_include),
        Path(g_ros2libTester_dir_src),
        Path(g_proj_include_path), 
        Path(g_proj_src_path),
    ]

    for path in paths_to_check:
        if not path.exists():
            g_errors.append(f"Error : Path '{path}' does not exist.")
    
    check_error()

def init_config():
    load_config()
    refine_target_msgs()
    check_hpp_existence()
    check_path_existence()

# Function to write comment of constants 
def write_comment_of_constants(file, msg_type, msg_class_name):
    global g_target_msgs_fields_dict
    last_comment_field = ''
    writeCount = 0
    if 'constants' in g_target_msgs_fields_dict[msg_type][msg_class_name]:
        num_of_constant = len(g_target_msgs_fields_dict[msg_type][msg_class_name]['constants'])
        for constant in g_target_msgs_fields_dict[msg_type][msg_class_name]['constants']:
            # Write foreword
            if constant['field'] == '':
                if last_comment_field != 'NONE':
                    last_comment_field = 'NONE'
                    file.write(f'    // UNKNOWN CONSTANTS : [')
            elif last_comment_field != constant['field']: 
                if last_comment_field != '':
                    file.write(']\n') 
                writeCount = 0
                last_comment_field = constant['field']
                file.write(f'    // {last_comment_field} CONSTANTS : [')
            # Write constant
            file.write(f' {constant["name"]} = {constant["value"]} ')

            if writeCount / 4 > 0 and writeCount % 4 == 0 and writeCount != num_of_constant:
                file.write('\n') 
            writeCount += 1
        if last_comment_field != '':
            file.write(']\n\n') 

# Function to convert ROS2 msg field type to default value
def ros_field_type_to_default_value(var_type):
    if var_type == "string":
        default_value = '""'
    elif var_type == "bool":
        default_value = 'false'
    elif var_type == "byte" or var_type == "int32":
        default_value = '0'
    elif var_type == "float32":
        default_value = '0.f'
    elif var_type == "float64":
        default_value = '0.0'

    return default_value

# Function to convert ROS2 msg field type to c++ type
def ros_field_type_to_cpp_type(var_type):
    if var_type == "string":
        cpp_type = 'std::string'
    elif var_type == "bool":
        cpp_type = var_type
    elif var_type == "byte" or var_type == "int32":
        cpp_type = 'unsigned char'
    elif var_type == "float32":
        cpp_type = 'float'
    elif var_type == "float64":
        cpp_type = 'double'
    else:
        cpp_type = 'NONE'
    return cpp_type

# Function to generate MessageInclude.h in ros2lib
def generate_MessageInclude_in_ros2lib():
    global g_pkg_name, g_pkg_include_path
    global g_target_msgs_dict

    file_name = 'MessageInclude.h'
    path = Path(g_ros2lib_dir_include_ROS2Communication)
    file_path = path / file_name

    ensure_directory(path)

    with open(file_path, 'w') as file:
        file.write('/* Generated by GenROS2CustomPkgInterface.py */\n\n')

        file.write('#pragma once\n\n')

        include_statements = []
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                hpp_file_name = camel_to_snake(msg_class_name) + '.hpp'
                msg_file_path = (g_pkg_include_path / g_pkg_name) / f'{msg_type}/{hpp_file_name}'
                if msg_file_path:
                    relative_path = msg_file_path.relative_to(g_pkg_include_path / g_pkg_name).with_suffix("").as_posix()
                    statement = f'#include "{g_pkg_name}/{relative_path}.hpp"'
                    if statement not in include_statements:
                        file.write(statement + '\n')
                        include_statements.append(statement)

    print("Generation SUCCESS (overwrite) : " + file_name + " in " + str(Path.cwd()) + '\\' + str(path))

# Function to generate ROSMsgHandler.h in ros2lib
def generate_ROSMsgHandler_in_ros2lib():
    global g_pkg_name
    global g_lib_project_name
    global g_target_msgs_dict

    file_name = 'ROSMsgHandler.h'
    path = Path(g_ros2lib_dir_include_ROS2Communication)
    file_path = path / file_name

    ensure_directory(path)

    with open(file_path, 'w') as file:
        file.write("""/* Generated by GenROS2CustomPkgInterface */

#pragma once
#include <string>
#include <any>
#include <rclcpp/rclcpp.hpp>\n""")
        file.write(f'#include "{g_lib_project_name}/Definitions.h"\n')
        file.write(f'#include "{g_lib_project_name}/ROS2Communication/MessageInclude.h"\n')
        file.write("""
class ROSMsgHandler
{
private:
    static std::shared_ptr<ROSMsgHandler> Instance;

protected:
    ROSMsgHandler();
    ~ROSMsgHandler();
    ROSMsgHandler(const ROSMsgHandler&) = delete;
    ROSMsgHandler operator = (const ROSMsgHandler&) = delete;

public:
    static std::shared_ptr<ROSMsgHandler> GetInstance() {
        if (!Instance) {
            Instance = std::shared_ptr<ROSMsgHandler>(new ROSMsgHandler, [](ROSMsgHandler* p) {
                delete p;
            });
        }
        return Instance;
    }

    static void ReleaseInstance()
    {
        Instance.reset();
    }
    
public:
    void printLogMessage(const std::string& message);

public:
    template<typename T> std::string getROSMsgInterfaceName(const std::string& nameSpace);
    template<typename T> std::string getClassTypeName();
    std::string getNamespaceFromInterfaceName(const std::string& interfaceName);
};

template<typename T> std::string
ROSMsgHandler::getROSMsgInterfaceName(const std::string& nameSpace)
{
    std::string interfaceName = getClassTypeName<T>();
    if(nameSpace != "") 
        interfaceName = nameSpace + "/" + getClassTypeName<T>();

    return interfaceName;
}

template<typename T> std::string
ROSMsgHandler::getClassTypeName()
{\n""")

        wrote_msgs = []
        is_first_msg = True
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                if msg_class_name not in wrote_msgs:
                    if is_first_msg:
                        is_first_msg = False
                        file.write('    ')
                    else:
                        file.write('    else ')
                    msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                    file.write(f'if constexpr (std::is_same_v<T, {g_pkg_name}::{msg_type}::{msg_class_name}>) {{\n')
                    file.write(f'        return "{msg_class_name}";\n')
                    file.write('    }\n')
                    wrote_msgs.append(msg_class_name)

        file.write('\n    return "";\n')
        file.write('}')

    print("Generation SUCCESS (overwrite) : " + file_name + " in " + str(Path.cwd()) + '\\' + str(path))

# Function to generate IROS2Callback.h in ros2lib
def generate_IROS2Callback_in_ros2lib():
    global g_pkg_name
    global g_lib_project_name
    global g_target_msgs_dict, g_dual_msg_list, g_nonloop_dual_msg_list

    struct_name = 'IROS2Callback'
    file_name = struct_name + '.h'
    path = Path(g_ros2lib_dir_IROS2Callback)
    file_path = path / file_name

    ensure_directory(path)

    with open(file_path, 'w') as file:
        file.write('#pragma once\n\n')
        file.write(f'#include "{g_lib_project_name}/ROS2Communication/MessageInclude.h"\n\n')

        # Begin callback struct definition
        file.write('struct ' + struct_name + '\n{\n')
        # Write Application Project pure virtual functions
        file.write('    /* Application Project Override (Pure virtual) */\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                if category == 'loop_publish':
                    file.write(f'    virtual void SetLoopPublishTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) = 0;\n')
                elif category == 'subscribe':
                    file.write(f'    virtual void SubscribeTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) = 0;\n')
                elif category == 'service_client':
                    file.write(f'    virtual void RequestResponseReceive(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) = 0;\n')
                elif category == 'service_server':
                    file.write(f'    virtual void ServiceReceive(const std::string& nameSpace,\n')
                    file.write(f'                               {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr req,\n')
                    file.write(f'                               {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) = 0;\n')

        # Write Tester(ros2libTester) virtual functions
        file.write('\n    /* Tester Override (Virtual) */\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                if msg_class_name not in g_dual_msg_list:
                    msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                    if (category == 'publish' and msg_class_name not in g_nonloop_dual_msg_list) or category == 'loop_publish':
                        file.write(f'    virtual void SubscribeTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) {{}}\n')
                    elif category == 'subscribe':
                        file.write(f'    virtual void SetLoopPublishTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) {{}}\n')
                    elif category == 'service_client':
                        file.write(f'    virtual void ServiceReceive(const std::string& nameSpace,\n')
                        file.write(f'                               {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr req,\n')
                        file.write(f'                               {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) {{}}\n')
                    elif category == 'service_server':
                        file.write(f'    virtual void RequestResponseReceive(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) {{}}\n')

        file.write('};')

    print("Generation SUCCESS (overwrite) : " + file_name + " in " + str(Path.cwd()) + '\\' + str(path))

# Function to generate ROS2CommManagerExtensions.cpp in ros2lib
def generate_ROS2CommManagerExtensions_in_ros2lib():
    global g_pkg_name
    global g_lib_project_name
    global g_target_msgs_dict, g_dual_msg_list, g_nonloop_dual_msg_list

    file_name = 'ROS2CommManagerExtensions.cpp'
    path = Path(g_ros2lib_dir_src_ROS2Communication)
    file_path = path / file_name
    ensure_directory(path)

    with open(file_path, 'w') as file:
        file.write('/* Generated by GenROS2CustomPkgInterface.py */\n\n')
        file.write(f'#include "{g_lib_project_name}/ROS2Communication/ROS2CommManager.h"\n\n')
        file.write(f'#include "{g_lib_project_name}/ROS2Communication/topic/PublishNode.h"\n')
        file.write(f'#include "{g_lib_project_name}/ROS2Communication/topic/SubscribeNode.h"\n')
        file.write(f'#include "{g_lib_project_name}/ROS2Communication/service/ClientNode.h"\n')
        file.write(f'#include "{g_lib_project_name}/ROS2Communication/service/ServerNode.h"\n\n')  

        # Write manger task template implements 
        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::createPublisher(const std::string& nameSpace)\n')
        file.write('{\n')
        file.write('    m_publishNode->makePublisher<T>(nameSpace);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::createLoopPublisher(const std::string& nameSpace, std::chrono::milliseconds period)\n')
        file.write('{\n')
        file.write('    m_publishNode->makeLoopPublisher<T>(nameSpace, period);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::createSubscriber(const std::string& nameSpace)\n')
        file.write('{\n')
        file.write('    m_subscribeNode->makeSubscriber<T>(nameSpace);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::createClient(const std::string& nameSpace)\n')
        file.write('{\n')
        file.write('    m_clientNode->makeClient<T>(nameSpace);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::createServer(const std::string& nameSpace)\n')
        file.write('{\n')
        file.write('    m_serverNode->makeServer<T>(nameSpace);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::destroyPublisher(const std::string& nameSpace)\n')
        file.write('{\n')
        file.write('    m_publishNode->destroyPublisher<T>(nameSpace);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::destroySubscriber(const std::string& nameSpace)\n')
        file.write('{\n')
        file.write('    m_subscribeNode->destroySubscriber<T>(nameSpace);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::destroyClient(const std::string& nameSpace)\n')
        file.write('{\n')
        file.write('    m_clientNode->destroyClient<T>(nameSpace);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::destroyServer(const std::string& nameSpace)\n')
        file.write('{\n')
        file.write('    m_serverNode->destroyServer<T>(nameSpace);\n')
        file.write('}\n\n')

        file.write('template<typename T> void \n')
        file.write('ROS2CommManager::publishTopic(const std::string& nameSpace, const T& msg)\n')
        file.write('{\n')
        file.write('    m_publishNode->publish<T>(nameSpace, msg);\n')
        file.write('}\n\n')

        file.write('template<typename T> void\n')
        file.write('ROS2CommManager::sendServiceRequest(const std::string& nameSpace, const typename T::Request& req)\n')
        file.write('{\n')
        file.write('    m_clientNode->sendRequest<T>(m_clientNode, nameSpace, req);\n')
        file.write('}\n\n')

        prevType = ''
        # Write register callbacks
        file.write('void\nROS2CommManager::registerCallback(IROS2Callback* callback)\n{\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                if prevType != '' and prevType != category and prevType != 'publish':
                    file.write('\n')
                prevType = category
                
                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                if category == 'loop_publish':
                    file.write(f'    m_publishNode->registerLoopCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>(\n')
                    file.write(f'        std::bind(static_cast<void(IROS2Callback::*)(const std::string&, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr)>\n')
                    file.write(f'                (&IROS2Callback::SetLoopPublishTopic),\n')
                    file.write(f'            callback, std::placeholders::_1, std::placeholders::_2)\n')
                    file.write('    );\n')
                elif category == 'subscribe':
                    file.write(f'    m_subscribeNode->registerCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>(\n')
                    file.write(f'        std::bind(static_cast<void(IROS2Callback::*)(const std::string&, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr)>\n')
                    file.write(f'                (&IROS2Callback::SubscribeTopic),\n')
                    file.write(f'            callback, std::placeholders::_1, std::placeholders::_2)\n')
                    file.write('    );\n')
                elif category == 'service_client':
                    file.write(f'    m_clientNode->registerRspCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>(\n')
                    file.write(f'        std::bind(static_cast<void(IROS2Callback::*)(const std::string&, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr)>\n')
                    file.write(f'                (&IROS2Callback::RequestResponseReceive),\n')
                    file.write(f'            callback, std::placeholders::_1, std::placeholders::_2)\n')
                    file.write('    );\n')
                elif category == 'service_server':
                    file.write(f'    m_serverNode->registerCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>(\n')
                    file.write(f'        std::bind(static_cast<void(IROS2Callback::*)(const std::string&,\n') 
                    file.write(f'                                                    {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr,\n')
                    file.write(f'                                                    {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr)>\n')
                    file.write(f'                (&IROS2Callback::ServiceReceive),\n')
                    file.write(f'            callback, std::placeholders::_1, std::placeholders::_2,  std::placeholders::_3)\n')
                    file.write('    );\n')
        file.write('}\n\n')

        prevType = ''
        # Write undo register callbacks
        file.write('void\nROS2CommManager::unRegisterCallback()\n{\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                if prevType != '' and prevType != category and prevType != 'publish':
                    file.write('\n')
                prevType = category
                
                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                if category == 'loop_publish':
                    file.write(f'    m_publishNode->unRegisterLoopCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>();\n')
                elif category == 'subscribe':
                    file.write(f'    m_subscribeNode->unRegisterCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>();\n')
                elif category == 'service_client':
                    file.write(f'    m_clientNode->unRegisterRspCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>();\n')
                elif category == 'service_server':
                    file.write(f'    m_serverNode->unRegisterCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>();\n')
        file.write('}\n\n')

        prevType = ''
        # Write register callbacks for Tester
        file.write('void\nROS2CommManager::registerCallbackForTester(IROS2Callback* callback)\n{\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                if prevType != '' and prevType != category:
                    file.write('\n')
                prevType = category

                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                if category == 'publish' or category == 'loop_publish':
                    file.write(f'    m_subscribeNode->registerCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>(\n')
                    file.write(f'        std::bind(static_cast<void(IROS2Callback::*)(const std::string&, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr)>\n')
                    file.write(f'                (&IROS2Callback::SubscribeTopic),\n')
                    file.write(f'            callback, std::placeholders::_1, std::placeholders::_2)\n')
                    file.write('    );\n')
                elif category == 'subscribe':
                    file.write(f'    m_publishNode->registerLoopCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>(\n')
                    file.write(f'        std::bind(static_cast<void(IROS2Callback::*)(const std::string&, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr)>\n')
                    file.write(f'                (&IROS2Callback::SetLoopPublishTopic),\n')
                    file.write(f'            callback, std::placeholders::_1, std::placeholders::_2)\n')
                    file.write('    );\n')
                elif category == 'service_client':
                    file.write(f'    m_serverNode->registerCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>(\n')
                    file.write(f'        std::bind(static_cast<void(IROS2Callback::*)(const std::string&,\n') 
                    file.write(f'                                                    {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr,\n')
                    file.write(f'                                                    {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr)>\n')
                    file.write(f'                (&IROS2Callback::ServiceReceive),\n')
                    file.write(f'            callback, std::placeholders::_1, std::placeholders::_2,  std::placeholders::_3)\n')
                    file.write('    );\n')
                elif category == 'service_server':
                    file.write(f'    m_clientNode->registerRspCallback<{g_pkg_name}::{msg_type}::{msg_class_name}>(\n')
                    file.write(f'        std::bind(static_cast<void(IROS2Callback::*)(const std::string&, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr)>\n')
                    file.write(f'                (&IROS2Callback::RequestResponseReceive),\n')
                    file.write(f'            callback, std::placeholders::_1, std::placeholders::_2)\n')
                    file.write('    );\n')
        file.write('}\n\n')

        # Write Explicit Template
        file.write('/* Explicit Template Instantiation for .cpp implementation */\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                if category == 'publish':
                    file.write(f'template void ROS2CommManager::createPublisher<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    file.write(f'template void ROS2CommManager::destroyPublisher<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    file.write(f'template void ROS2CommManager::publishTopic<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace, const typename {g_pkg_name}::{msg_type}::{msg_class_name}& msg);\n')
                elif category == 'loop_publish':
                    file.write(f'template void ROS2CommManager::createLoopPublisher<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace, std::chrono::milliseconds period);\n')
                    file.write(f'template void ROS2CommManager::destroyPublisher<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                elif category == 'subscribe':
                    file.write(f'template void ROS2CommManager::createSubscriber<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    file.write(f'template void ROS2CommManager::destroySubscriber<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                elif category == 'service_client':
                    file.write(f'template void ROS2CommManager::createClient<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    file.write(f'template void ROS2CommManager::destroyClient<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    file.write(f'template void ROS2CommManager::sendServiceRequest<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace, const typename {g_pkg_name}::{msg_type}::{msg_class_name}::Request& req);\n')
                elif category == 'service_server':
                    file.write(f'template void ROS2CommManager::createServer<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    file.write(f'template void ROS2CommManager::destroyServer<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
        file.write('\n')
    
        # Write Explicit Template For Tester
        file.write('/* Explicit Template Instantiation for Tester */\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                if msg_class_name not in g_dual_msg_list:
                    if category == 'publish' or category == 'loop_publish':
                        file.write(f'template void ROS2CommManager::createSubscriber<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                        file.write(f'template void ROS2CommManager::destroySubscriber<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    elif category == 'subscribe':
                        file.write(f'template void ROS2CommManager::createLoopPublisher<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace, std::chrono::milliseconds period);\n')
                        file.write(f'template void ROS2CommManager::destroyPublisher<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    elif category == 'service_client':
                        file.write(f'template void ROS2CommManager::createServer<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                        file.write(f'template void ROS2CommManager::destroyServer<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                    elif category == 'service_server':
                        file.write(f'template void ROS2CommManager::createClient<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                        file.write(f'template void ROS2CommManager::destroyClient<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace);\n')
                        file.write(f'template void ROS2CommManager::sendServiceRequest<{g_pkg_name}::{msg_type}::{msg_class_name}>(const std::string& nameSpace, const typename {g_pkg_name}::{msg_type}::{msg_class_name}::Request& req);\n')

    print("Generation SUCCESS (overwrite) : " + file_name + " in " + str(Path.cwd()) + '\\' + str(path))

# Function to create .h, .cpp file in tester project
def generate_files_in_tester():
    global g_pkg_name, g_target_msgs
    global g_target_msgs_dict, g_target_msgs_fields_dict, g_dual_msg_list, g_nonloop_dual_msg_list
    global g_ros2libTester_dir_include, g_ros2libTester_dir_src

    # Generate ROS2Callback.h in application project header directory path  
    g_ros2libTester_dir_include = Path(g_ros2libTester_dir_include)
    include_path = g_ros2libTester_dir_include / 'ROS2'
    include_file_path = include_path / 'ROS2Callback.h'
    ensure_directory(include_path)

    with open(include_file_path, 'w') as file:
        file.write('#pragma once\n\n')
        file.write('#include "ros2lib/interface/IROS2Callback.h"\n\n')
        file.write('class ROS2Callback : public IROS2Callback\n{\n')

        # Write pure virtual functions override
        file.write('    /* Essential Override (Pure Virtual) */\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                if msg_class_name not in g_dual_msg_list:
                    msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                    if category == 'loop_publish':
                        file.write(f'    void SetLoopPublishTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) override;\n')
                    elif category == 'subscribe':
                        file.write(f'    void SubscribeTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) override;\n')
                    elif category == 'service_client':
                        file.write(f'    void RequestResponseReceive(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) override;\n')
                    elif category == 'service_server':
                        file.write(f'    void ServiceReceive(const std::string& nameSpace,\n')
                        file.write(f'                       {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr req,\n')
                        file.write(f'                       {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) override;\n')

        # Write tester virtual functions override
        file.write('\n    /* Tester Override (Virtual) */\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                if (category == 'publish' and msg_class_name not in g_nonloop_dual_msg_list) or category == 'loop_publish':
                    file.write(f'    void SubscribeTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) override;\n')
                elif category == 'subscribe':
                    file.write(f'    void SetLoopPublishTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) override;\n')
                elif category == 'service_client':
                    file.write(f'    void ServiceReceive(const std::string& nameSpace,\n')
                    file.write(f'                       {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr req,\n')
                    file.write(f'                       {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) override;\n')
                elif category == 'service_server':
                    file.write(f'    void RequestResponseReceive(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) override;\n')
        file.write('};')

    # Generate callback's .cpp in tester project src directory path  
    g_ros2libTester_dir_src = Path(g_ros2libTester_dir_src)
    src_path = g_ros2libTester_dir_src / 'ROS2'
    tester_src_over_path = src_path / 'PureVirtualOverride'
    proj_src_pub_path = src_path / 'Topic/PublishLoop'
    proj_src_sub_path = src_path / 'Topic/Subscribe'
    proj_src_cli_path = src_path / 'Service/Client'
    proj_src_srv_path = src_path / 'Service/Server'
    ensure_directory(tester_src_over_path)
    ensure_directory(proj_src_pub_path)
    ensure_directory(proj_src_sub_path)
    ensure_directory(proj_src_cli_path)
    ensure_directory(proj_src_srv_path)

    over_file_name = 'OverridePureViurtual.cpp'
    over_file_path = tester_src_over_path / over_file_name
    with open(over_file_path, 'w') as file:
        file.write('#pragma once\n\n')
        file.write('#include "ROS2/ROS2Callback.h"\n\n')
        file.write('/* Essential Override (Pure Virtual) */\n')
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                if msg_class_name not in g_dual_msg_list and msg_class_name not in g_nonloop_dual_msg_list:
                    msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                    if category == 'loop_publish':
                        file.write(f'void ROS2Callback::SetLoopPublishTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) {{}}\n')
                    elif category == 'subscribe':
                        file.write(f'void ROS2Callback::SubscribeTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) {{}}\n')
                    elif category == 'service_client':
                        file.write(f'void ROS2Callback::RequestResponseReceive(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) {{}}\n')
                    elif category == 'service_server':
                        file.write(f'void ROS2Callback::ServiceReceive(const std::string& nameSpace,\n') 
                        file.write(f'                                 {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr req,\n')
                        file.write(f'                                 {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) {{}}\n')
        print("Generation SUCCESS (overwrite) : " + over_file_name + " in " + str(Path.cwd()) + '\\' +  str(tester_src_over_path))

    for category, msg_names in g_target_msgs_dict.items():
        for msg_class_name in msg_names:
            msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
            if category == 'publish' or category == 'loop_publish':
                file_name = f'Subscribe{msg_class_name}.cpp'
                sub_file_path = proj_src_sub_path / file_name
                if not os.path.exists(sub_file_path):
                    with open(sub_file_path, 'w') as file:
                        file.write('#include "ROS2/ROS2Callback.h"\n\n')
                        file.write('void\n')
                        file.write(f'ROS2Callback::SubscribeTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg)\n')
                        file.write('{\n')
                        write_comment_of_constants(file, msg_type, msg_class_name)
                        for field in g_target_msgs_fields_dict[msg_type][msg_class_name]['fields']: 
                            file.write(f'    {ros_field_type_to_cpp_type(field["type"])} {field["name"]} = msg->{field["name"]};\n')
                        file.write('}')
                    print("Generation SUCCESS : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_sub_path))
                else:
                    print("Generation Skip (already exist) : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_sub_path))
            elif category == 'subscribe':
                file_name = f'LoopPublish{msg_class_name}.cpp'
                pub_file_path = proj_src_pub_path / file_name
                if not os.path.exists(pub_file_path):
                    with open(pub_file_path, 'w') as file:
                        file.write('#include "ROS2/ROS2Callback.h"\n\n')
                        file.write(f'void\n') 
                        file.write(f'ROS2Callback::SetLoopPublishTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg)\n')
                        file.write('{\n')
                        write_comment_of_constants(file, msg_type, msg_class_name)
                        for field in g_target_msgs_fields_dict[msg_type][msg_class_name]['fields']: 
                            file.write(f'    msg->{(field["name"])} = {ros_field_type_to_default_value(field["type"])};\n')
                        file.write('}')
                    print("Generation SUCCESS : " + file_name + " in " + str(Path.cwd()) + '\\' + str(proj_src_pub_path))
                else:
                    print("Generation Skip (already exist) : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_pub_path))    
            elif category == 'service_client':
                file_name = f'Receive{msg_class_name}.cpp'
                srv_file_path = proj_src_srv_path / file_name
                if not os.path.exists(srv_file_path):
                    with open(srv_file_path, 'w') as file:
                        file.write('#include "ROS2/ROS2Callback.h"\n\n')
                        file.write('void\n')
                        file.write(f'ROS2Callback::ServiceReceive(const std::string& nameSpace,\n') 
                        file.write(f'                            {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr req,\n')
                        file.write(f'                            {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp)\n')
                        file.write('{\n')
                        write_comment_of_constants(file, msg_type, msg_class_name)
                        for field in g_target_msgs_fields_dict[msg_type][msg_class_name]['fields']: 
                            file.write(f'    {ros_field_type_to_cpp_type(field["type"])} {field["name"]} = req->{field["name"]};\n')
                        for rsp_field in g_target_msgs_fields_dict[msg_type][msg_class_name]['responseFields']: 
                            file.write(f'    rsp->{rsp_field["name"]} = {ros_field_type_to_default_value(rsp_field["type"])};\n')
                        file.write('}')
                    print("Generation SUCCESS : " + file_name + " in " + str(Path.cwd()) + '\\' + str(proj_src_srv_path))
                else:
                    print("Generation Skip (already exist) : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_srv_path))   
            elif category == 'service_server':
                file_name = f'ReceiveRsp{msg_class_name}.cpp'
                cli_file_path = proj_src_cli_path / file_name
                if not os.path.exists(cli_file_path):
                    with open(cli_file_path, 'w') as file:
                        file.write('#include "ROS2/ROS2Callback.h"\n\n')
                        file.write('void\n')
                        file.write(f'ROS2Callback::RequestResponseReceive(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp)\n')
                        file.write('{\n')
                        write_comment_of_constants(file, msg_type, msg_class_name)
                        for rsp_field in g_target_msgs_fields_dict[msg_type][msg_class_name]['responseFields']: 
                            file.write(f'    {ros_field_type_to_cpp_type(rsp_field["type"])} {rsp_field["name"]} = rsp->{rsp_field["name"]};\n')
                        file.write('}')
                    print("Generation SUCCESS : " + file_name + " in " + str(Path.cwd()) + '\\' + str(proj_src_cli_path))
                else:
                    print("Generation Skip (already exist) : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_cli_path))  

# Function to create .h, .cpp file in application project
def generate_files_in_application():
    global g_pkg_name, g_proj_include_path, g_proj_src_path, g_target_msgs
    global g_target_msgs_dict, g_target_msgs_fields_dict, g_dual_msg_list

    # Generate ROS2Callback.h in application project header directory path  
    g_proj_include_path = Path(g_proj_include_path)
    include_path = g_proj_include_path / 'ROS2'
    callback_file_name = 'ROS2Callback.h'
    include_file_path = include_path / callback_file_name
    ensure_directory(include_path)

    extraPrintStr = ""
    if os.path.exists(include_file_path):
        extraPrintStr = "(overwrite) "
    with open(include_file_path, 'w') as file:
        file.write('#pragma once\n\n')
        file.write('#include "ros2lib/interface/IROS2Callback.h"\n\n')
        file.write('class ROS2Callback : public IROS2Callback\n{\n')
        # Write virtual functions override
        for category, msg_names in g_target_msgs_dict.items():
            for msg_class_name in msg_names:
                msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
                if category == 'loop_publish':
                    file.write(f'    void SetLoopPublishTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) override;\n')
                elif category == 'subscribe':
                    file.write(f'    void SubscribeTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg) override;\n')
                elif category == 'service_client':
                    file.write(f'    void RequestResponseReceive(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) override;\n')
                elif category == 'service_server':
                    file.write(f'    void ServiceReceive(const std::string& nameSpace,\n')
                    file.write(f'                       {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr req,\n')
                    file.write(f'                       {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp) override;\n')
        file.write('};')
    print("Generation SUCCESS " + extraPrintStr + ": " + callback_file_name + " in " + str(Path.cwd()) + '\\' + str(include_path))

    # Generate callback's .cpp in application project src directory path  
    g_proj_src_path = Path(g_proj_src_path)
    src_path = g_proj_src_path / 'ROS2'
    proj_src_pub_path = src_path / 'Topic/PublishLoop'
    proj_src_sub_path = src_path / 'Topic/Subscribe'
    proj_src_cli_path = src_path / 'Service/Client'
    proj_src_srv_path = src_path / 'Service/Server'
    ensure_directory(proj_src_pub_path)
    ensure_directory(proj_src_sub_path)
    ensure_directory(proj_src_cli_path)
    ensure_directory(proj_src_srv_path)

    for category, msg_names in g_target_msgs_dict.items():
        for msg_class_name in msg_names:
            msg_type = 'msg' if category != 'service_server' and category != 'service_client' else 'srv'
            if category == 'loop_publish':
                file_name = f'LoopPublish{msg_class_name}.cpp'
                pub_file_path = proj_src_pub_path / file_name
                if not os.path.exists(pub_file_path):
                    with open(pub_file_path, 'w') as file:
                        file.write('#include "ROS2/ROS2Callback.h"\n\n')
                        file.write(f'void\n') 
                        file.write(f'ROS2Callback::SetLoopPublishTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg)\n')
                        file.write('{\n')
                        write_comment_of_constants(file, msg_type, msg_class_name)
                        for field in g_target_msgs_fields_dict[msg_type][msg_class_name]['fields']: 
                            file.write(f'    msg->{(field["name"])} = {ros_field_type_to_default_value(field["type"])};\n')
                        file.write('}')
                    print("Generation SUCCESS : " + file_name + " in " + str(Path.cwd()) + '\\' + str(proj_src_pub_path))
                else:
                    print("Generation Skip (already exist) : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_pub_path))    
            elif category == 'subscribe':
                file_name = f'Subscribe{msg_class_name}.cpp'
                sub_file_path = proj_src_sub_path / file_name
                if not os.path.exists(sub_file_path):
                    with open(sub_file_path, 'w') as file:
                        file.write('#include "ROS2/ROS2Callback.h"\n\n')
                        file.write('void\n')
                        file.write(f'ROS2Callback::SubscribeTopic(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::SharedPtr msg)\n')
                        file.write('{\n')
                        write_comment_of_constants(file, msg_type, msg_class_name)
                        for field in g_target_msgs_fields_dict[msg_type][msg_class_name]['fields']: 
                            file.write(f'    {ros_field_type_to_cpp_type(field["type"])} {field["name"]} = msg->{field["name"]};\n')
                        file.write('}')
                    print("Generation SUCCESS : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_sub_path))
                else:
                    print("Generation Skip (already exist) : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_sub_path))      
            elif category == 'service_client':
                file_name = f'ReceiveRsp{msg_class_name}.cpp'
                cli_file_path = proj_src_cli_path / file_name
                if not os.path.exists(cli_file_path):
                    with open(cli_file_path, 'w') as file:
                        file.write('#include "ROS2/ROS2Callback.h"\n\n')
                        file.write('void\n')
                        file.write(f'ROS2Callback::RequestResponseReceive(const std::string& nameSpace, {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp)\n')
                        file.write('{\n')
                        write_comment_of_constants(file, msg_type, msg_class_name)
                        for rsp_field in g_target_msgs_fields_dict[msg_type][msg_class_name]['responseFields']: 
                            file.write(f'    {ros_field_type_to_cpp_type(rsp_field["type"])} {rsp_field["name"]} = rsp->{rsp_field["name"]};\n')
                        file.write('}')
                    print("Generation SUCCESS : " + file_name + " in " + str(Path.cwd()) + '\\' + str(proj_src_cli_path))
                else:
                    print("Generation Skip (already exist) : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_cli_path))
            elif category == 'service_server':
                file_name = f'Receive{msg_class_name}.cpp'
                srv_file_path = proj_src_srv_path / file_name
                if not os.path.exists(srv_file_path):
                    with open(srv_file_path, 'w') as file:
                        file.write('#include "ROS2/ROS2Callback.h"\n\n')
                        file.write('void\n')
                        file.write(f'ROS2Callback::ServiceReceive(const std::string& nameSpace,\n') 
                        file.write(f'                            {g_pkg_name}::{msg_type}::{msg_class_name}::Request::SharedPtr req,\n')
                        file.write(f'                            {g_pkg_name}::{msg_type}::{msg_class_name}::Response::SharedPtr rsp)\n')
                        file.write('{\n')
                        write_comment_of_constants(file, msg_type, msg_class_name)
                        for field in g_target_msgs_fields_dict[msg_type][msg_class_name]['fields']: 
                            file.write(f'    {ros_field_type_to_cpp_type(field["type"])} {field["name"]} = req->{field["name"]};\n')
                        for rsp_field in g_target_msgs_fields_dict[msg_type][msg_class_name]['responseFields']: 
                            file.write(f'    rsp->{rsp_field["name"]} = {ros_field_type_to_default_value(rsp_field["type"])};\n')
                        file.write('}')
                    print("Generation SUCCESS : " + file_name + " in " + str(Path.cwd()) + '\\' + str(proj_src_srv_path))
                else:
                    print("Generation Skip (already exist) : " + file_name + " in " + str(Path.cwd()) + '\\' +  str(proj_src_srv_path))   

def main():
    global g_proj_include_path, g_proj_src_path
    global g_ros2libTester_dir_include, g_ros2libTester_dir_src

    init_config()

    print("\n------------------------------------------ Generate code into roslib ------------------------------------------")
    generate_MessageInclude_in_ros2lib()
    generate_IROS2Callback_in_ros2lib()
    generate_ROSMsgHandler_in_ros2lib()
    generate_ROS2CommManagerExtensions_in_ros2lib()
    print("\n------------------------------------------ Generate code into roslibTester ------------------------------------------")
    generate_files_in_tester()
    print("\n------------------------------------------ Generate code into application ------------------------------------------")
    generate_files_in_application()

    # TODO : ue editor restart
    # TODO : Sensor, geometry gen
    # TODO : sln bat gen
    # TODO : clean up tester CmakeLists.txt
    # TODO : manual
    # TODO : CMakeLists includePath, lib to build.cs
    # TODO : linux

    print("Code generation SUCCESS")

if __name__ == "__main__":
    main()