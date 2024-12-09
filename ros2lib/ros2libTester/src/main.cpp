#include <iostream>
#include <cstdlib>
#include <windows.h>

#include "ROS2/ROS2Callback.h"
#include "ros2lib/ROS2Communication/ROS2CommManager.h"

// #pragma GCC diagnostic ignored "-Wdeprecated-declarations"

int
main(int argc, char **argv)
{
    auto ros = ROS2CommManager::GetInstance();
    ROS2Callback callback;
    ros->initForTester(
        static_cast<IROS2Callback*>(&callback)
    );

    std::cout << "Start" << "\n";
    std::chrono::milliseconds period = std::chrono::milliseconds(1000);
    ros->createLoopPublisher<imast_msgs::msg::ReportRobotOperInfo>("UGV1", period);
    // ros->createSubscriber<imast_msgs::msg::ReportRobotOperInfo>("UGV1");

    ros->createClient<imast_msgs::srv::SendTaskPlan>("UGV1");
    imast_msgs::srv::SendTaskPlan::Request req;
    int i = 0;
    req.robot_id = "UTT" + std::to_string(i);

    ros->createServer<imast_msgs::srv::TaskEvent>("UGV1");

     while (true) {
        // 'A' 키를 누르면 RunMyCode() 함수 실행
        if (GetAsyncKeyState('A') & 0x8000) {
            i++;
            req.robot_id = "UGV" + std::to_string(i);
            ros->sendServiceRequest<imast_msgs::srv::SendTaskPlan>("UGV1", req);
            Sleep(50); // 200ms 대기 (원하는 대로 조정 가능)
        }
     }

    ros->shutdown();
} 