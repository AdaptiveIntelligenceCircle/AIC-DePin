#pragma once 

#include <iostream> 

#include <string> 
using namespace std; 

namespace aic :: depin :: incentive 
{
    struct Reward
    {
        double token_reward; 
        double trust_boost; 
        bool priority_process; 
    }; 

    class RewardPolicy
    {
        RewardPolicy() = default; 
        virtual ~RewardPolicy() = default;

        virtual Reward computeReward(
            double token_reward, 
            double trust_boost, 
            bool priority_process
        ) const = 0; 
        
    }; 
}