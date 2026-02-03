// #pragma once 

// class SyncPolicy
// {
//     public: 
//     bool allow_sync(); 
// }; 

#pragma once 
#include <iostream>
using namespace std; 

#include "state_diff.h"
#include <string> 

namespace aic :: network :: sync 
{
    enum class SyncDecision
    {
        ACCEPT, 
        REJECT, 
        PARTIAL_ACCEPT,
        REQUIRE_HUMAN_APPROVE
    }; 

    struct SyncContext 
    {
        string local_node_id; 
        string remote_node_id; 
        double remote_trust_score; 
        bool is_replay; 
    }; 

    class SyncPolicy 
    {
        public: 
        virtual ~SyncPolicy() = default; 

        virtual SyncDecision evaluate(
            const StateDiff &diff, 
            const SyncContext &context
        ) const = 0; 
    }; 
}