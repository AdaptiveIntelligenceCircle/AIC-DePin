#pragma once 
#include <string>

using namespace std; 

#include <cmath>

namespace aic :: simulation :: replay 
{
    struct ReplayPermission 
    {
        string requester; 
        double trust_score = 0.0; 

        bool allow() const 
        {
            return trust_score >= 0.5; 
        }
    };
}
