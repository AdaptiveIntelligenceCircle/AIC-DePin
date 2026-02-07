#pragma once 
#include <string> 

using namespace std; 

class Scenario
{
    public: 
    virtual string name() const = 0; 
    virtual void setup() = 0; 
    virtual void step() = 0; 
    virtual ~Scenario() = default; 
}; 