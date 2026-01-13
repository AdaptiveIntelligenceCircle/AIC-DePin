#pragma once 
#include <string>

#include <vector> 
using namespace std; 

class Command
{
    public: 
    virtual string name() const = 0; 
    virtual string description() const = 0; 
    virtual int execute(const vector<string>&args) = 0; 
    virtual ~Command() = default; 
};  