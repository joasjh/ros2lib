# 4-1. Chocolatey 
Write-Host "Chocolatey Installing..."
Set-ExecutionPolicy Bypass -Scope Process -Force
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

# 4-2. Python, colcon 
Write-Host "Python Installing..."
choco install -y python --version 3.8.3
Write-Host "PATH reload..."
& cmd /c "refreshenv"
Write-Host "colcon Installing..."
pip install -U colcon-common-extensions
Write-Host "PyYAML Installing..."
pip install PyYAML

# 4-3. Visual C++
Write-Host "Visual C++ Redistributable Installing..."
choco install -y vcredist2013 vcredist140

# 4-4. OpenSSL
Write-Host "OpenSSL Installing..."
choco install -y openssl --version 1.1.1.2100
setx /M OPENSSL_CONF "C:\Program Files\OpenSSL-Win64\bin\openssl.cfg"

# 4-5. OpenCV 
Write-Host "OpenCV Setting..."
setx /M OpenCV_DIR C:\opencv

# 4-6. CMake
Write-Host "CMake Setting..."
choco install -y cmake

# 4-7. nupkg , Python packages
Write-Host "nupkg, Python packages Installing..."
$NupkgPath = Join-Path -Path $PSScriptRoot -ChildPath "ref\nupkg"
choco install -y -s $NupkgPath asio cunit eigen tinyxml-usestl tinyxml2 bullet
python -m pip install -U pip setuptools==59.6.0
python -m pip install -U catkin_pkg cryptography empy importlib-metadata lark==1.1.1 lxml matplotlib netifaces numpy opencv-python PyQt5 pillow psutil pycairo pydot pyparsing==2.4.7 pyyaml rosdistro

# 4-8. BUFFERED_OPT (empy module) fix
pip uninstall -y empy
pip install empy==3.3.4

Write-Host "ROS Setup done."

pause