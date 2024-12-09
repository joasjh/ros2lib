@echo off

call "%~dp0ref\ros2-windows\local_setup.bat"
call "%~dp0ros2_ws\install\local_setup.bat"

cd /d "%~dp0/build"
cmake ..
cmake --build . --config Release

pause