/*
    Including this header is satisfying all you need to access.
*/

#include <thread>
#include <mutex>
#include <chrono>

#include "ros2lib/interface/IROS2Callback.h"

// Forward declaration to avoid dependency & additional header inclusion
class PublishNode;
class SubscribeNode;
class ClientNode;
class ServerNode;
namespace rclcpp { namespace executors { class MultiThreadedExecutor; } }

class ROS2CommManager
{
private:
    static std::shared_ptr<ROS2CommManager> Instance;

protected:
    ROS2CommManager();
    ~ROS2CommManager();
    ROS2CommManager(const ROS2CommManager&) = delete;
    ROS2CommManager operator = (const ROS2CommManager&) = delete;

public:
    static std::shared_ptr<ROS2CommManager> GetInstance() {
        if (!Instance) {
            Instance = std::shared_ptr<ROS2CommManager>(new ROS2CommManager, [](ROS2CommManager* p) {
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
    void init(IROS2Callback* callback);
    void initForTester(IROS2Callback* callback);
    void shutdown();

public:
    template<typename T> void createPublisher(const std::string& nameSpace);
    template<typename T> void createLoopPublisher(const std::string& nameSpace, std::chrono::milliseconds period);
    template<typename T> void createSubscriber(const std::string& nameSpace);
    template<typename T> void createClient(const std::string& nameSpace);
    template<typename T> void createServer(const std::string& nameSpace);
    template<typename T> void destroyPublisher(const std::string& nameSpace);
    template<typename T> void destroySubscriber(const std::string& nameSpace);
    template<typename T> void destroyClient(const std::string& nameSpace);
    template<typename T> void destroyServer(const std::string& nameSpace);

    template<typename T> void publishTopic(const std::string& nameSpace, const T& msg);
    template<typename T> void sendServiceRequest(const std::string& nameSpace, const typename T::Request& req);

private:
    void registerCallback(IROS2Callback* callback);
    void unRegisterCallback();
    void registerCallbackForTester(IROS2Callback* callback);

private:
    std::shared_ptr<rclcpp::executors::MultiThreadedExecutor> m_executor;
    std::thread m_thread;
    std::mutex m_mtx;

    std::shared_ptr<PublishNode> m_publishNode;
    std::shared_ptr<SubscribeNode> m_subscribeNode;
    std::shared_ptr<ClientNode> m_clientNode;
    std::shared_ptr<ServerNode> m_serverNode;
};