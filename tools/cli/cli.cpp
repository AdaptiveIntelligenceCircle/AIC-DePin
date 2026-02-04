#include "cli.h"
using namespace std;

#include <iostream>
#include <sstream>

#include "commands/debug/explain.cpp"
#include "commands/debug/dry_run.cpp"
#include "commands/debug/replay.cpp"

namespace aic :: cli 
{
    void CLIApp :: RegisterCommand()
    {
        registry_.registerCommand(
            make_shared<ExplainCommand>()
        );
        registry_.registerCommand(
            make_shared<DryRunCommand>()
        );
        registry_.registerCommand(
            make_shared<ReplayCommand>()
        );
    }

    void CLIApp :: run(int argc, char **argv)
    {
        RegisterCommand(); 

        if (argc < 2)
        {
            cout <<"No command provided\n"; 
            return ; 
        }

        auto cmd = registry_.resolve(argv[1]); 
        
        if (!cmd) 
        {
            cout << "Unknown command\n";
            return ; 
        }

        CommandContext ctx; 
        ctx.caller_id = "local";
        ctx.trust_score = 0.5; 

        auto result = cmd -> execute(ctx); 
        cout << result.message << "\n"; 
    }
} // namespace aic :: cli

// using namespace aic :: cli; 

// CLI :: CLI()
// {
//     // commands registered here.
// }

// void CLI :: run()
// {
//     string line; 
//     while (getline(cin, line))
//     {
//         execute_line(line); 
//     }
// }

// void CLI :: execute_line(const string &line)
// {
//     istringstream iss(line); 
//     string cmd; 
//     iss >> cmd; 

//     vector<string> args; 
//     string arg; 
//     while (iss >> arg) args.push_back(arg); 

//     auto *command = registry.find(cmd);

//     if (command)
//     {
//         command -> execute(args); 
//     }
//     else 
//     {
//         cout << "Unknown command\n"; 
//     }
// }