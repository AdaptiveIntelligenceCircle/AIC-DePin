#include "incentive_engine.h"
using namespace std; 

namespace aic :: depin :: incentive 
{
    IncentiveEngine::IncentiveEngine(
            unique_ptr<ContributionModel> contribution, 
            unique_ptr<DecayModel> decay, 
            unique_ptr<RewardPolicy> reward 
    ) 
    {
        contribution_ = move(contribution); 
        decay_ = move(decay); 
        reward_ = move(reward); 
    }

    Reward IncentiveEngine :: evaluate(const ContributionRecord &record, double now)
    {
        double score = contribution_ -> evaluate(record); 
        double decay_factor = decay_ -> decayFactor(record.timestamp, now); 
       //  return reward_-> computeReward(score, decay_factor); 
    }
}