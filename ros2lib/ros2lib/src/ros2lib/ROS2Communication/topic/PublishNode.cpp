#include "ros2lib/ROS2Communication/topic/PublishNode.h"

PublishNode::PublishNode(const std::string & node_name)
    : rclcpp::Node(node_name),
    m_qosProfile(rclcpp::QoS(rclcpp::KeepLast(10)))
{
  
}

PublishNode::~PublishNode()
{

}

void
PublishNode::destroyEntirePublisher()
{

}