#include "ros2lib/ROS2Communication/ROSMsgHandler.h"

class PublishNode : public rclcpp::Node
{
public:
    PublishNode(const std::string & node_name);
    ~PublishNode();

public:
    template<typename T> void makePublisher(const std::string& nameSpace);
    template<typename T> void makeLoopPublisher(const std::string& nameSpace, std::chrono::milliseconds period);
    template<typename T> void destroyPublisher(const std::string& nameSpace);

    template<typename T> void publish(const std::string& nameSpace, const T& msg);

    template<typename T> void registerLoopCallback(std::function<void(const std::string&, typename T::SharedPtr)> callback);
    template<typename T> void unRegisterLoopCallback();

public:
    void destroyEntirePublisher();

private:
    template<typename T> void InvokeLoopCallback(const std::string& nameSpace, typename T::SharedPtr msg);

private:
    rclcpp::QoS m_qosProfile;
    std::map<std::string, rclcpp::PublisherBase::SharedPtr> m_publisherMap;
    std::map<rclcpp::PublisherBase::SharedPtr, std::string> m_namespaceMap;
    std::map<std::chrono::milliseconds, rclcpp::TimerBase::SharedPtr> m_timerMap;
    std::multimap<std::chrono::milliseconds, rclcpp::PublisherBase::SharedPtr> m_loopPublisherMultiMap;

    std::map<std::string, std::any> m_loopCallbacks;
};

template<typename T> void
PublishNode::makePublisher(const std::string& nameSpace)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);

    if (!m_publisherMap.count(interfaceName)) {
        m_publisherMap[interfaceName] = this->create_publisher<T>(interfaceName, m_qosProfile);
    } else {
        ROSMsgHandler::GetInstance()->printLogMessage("Publihser make FAIL (Already exists) : " + interfaceName);
    }
}

template<typename T> void
PublishNode::makeLoopPublisher(const std::string& nameSpace, std::chrono::milliseconds period)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);

    if (!m_publisherMap.count(interfaceName)) {
        std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
        if(m_loopCallbacks.count(typeName)) {

            // Make publisher
            m_publisherMap[interfaceName] = this->create_publisher<T>(interfaceName, m_qosProfile);
            m_namespaceMap[m_publisherMap[interfaceName]] = nameSpace;
            m_loopPublisherMultiMap.insert(
                std::make_pair(period, m_publisherMap[interfaceName])
            );

            // Activate timer for input period if not exist for this period
            if(!m_timerMap.count(period)) {         
                m_timerMap[period] = this->create_wall_timer(
                    period,
                    [this, typeName, period]() {
                        auto iterRange = m_loopPublisherMultiMap.equal_range(period);
                        for (auto it = iterRange.first; it != iterRange.second; ++it) {
                            try {
                                std::string it_nameSpace = m_namespaceMap[it->second];
                                T::SharedPtr msg = std::make_shared<T>();
                                InvokeLoopCallback<T>(it_nameSpace, msg);                                    

                                typename rclcpp::Publisher<T>::SharedPtr publisher
                                    = std::dynamic_pointer_cast<rclcpp::Publisher<T>>(it->second);

                                // auto weak_publisher = std::weak_ptr<rclcpp::Publisher<T>>(std::dynamic_pointer_cast<rclcpp::Publisher<T>>(it->second));
                                // auto publisher = weak_publisher.lock();
                                if (publisher) {
                                    publisher->publish(*msg);
                                } else {
                                    ROSMsgHandler::GetInstance()->printLogMessage("Publisher type mismatch : " + it_nameSpace + "/" + typeName);
                                }
                            } catch (const std::bad_any_cast& e) {
                                ROSMsgHandler::GetInstance()->printLogMessage("Failed to cast callback func : " + std::string(e.what()));
                            }
                        }
                    }
                );
                ROSMsgHandler::GetInstance()->printLogMessage("Publish Timer with " + std::to_string(period.count()) + "ms run start");
            }
        }
        else { 
            ROSMsgHandler::GetInstance()->printLogMessage("Loop Publihser make FAIL (No loopCallback register) for msg : " + interfaceName);
        }
    } else {
        ROSMsgHandler::GetInstance()->printLogMessage("Loop Publihser make FAIL (Already exists) : " + interfaceName);
    }
}

