#pragma once 
#include <string>

#include "command_result.h"
#include "command_context.h"

#include <vector> 
using namespace std; 

namespace aic :: cli
{
    class Command
    {
    public: 
    virtual string name() const = 0; 
    virtual string description() const = 0; 

    virtual int execute(const vector<string>&args) = 0; 
    virtual ~Command() = default; 

    virtual CommandResult execute(
        const CommandContext &ctx
    ); 
    };  
}