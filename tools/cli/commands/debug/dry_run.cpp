#pragma once 

#include <iostream>
using namespace std; 

#include "../../command/command.h"

namespace aic :: cli 
{
    class DryRunCommand : public Command 
    {
        public: 
        string name() const override 
        {
            return "dry-run"; 
        }

        string description() const override 
        {
            return "simulate command without execution"; 
        }

        CommandResult execute(
            const CommandContext&
        ) override 
        {
            return CommandResult :: ok(
                "Dry run completed: No state changed."
            );
        }
    }; 
} // namespace aic :: cli