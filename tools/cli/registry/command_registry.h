#pragma once 
#include <unordered_map>

#include <memory> 
#include "../command/command.h"

namespace aic :: cli
{
    class CommandRegistry
    {
        public:
        void registerCommand(shared_ptr<Command> cmd);
        shared_ptr<Command> resolve(const string &name) const; 

        private: 
        unordered_map<string, shared_ptr<Command>> commands_;
    }; 
}