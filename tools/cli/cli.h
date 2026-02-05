#pragma once
#include "registry/command_registry.h"
#include "registry/command_registry.h"
using namespace std;

namespace aic ::cli
{
    class CLIApp
    {
    public:
        CLIApp() = default;
        ~CLIApp() = default; 
        
        void run(int argc, char **argv);
        // void execute_line(const string &line);

    private:
        CommandRegistry registry_;
        void RegisterCommand(); 
    };
}