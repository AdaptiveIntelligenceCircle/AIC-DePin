#pragma once 
#include "message.h"

using namespace std; 

class ProtocolHandler
{
    public: 
    bool validate(const Message&); 
    void dispatch(const Message&); 
}; 