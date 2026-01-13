#pragma once 
#include "monitor.h"
using namespace std; 

class NetworkMonitor : public Monitor
{
    public: 
    void sample() override; 
}; 