#pragma once 
#include "../../command/command.h"

using namespace std; 

namespace aic :: cli 
{
    class ExplainCommand : public Command 
    {
        public: 
        string name() const override 
        {
            return "explain"; 
        }

        string description() const override 
        {
            return "explain system decisions";
        }

        CommandResult execute(
            const CommandContext &ctx
        ) override 
        {
            return 
            {
                true, 
                "Explain command executed", 
                "This command exposes decision rationale"
            }; 
        }
    }; 
}