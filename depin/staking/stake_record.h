#pragma once 
#include <string> 
#include <cstdint>

using namespace std; 

namespace aic :: depin :: staking
{
    struct StakeRecord
    {
        string node_id; 
        double amount = 0.0; // stake value.. 
        double reputation_weight = 0; 

        uint64_t start_epoch = 0; 
        uint64_t lock_until_epoch = 0; 

        bool slashed = false; 
        bool frozen = false; 
    }; 
}