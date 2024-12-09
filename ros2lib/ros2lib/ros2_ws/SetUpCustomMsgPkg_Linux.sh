echo "Try colcon build ..."
colcon build

echo "Add ROS Sourcing to .bashrc"
python3 AddROS2Sourcing.py
