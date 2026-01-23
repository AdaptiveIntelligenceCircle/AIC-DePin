#include "stake_manager.h"
using namespace std; 

namespace aic :: depin :: staking
{
    StakeManager :: StakeManager(
        unique_ptr<StakePolicy> policy, 
        LockupModel lockup
    ): policy_(move(policy)), lockup_(lockup) {}
    
    void StakeManager :: stake(
        const string &node_id, 
        double amount, 
        const StakeContext &ctx
    )
    {
        auto &record = stakes_[node_id]; 
        record.node_id = node_id; 
        record.amount += amount; 
        record.start_epoch = ctx.current_epoch; 
        record.lock_until_epoch = 
            lockup_.computeLockUntil(ctx.current_epoch); 

        record.reputation_weight = ctx.network_health; 
    }

    bool StakeManager :: unstake(
        const string &node_id, 
        const StakeContext &ctx
    )
    {
        if (!hasStake(node_id))
        return false; 

        auto &record = stakes_[node_id]; 
        if (!unstake_rules_.canUnstake(record, ctx.current_epoch))
        return false; 

        stakes_.erase(node_id);
        return true; 
    }

    void StakeManager :: slash(
        const string &node_id, 
        double severity
    )
    {
        if (!hasStake(node_id))
        return ; 

        auto &record = stakes_[node_id]; 
        record.amount *= (1.0 - severity); 
        record.slashed = true; 
        record.reputation_weight = policy_ -> computeWeight(record); 
    }

    double StakeManager :: stakeWeight(
        const string &node_id
    ) const 
    {
        auto it = stakes_.find(node_id); 
        if (it == stakes_.end())
        return 0.0; 
        
        return it -> second.reputation_weight; 
    }

    bool StakeManager :: hasStake(
        const string &node_id
    ) const 
    {
        return stakes_.count(node_id) > 0; 
    }
}