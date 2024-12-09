#include "ros2lib/ROS2Communication/ROSMsgHandler.h"

#ifdef _WIN32 
    #include <windows.h> // OutputDebugStringA
#endif

std::shared_ptr<ROSMsgHandler> ROSMsgHandler::Instance = nullptr;

ROSMsgHandler::ROSMsgHandler()
{

}

ROSMsgHandler::~ROSMsgHandler()
{

}

// Can be found in visual studio 'output'
void
ROSMsgHandler::printLogMessage(const std::string& message)
{
    #ifdef _WIN32
        std::string indicator = "[ Log from ros2lib ] ";
        std::string msg_to_print =  indicator + message + "\n";
        OutputDebugStringA(msg_to_print.c_str()); 
    #else 
        std::cerr << message << std::endl;
    #endif
}

std::string
ROSMsgHandler::getNamespaceFromInterfaceName(const std::string& interfaceName)
{
   size_t pos = interfaceName.find('/');

   if (pos != std::string::npos) { 
       return interfaceName.substr(0, pos);
   } else {
       return "";
   }
}