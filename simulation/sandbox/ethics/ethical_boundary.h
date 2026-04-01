#pragma once 
#include <iostream> 

using namespace std; 

namespace aic  
{
    enum class EthicalViolation 
    {
        NONE, 
        EXCESSIVE_PENALTY, 
        REAL_WORLD_IMPACT, 
        IRREVERSIBLE_DAMAGE 
    }; 
}