#include "cli.h"
using namespace std;

#include <iostream>
#include <sstream>

CLI :: CLI()
{
    // commands registered here.
}

void CLI :: run()
{
    string line; 
    while (getline(cin, line))
    {
        execute_line(line); 
    }
}

void CLI :: execute_line(const string &line)
{
    istringstream iss(line); 
    string cmd; 
    iss >> cmd; 

    vector<string> args; 
    string arg; 
    while (iss >> arg) args.push_back(arg); 

    auto *command = registry.find(cmd);

    if (command)
    {
        command -> execute(args); 
    }
    else 
    {
        cout << "Unknown command\n"; 
    }
}