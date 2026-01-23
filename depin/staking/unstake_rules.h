#pragma once 
#include "stake_record.h"

using namespace std; 

namespace aic :: depin :: staking 
{
    class UnstakeRules
    {
        public:
        bool canUnstake(const StakeRecord &stake, uint64_t current_epoch)
        {
            if (stake.frozen or stake.slashed)
            return false; 

            return current_epoch >= stake.lock_until_epoch; 
        }
    }; 
}