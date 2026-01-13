#pragma once 
#include "monitor.h"

class TrustMonitor : public Monitor
{
    public: 
    void sample() override; 
}; 