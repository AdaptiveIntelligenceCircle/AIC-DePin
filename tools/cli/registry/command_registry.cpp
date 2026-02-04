#include "command_registry.h"
using namespace std; 

namespace aic :: cli
{
    void CommandRegistry :: registerCommand(shared_ptr<Command> cmd)
    {
        if (!cmd) return;
        commands_[cmd -> name()] = move(cmd); 
    }

    shared_ptr<Command> 
    CommandRegistry :: resolve(const string &name) const 
    {
        auto it = commands_.find(name); 
        if (it == commands_.end()) return nullptr; 
        return it -> second; 
    }
} // namespace aic :: cli 