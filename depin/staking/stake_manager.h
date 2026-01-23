#pragma once 

#include <unordered_map>
#include <memory> 

#include "stake_record.h"
#include "stake_policy.h"

#include "lockup_model.h"
#include "unstake_rules.h"

#include "stake_context.h"
using namespace std ; 

namespace aic :: depin :: staking
{
    class StakeManager
    {
        public: 
        StakeManager(unique_ptr<StakePolicy> policy, 
        LockupModel lockup);

        void stake(const string &node_id, 
        double amount, const StakeContext &ctx);
        
        bool unstake(const string &node_id, 
        const StakeContext &ctx); 

        void slash(const string &node_id, double severity); 

        double stakeWeight(const string &node_id) const; 

        bool hasStake(const string &node_id) const; 

        public: 
        unordered_map<string, StakeRecord> stakes_;
        unique_ptr<StakePolicy> policy_;
        LockupModel lockup_; 
        UnstakeRules unstake_rules_; 

    }; 
}