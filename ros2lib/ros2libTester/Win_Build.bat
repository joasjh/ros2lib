@echo off

call "%~dp0..\ros2lib\ref\ros2-windows\setup.bat"
call "%~dp0..\ros2lib\ros2_ws\install\setup.bat"

cd /d "%~dp0/build"
cmake ..
cmake --build . --config Release

pause