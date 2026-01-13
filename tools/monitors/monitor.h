#pragma once 

class Monitor
{
    public: 
    virtual void sample()  = 0; 
    virtual ~Monitor() = default; 
};  