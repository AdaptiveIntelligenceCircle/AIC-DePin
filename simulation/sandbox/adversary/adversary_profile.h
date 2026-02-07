#pragma once
#include <iostream>
using namespace std;

#include <string> 
#include <vector> 

// enum class AdversaryProfile
// {
//     HONEST,
//     SYBIL,
//     COLLUDER,
//     LATENCY_CHEATER,
//     RESOURCE_LIAR,
//     SLOW_POISONER
// };

namespace aic ::sandbox
{
    enum class AdversaryIntest
    {
        ECONOMIC_EXPLOIT,
        GOVERNANCE_ATTACK,
        RESOURCE_HOARDING,
        TRUST_MANIPULATION,
        CHAOS_INDUCTION
    };

    struct AdversaryProfile 
    {
        string id; 
        AdversaryIntest intent; 
        float sophiscation; 
        float patience; 
        float risk_tolerance; 
        vector<string> known_capabilities; 
    }; 
}