template<typename T> void
PublishNode::destroyPublisher(const std::string& nameSpace)
{
    ROSMsgHandler::GetInstance()->printLogMessage("_1"); 
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);
    ROSMsgHandler::GetInstance()->printLogMessage("_2"); 
    auto pubIter = m_publisherMap.find(interfaceName);
    ROSMsgHandler::GetInstance()->printLogMessage("_3"); 
    if (pubIter != m_publisherMap.end()) {
        ROSMsgHandler::GetInstance()->printLogMessage("_4"); 
        auto publisherBase = pubIter->second;

        // No loop pub of its period, no timer of this period.
        for(auto it = m_loopPublisherMultiMap.begin(); it != m_loopPublisherMultiMap.end();) {
            ROSMsgHandler::GetInstance()->printLogMessage("_5"); 
            if (it->second == publisherBase) {
                ROSMsgHandler::GetInstance()->printLogMessage("_51");
                if(m_loopPublisherMultiMap.count(it->first) == 1) {
                    ROSMsgHandler::GetInstance()->printLogMessage("_52"); 
                    m_timerMap[it->first]->cancel();
                    ROSMsgHandler::GetInstance()->printLogMessage("_53"); 
                    m_timerMap.erase(it->first);
                } else {
                    m_timerMap[it->first]->cancel();
                    it = m_loopPublisherMultiMap.erase(it);
                    m_timerMap[it->first]->reset();
                }
                ROSMsgHandler::GetInstance()->printLogMessage("_54"); 
                // it = m_loopPublisherMultiMap.erase(it);
            } else {
                ++it;
            }
        }
        ROSMsgHandler::GetInstance()->printLogMessage("_6"); 
        m_namespaceMap.erase(publisherBase);
        ROSMsgHandler::GetInstance()->printLogMessage("_7"); 
        m_publisherMap.erase(pubIter);
        ROSMsgHandler::GetInstance()->printLogMessage("_8"); 
    }
}

template<typename T> void
PublishNode::publish(const std::string& nameSpace, const T& msg)
{
    std::string interfaceName = ROSMsgHandler::GetInstance()->getROSMsgInterfaceName<T>(nameSpace);

    if (m_publisherMap.count(interfaceName)) {
        typename rclcpp::Publisher<T>::SharedPtr publisher
            = std::dynamic_pointer_cast<rclcpp::Publisher<T>>(m_publisherMap[interfaceName]);
        if (publisher) {
            publisher->publish(msg);
        } else {
            ROSMsgHandler::GetInstance()->printLogMessage("Publisher type mismatch : " + interfaceName);
        }
    } else {
        ROSMsgHandler::GetInstance()->printLogMessage("No publisher found : " + interfaceName);
    }
}

template<typename T> void
PublishNode::registerLoopCallback(std::function<void(const std::string&, typename T::SharedPtr)> callback)
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
   
    if (!m_loopCallbacks.count(typeName)) {
        m_loopCallbacks[typeName] = callback;
    } 
}

template<typename T> void
PublishNode::unRegisterLoopCallback()
{
    m_loopCallbacks.erase(ROSMsgHandler::GetInstance()->getClassTypeName<T>());
}

template <typename T> void
PublishNode::InvokeLoopCallback(const std::string& nameSpace, typename T::SharedPtr msg)
{
    std::string typeName = ROSMsgHandler::GetInstance()->getClassTypeName<T>();
    auto callback = std::any_cast<std::function<void(const std::string&, typename T::SharedPtr)>>(m_loopCallbacks[typeName]);
    callback(nameSpace, msg);
}