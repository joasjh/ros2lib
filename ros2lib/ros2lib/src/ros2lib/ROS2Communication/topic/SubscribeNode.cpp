#include "ros2lib/ROS2Communication/topic/SubscribeNode.h"

SubscribeNode::SubscribeNode(const std::string & node_name)
    : rclcpp::Node(node_name),
    m_qosProfile(rclcpp::QoS(rclcpp::KeepLast(10)))
{
  
}

SubscribeNode::~SubscribeNode()
{

}