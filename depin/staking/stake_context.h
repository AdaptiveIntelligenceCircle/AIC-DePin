#pragma once 
#include <cstdint>

using namespace std;

namespace aic :: depin :: staking 
{
    struct StakeContext
    {
        uint64_t current_epoch; 
        double network_health; 
    }; 
}