// #pragma once 
// #include "state_diff.h"

// using namespace std; 

// class SyncEngine
// {
//     public:
//     void push_diff(const StateDiff&); 
//     void pull_diff(); 
// }; 

#pragma once 
#include "state_diff.h"

#include "sync_policy.h"
#include <memory> 

using namespace std; 

namespace aic :: network :: sync 
{
    class SyncEngine 
    {
        public: 
        explicit SyncEngine (shared_ptr<SyncPolicy> policy); 

        SyncDecision processDiff(
            const StateDiff &diff,
            const SyncContext& context 
        ); 

        void applyDiff(const StateDiff &diff); 

        private: 
        shared_ptr<SyncPolicy> m_policy; 
        void applyChange(const StateChange &change);
    }; 
}