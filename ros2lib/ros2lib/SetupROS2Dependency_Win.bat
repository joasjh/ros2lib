@echo off

PowerShell -Command "Start-Process PowerShell -ArgumentList '-NoProfile -ExecutionPolicy Bypass -File \"%~dp0SetupROS2Dependency_Win.ps1\"' -Verb RunAs"

exit /b