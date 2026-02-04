#pragma once
#include "../../command/command.h"
using namespace std; 

namespace aic::cli 
{

class ReplayCommand : public Command 
{
public:
    string name() const override 
    { 
        return "replay"; 
    }

    string description() const override 
    {
        return "Replay recorded system events";
    }

    CommandResult execute
    (
        const CommandContext&
    ) override 
    {
        return CommandResult::ok
        (
            "Replay executed (simulation mode)"
        );
    }
};

} // namespace aic::cli
