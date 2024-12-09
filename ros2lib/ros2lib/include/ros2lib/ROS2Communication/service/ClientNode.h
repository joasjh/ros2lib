#include "ros2lib/ROS2Communication/ROSMsgHandler.h"

class ClientNode : public rclcpp::Node
{
public:
    ClientNode(const std::string & node_name);
    ~ClientNode();

public:
    template<typename T> void makeClient(const std::string& nameSpace);
    template<typename T> void destroyClient(const std::string& nameSpace);

    template<typename T> void sendRequest(std::shared_ptr<ClientNode> nodePtr,
                                          const std::string& nameSpace, 
                                          const typename T::Request& req);

    template<typename T> void registerRspCallback(std::function<void(const std::string&, typename T::Response::SharedPtr)> callback);
    template<typename T> void unRegisterRspCallback();
    
private:
   template<typename T> void InvokeCallback(const std::string& nameSpace, typename T::Response::SharedPtr rsp);

private:
    std::map<std::string, rclcpp::ClientBase::SharedPtr> m_clientMap;
    std::chrono::seconds m_requestTimeOut;

    std::map<std::string, std::any> m_rspCallbacks;
};

template<typename T> void
ClientNode::makeClient(const std::string& nameSpace)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);
    if (!m_clientMap.count(interfaceName)) {
        m_clientMap[interfaceName] = this->create_client<T>(interfaceName);
    } else {
        ROSMsgHandler::GetInstance()->printLogMessage("Client make FAIL (Already exists) : " + interfaceName);
    }
}

template<typename T> void
ClientNode::destroyClient(const std::string& nameSpace)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);
    if (m_clientMap.count(interfaceName)) {
        m_clientMap.erase(interfaceName);
    }
}

template<typename T> void
ClientNode::sendRequest(std::shared_ptr<ClientNode> nodePtr, 
                        const std::string& nameSpace,
                        const typename T::Request& req)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);
    if (m_clientMap.count(interfaceName)) {
        typename rclcpp::Client<T>::SharedPtr client
            = std::dynamic_pointer_cast<rclcpp::Client<T>>(m_clientMap[interfaceName]);
        if (client) {
            T::Request::SharedPtr reqPtr = std::make_shared<T::Request>(req);
            auto resultFuture = client->async_send_request(reqPtr);
            auto status = rclcpp::spin_until_future_complete(std::dynamic_pointer_cast<rclcpp::Node>(nodePtr), resultFuture, m_requestTimeOut);
            if (status == rclcpp::FutureReturnCode::SUCCESS) {
                InvokeCallback<T>(nameSpace, resultFuture.get());
            } else if (status == rclcpp::FutureReturnCode::TIMEOUT) { 
                ROSMsgHandler::GetInstance()->printLogMessage("---------------------- Response timeout : " + interfaceName + " ----------------------");
            } else {
                ROSMsgHandler::GetInstance()->printLogMessage("Failed to receive response unknown reason : " + interfaceName);
            }
        } else {
            ROSMsgHandler::GetInstance()->printLogMessage("Client type mismatch : " + interfaceName);
        }    
    } else {
        ROSMsgHandler::GetInstance()->printLogMessage("No client found : " + interfaceName);
    }
}

template<typename T> void
ClientNode::registerRspCallback(std::function<void(const std::string&, typename T::Response::SharedPtr)> callback)
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
    if (!m_rspCallbacks.count(typeName)) {
        m_rspCallbacks[typeName] = callback;
    } 
}

template<typename T> void
ClientNode::unRegisterRspCallback()
{
    m_rspCallbacks.erase(ROSMsgHandler::GetInstance()->getClassTypeName<T>());
}

template <typename T> void
ClientNode::InvokeCallback(const std::string& nameSpace, typename T::Response::SharedPtr rsp)
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
    auto callback = std::any_cast<std::function<void(const std::string&, typename T::Response::SharedPtr)>>(m_rspCallbacks[typeName]);
    callback(nameSpace, rsp);
}