#pragma once 
#include "stake_record.h"

using namespace std; 

namespace aic :: depin :: staking
{
    class StakePolicy
    {
        public: 
        virtual ~StakePolicy() = default; 

        virtual double computeWeight (const StakeRecord& stake) const =0; 
    };

    class LinearStakePolicy : public StakePolicy
    {
        public:
        double computeWeight(const StakeRecord &stake) const override 
        {
            return stake.amount * (stake.slashed ? 0.2 : 1.0); 
        }
    }; 
}