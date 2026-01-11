#pragma once 
#include "../protocol/message.h"

using namespace std; 

class Router
{
    public: 
    void forward(const Message&);
}; 