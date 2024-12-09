setlocal enabledelayedexpansion
@echo off

set "VSWHERE_PATH="
for %%i in (
    "%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
    "%ProgramFiles%\Microsoft Visual Studio\Installer\vswhere.exe"
) do (
    echo Installer Found : %%i
    if exist "%%i" (
        set "VSWHERE_PATH=%%i"
    ) 
)

if not "!VSWHERE_PATH!"=="" (
    echo Visual Studio installer path : !VSWHERE_PATH!
) else (
    echo Cannot find Visual Studio installer path. It looks like {Drive}:\ProgramFiles^(x86^)\Microsoft Visual Studio\Installer\vswhere.exe
    pause
)

set "VS_2019_INSTALL_PATH="
for /f "tokens=*" %%i in ('%VSWHERE_PATH% -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath') do (
    set VS_INSTALL_PATH=%%i
    echo Installation Path Found : !VS_INSTALL_PATH!
    if "!VS_INSTALL_PATH:2019=!" neq "!VS_INSTALL_PATH!" (
        set "VS_2019_INSTALL_PATH=!VS_INSTALL_PATH!"
    )
)

set "VCVARSALL_PATH="
if not "!VS_2019_INSTALL_PATH!"=="" (
    set "VCVARSALL_PATH=%VS_2019_INSTALL_PATH%\VC\Auxiliary\Build\vcvarsall.bat"
    echo Visual Studio 2019 prompt path : !VCVARSALL_PATH!
) else (
    echo Cannot find Visual Studio 2019 installation path. It looks like {Drive}:\ProgramFiles^(x86^)\Microsoft Visual Studio\2019\{Edition^(Community, Professional, Enterprise^)}\VC\Auxiliary\Build\vcvarsall.bat
    pause
)

call "%VCVARSALL_PATH%" x64

set "folders=build install log"
for %%f in (%folders%) do (
    set "TARGET_FOLDER=%cd%\%%f"
    if exist "!TARGET_FOLDER!" (
        rd /s /q "!TARGET_FOLDER!"
        echo !TARGET_FOLDER! has been deleted.
    ) else (
        echo !TARGET_FOLDER! does not exist, skip folder delete.
    )
)

call "%~dp0..\ref\ros2-windows\setup.bat"
colcon build

pause