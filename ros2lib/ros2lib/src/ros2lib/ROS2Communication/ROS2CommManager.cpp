#include "ros2lib/ROS2Communication/ROS2CommManager.h"

#include "ros2lib/ROS2Communication/ROSMsgHandler.h"
#include "ros2lib/ROS2Communication/topic/PublishNode.h"
#include "ros2lib/ROS2Communication/topic/SubscribeNode.h"
#include "ros2lib/ROS2Communication/service/ClientNode.h"
#include "ros2lib/ROS2Communication/service/ServerNode.h"

std::shared_ptr<ROS2CommManager> ROS2CommManager::Instance = nullptr;

static void execptionHandle()
{
    if(rclcpp::ok()) {
        ROSMsgHandler::GetInstance()->printLogMessage("rclcpp shutdown call missed. force shutdown ...");
        ROS2CommManager::GetInstance()->shutdown();
    }
}

ROS2CommManager::ROS2CommManager()
{

}

ROS2CommManager::~ROS2CommManager()
{
    if(m_executor) {
        ROSMsgHandler::GetInstance()->printLogMessage("rclcpp shutdown call missed. force shutdown ...");
        shutdown();
    }
}

void
ROS2CommManager::init(IROS2Callback* callback)
{
    char* fake_argv[] = {
        _strdup("program_name"), 
        _strdup("--ros-args")
    };
    int fake_argc = (int)(sizeof(fake_argv) / sizeof(fake_argv[0])) - 1;

    try {
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp init ...");
        rclcpp::init(fake_argc, fake_argv);
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp init SUCCESS"); 

        if(!m_executor) {
            m_executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
            m_publishNode = std::make_shared<PublishNode>(NODE_NAME_PUB);
            if(!m_subscribeNode){
                m_subscribeNode = std::make_shared<SubscribeNode>(NODE_NAME_SUB);
            }
            m_clientNode = std::make_shared<ClientNode>(NODE_NAME_CLI);
            m_serverNode = std::make_shared<ServerNode>(NODE_NAME_SRV);

            ROSMsgHandler::GetInstance()->printLogMessage("ROS2 nodes generated."); 
        
            registerCallback(callback);

            m_executor->add_node(m_publishNode);
            m_executor->add_node(m_subscribeNode);
            // m_executor->add_node(m_clientNode); when send req, automatic adding
            m_executor->add_node(m_serverNode);
            ROSMsgHandler::GetInstance()->printLogMessage("ROS2 Executor manage nodes. now spin with thread.."); 

            m_thread = std::thread([this]() {
                m_executor->spin();
            });

            std::atexit(execptionHandle);
        }
    } 
    catch (const rclcpp::exceptions::RCLError &e) {
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp init failed. Please make sure runnning of setup.bash"); 
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp init failed. error : " + std::string(e.what())); 
    }
}

void
ROS2CommManager::initForTester(IROS2Callback* callback)
{
    char* fake_argv[] = {
        _strdup("program_name_t"),
        _strdup("--ros-args") 
    };
    int fake_argc = (int)(sizeof(fake_argv) / sizeof(fake_argv[0])) - 1;

    try {
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp init ...");
        rclcpp::init(fake_argc, fake_argv);
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp init SUCCESS"); 

        m_publishNode = std::make_shared<PublishNode>(NODE_NAME_T_PUB);
        m_subscribeNode = std::make_shared<SubscribeNode>(NODE_NAME_T_SUB);
        m_clientNode = std::make_shared<ClientNode>(NODE_NAME_T_CLI);
        m_serverNode = std::make_shared<ServerNode>(NODE_NAME_T_SRV);
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 nodes generated."); 
        
        registerCallbackForTester(callback);
        
        m_executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
        m_executor->add_node(m_publishNode);
        m_executor->add_node(m_subscribeNode);
        // m_executor->add_node(m_clientNode); when send req, automatic adding
        m_executor->add_node(m_serverNode);
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 Executor manage nodes. now spin with thread.."); 

        m_thread = std::thread([this]() {
            m_executor->spin();
        });

        std::atexit(execptionHandle);
    } 
    catch (const rclcpp::exceptions::RCLError &e) {
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp init failed. Please make sure runnning of setup.bash"); 
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp init failed. error : " + std::string(e.what())); 
    }
}

void
ROS2CommManager::shutdown()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lock(m_mtx);
        m_executor->cancel();
        unRegisterCallback();
    }

    if (m_thread.joinable()) {
        m_thread.join();
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));

    {
        std::lock_guard<std::mutex> lock(m_mtx);
        ROSMsgHandler::GetInstance()->printLogMessage("1"); 
        m_executor->remove_node(m_publishNode);
        ROSMsgHandler::GetInstance()->printLogMessage("2"); 
        m_executor->remove_node(m_subscribeNode);
        // m_executor->remove_node(m_clientNode);
        m_executor->remove_node(m_serverNode);

        
        // ROSMsgHandler::GetInstance()->printLogMessage("2.5"); 
        // m_clientNode.reset();
        // ROSMsgHandler::GetInstance()->printLogMessage("3"); 
        // m_subscribeNode.reset();
        // ROSMsgHandler::GetInstance()->printLogMessage("4"); 
        // m_publishNode.reset();
        // m_serverNode.reset();

        ROSMsgHandler::GetInstance()->printLogMessage("5"); 

        m_executor.reset();
        ROSMsgHandler::GetInstance()->printLogMessage("6"); 
        rclcpp::shutdown();
        ROSMsgHandler::GetInstance()->printLogMessage("ROS2 rclcpp shutdown."); 
    }
}