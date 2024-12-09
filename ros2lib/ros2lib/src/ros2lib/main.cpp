/*
    For Executable build test.
*/
#pragma warning(push)
#pragma warning(disable: 4700) // non-initialized pointer var warning skip

#include <iostream>

#include "ros2lib/ROS2Communication/ROS2CommManager.h"

int
main(int argc, char **argv)
{
    IROS2Callback* callback;

    ROS2CommManager::GetInstance()->init(callback);
    ROS2CommManager::GetInstance()->shutdown();
}

#pragma warning(pop)