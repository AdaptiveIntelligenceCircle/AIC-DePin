#pragma once 
#include <string> 
using namespace std; 

enum class MessageType
{
    DISCOVERY, 
    HEARTBEAT, 
    TASK, 
    RESULT, 
    SYNC, 
    CONTROL
}; 

struct Message
{
    MessageType type; 
    string payload; 
}; 