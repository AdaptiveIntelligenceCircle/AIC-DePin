#pragma once 

class BootstrapStrategy
{
    public: 
    virtual void bootstrap() = 0; 
    virtual ~BootstrapStrategy() = default; 
}; 