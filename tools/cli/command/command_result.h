#pragma once 
#include <iostream>

#include <string> 
using namespace std; 

namespace aic :: cli
{
    struct CommandResult 
    {
        bool success; // failed or succeed. 
        string message;  // message
        string explanation; // for explain nodedt

        static CommandResult ok(const string &msg)
        {
            return {
                true, msg, ""
            };
        }

        static CommandResult fail(const string &msg)
        {
            return  
            {
                false, msg, ""
            }; 
        }
    }; 
}