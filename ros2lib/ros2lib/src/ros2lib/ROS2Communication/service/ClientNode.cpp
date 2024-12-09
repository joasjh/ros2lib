#include "ros2lib/ROS2Communication/service/ClientNode.h"

ClientNode::ClientNode(const std::string & node_name)
    : rclcpp::Node(node_name),
    m_requestTimeOut(std::chrono::seconds(5))
{
  
}

ClientNode::~ClientNode()
{

}