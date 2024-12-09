@echo off

echo "Generation of CMakeLists.txt in current directory : Start executing GenCmakeLists.py ..."
python "%~dp0GenCmakeLists.py"

echo "Generation of C++ source code in ros2lib & applicaiton : Start executing GenROS2CustomPkgInterface.py ..."
python "%~dp0GenROS2CustomPkgInterface.py"

pause