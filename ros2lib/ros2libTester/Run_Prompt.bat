@echo off

call "%~dp0..\ros2lib\ref\ros2-windows\setup.bat"
call "%~dp0..\ros2lib\ros2_ws\install\setup.bat"

start "" "%~dp0/build/Release/main.exe"