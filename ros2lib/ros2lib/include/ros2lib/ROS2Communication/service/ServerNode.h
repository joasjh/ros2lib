#include "ros2lib/ROS2Communication/ROSMsgHandler.h"

class ServerNode : public rclcpp::Node
{
public:
    ServerNode(const std::string & node_name);
    ~ServerNode();

public:
    template<typename T> void makeServer(const std::string& nameSpace);
    template<typename T> void destroyServer(const std::string& nameSpace);

    template<typename T> void registerCallback(std::function<void(const std::string& nameSpace, 
                                                                  typename T::Request::SharedPtr,
                                                                  typename T::Response::SharedPtr)> callback);
    template<typename T> void unRegisterCallback();
    
private:
   template<typename T> void InvokeCallback(const std::string& nameSpace,
                                            typename T::Request::SharedPtr req,
                                            typename T::Response::SharedPtr rsp);

private:
    std::map<std::string, rclcpp::ServiceBase::SharedPtr> m_serverMap;

    std::map<std::string, std::any> m_callbacks;
};

template<typename T> void
ServerNode::makeServer(const std::string& nameSpace)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);
    if (!m_serverMap.count(interfaceName)) {
        std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
        if(m_callbacks.count(typeName)) {
            m_serverMap[interfaceName] = this->create_service<T>(interfaceName,
                [this, nameSpace](typename T::Request::SharedPtr req, typename T::Response::SharedPtr rsp) {
                    this->InvokeCallback<T>(nameSpace, req, rsp);
                }
                //std::bind(&ServerNode::InvokeCallback<T>, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)
            );
        } else {
            ROSMsgHandler::GetInstance()->printLogMessage("Server make FAIL (No Callback register) for srv : " + typeName);
        }
    } else {
        ROSMsgHandler::GetInstance()->printLogMessage("Server make FAIL (Already exists) : " + interfaceName);
    }
}

template<typename T> void
ServerNode::destroyServer(const std::string& nameSpace)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);
    if (m_serverMap.count(interfaceName)) {
        m_serverMap.erase(interfaceName);
    }
}

template<typename T> void
ServerNode::registerCallback(std::function<void(const std::string& nameSpace, 
                                                typename T::Request::SharedPtr,
                                                typename T::Response::SharedPtr)> callback)
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
    if (!m_callbacks.count(typeName)) {
        m_callbacks[typeName] = callback;
    } 
}

template<typename T> void
ServerNode::unRegisterCallback()
{
    m_callbacks.erase(ROSMsgHandler::GetInstance()->getClassTypeName<T>());
}

template<typename T> void
ServerNode::InvokeCallback(const std::string& nameSpace, 
                           typename T::Request::SharedPtr req,
                           typename T::Response::SharedPtr rsp)
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();

    auto callback = std::any_cast<std::function<void(const std::string& nameSpace,
                                                     typename T::Request::SharedPtr,
                                                     typename T::Response::SharedPtr)>>(m_callbacks[typeName]);
    callback(nameSpace, req, rsp);
}