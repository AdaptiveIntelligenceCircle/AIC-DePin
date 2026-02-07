#pragma once 
#include <iostream>

#include <string>
using namespace std; 

namespace aic :: sandbox 
{
    enum class EthicalViolation 
    {
        NONE, 
        EXCESSIVE_PENALTY,
        REAL_WORLD_IMPACT, 
        IRREVERSIBLE_DAMAGE
    };
}