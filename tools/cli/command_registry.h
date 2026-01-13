#pragma once 
#include <unordered_map>

#include <string> 
#include "command.h"

class CommandRegistry
{
    public: 
    void register_command(Command*); 
    Command *find(const string &name); 

    private: 
    unordered_map<string, Command*> commands; 
}; 