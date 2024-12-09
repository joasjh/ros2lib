#include "ros2lib/ROS2Communication/ROSMsgHandler.h"

class SubscribeNode : public rclcpp::Node
{
public:
    SubscribeNode(const std::string & node_name);
    ~SubscribeNode();

public:
    template<typename T> void makeSubscriber(const std::string& nameSpace);
    template<typename T> void destroySubscriber(const std::string& nameSpace);

    template<typename T> void registerCallback(std::function<void(const std::string& nameSpace, typename T::SharedPtr)> callback);//std::function<void(T)> callback);
    template<typename T> void unRegisterCallback();
    
private:
   template<typename T> void InvokeCallback(const std::string& nameSpace, typename T::SharedPtr msg);

private:
    rclcpp::QoS m_qosProfile;
    std::map<std::string, rclcpp::SubscriptionBase::SharedPtr> m_subscriberMap;

    std::map<std::string, std::any> m_callbacks;
};

template<typename T> void
SubscribeNode::makeSubscriber(const std::string& nameSpace)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);
    if (!m_subscriberMap.count(interfaceName)) {
        std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
        if(m_callbacks.count(typeName)) {
            m_subscriberMap[interfaceName] = this->create_subscription<T>(interfaceName, m_qosProfile,
                [this, nameSpace](typename T::SharedPtr msg) {
                    this->InvokeCallback<T>(nameSpace, msg);
                }
                // std::bind(&SubscribeNode::InvokeCallback<T>, this, nameSpace, std::placeholders::_1)
            );
        } else {
            ROSMsgHandler::GetInstance()->printLogMessage("Subscriber make FAIL (No Callback register) for msg class : " + typeName);
        }
    } else {
        ROSMsgHandler::GetInstance()->printLogMessage("Subscriber make FAIL (Already exists) : " + interfaceName);
    }
}

template<typename T> void
SubscribeNode::destroySubscriber(const std::string& nameSpace)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);
    if (!m_subscriberMap.count(interfaceName)) {
        m_subscriberMap[interfaceName].reset();
        m_subscriberMap.erase(interfaceName);
    }
}

template<typename T> void
SubscribeNode::registerCallback(std::function<void(const std::string& nameSpace, typename T::SharedPtr)> callback)
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
   
    if (!m_callbacks.count(typeName)) {
        m_callbacks[typeName] = callback;
    } 
}

template<typename T> void
SubscribeNode::unRegisterCallback()
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
    if (m_callbacks.count(typeName)) {
        m_callbacks[typeName] = nullptr;
        m_callbacks.erase(typeName);
    }
}

template <typename T> void
SubscribeNode::InvokeCallback(const std::string& nameSpace, typename T::SharedPtr msg)
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();

    auto callback = std::any_cast<std::function<void(const std::string& nameSpace, typename T::SharedPtr)>>(m_callbacks[typeName]);
    // callback(nameSpace, std::const_pointer_cast<T>(msg));

    // TODO : Replace
    callback(nameSpace, msg);
}