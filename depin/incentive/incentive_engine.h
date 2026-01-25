#pragma once 

#include <memory> 
#include "contribution_model.h"

#include "decay_model.h"
#include "reward_policy.h"

using namespace std; 

namespace aic :: depin :: incentive 
{
    class IncentiveEngine 
    {
        public: 
        IncentiveEngine() = default; 
        ~IncentiveEngine() = default; 

        IncentiveEngine(
            unique_ptr<ContributionModel> contribution, 
            unique_ptr<DecayModel> decay, 
            unique_ptr<RewardPolicy> reward 
        ); 

        Reward evaluate(const ContributionRecord &record , double now); 
        // double computeReward(double score, double decay_factor); 
        private: 
        unique_ptr<ContributionModel> contribution_;  
        unique_ptr<DecayModel> decay_;  
        unique_ptr<RewardPolicy> reward_ ; 
    }; 
}