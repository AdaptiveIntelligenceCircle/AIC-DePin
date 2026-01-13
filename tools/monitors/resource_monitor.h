#pragma once 

#include "monitor.h"
using namespace std; 

class ResourceMonitor : public Monitor
{
    public: 
    void sample()override ; 
}; 