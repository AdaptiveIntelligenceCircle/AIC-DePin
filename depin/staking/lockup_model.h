#pragma once 
#include <cstdint> 

using namespace std; 

namespace aic :: depin :: staking 
{
    class LockupModel
    {
        public: 
        explicit LockupModel(uint64_t min_epochs)
        {
            min_lock_epochs = min_epochs; 
        }

        bool isLocked(uint64_t current_epoch, uint64_t lock_until) const 
        {
            return current_epoch < lock_until;
        }

        uint64_t computeLockUntil(uint64_t start_epoch) const 
        {
            return start_epoch + min_lock_epochs; 
        }
        
        uint64_t min_lock_epochs = 0;
    }; 
}