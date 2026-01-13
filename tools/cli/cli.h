#pragma once
#include "command_registry.h"

using namespace std; 

class CLI
{
    public: 
    CLI(); 

    void run(); 
    void execute_line(const string &line);

    private: 
    CommandRegistry registry; 
}; 