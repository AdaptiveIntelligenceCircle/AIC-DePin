#include "sync_engine.h"
#include <iostream>

using namespace std; 

namespace aic :: network :: sync 
{
    SyncEngine :: SyncEngine(shared_ptr<SyncPolicy> policy)
    {
        m_policy = move(policy); 
    }   

    SyncDecision SyncEngine :: processDiff(
        const StateDiff &diff, 
        const SyncContext &context 
    )
    {
        if (!m_policy)
        {
            return SyncDecision :: REJECT; 
        }

        SyncDecision decision  = m_policy -> evaluate(diff, context); 

        if (decision == SyncDecision :: ACCEPT or 
        decision == SyncDecision :: PARTIAL_ACCEPT)
        {
            applyDiff(diff); 
        }
        return decision; 
    }

    void SyncEngine :: applyDiff(const StateDiff &diff)
    {
        for (const auto &change : diff.changes())
        {
            applyChange(change); 
        }
    }

    void SyncEngine :: applyChange(const StateChange &change)
    {
        // placeholder : actual state share belongs to core/node or resource layer.. 
        switch(change.type)
        {
            case DiffType :: ADD:
            cout <<"SYNC add" << change.key << endl; 
            break; 

            case DiffType :: UPDATE:
            cout << "UPDATE " << change.key << endl; 
            break; 

            case DiffType :: REMOVE:
            cout << "Remove" << endl; 
            break; 
        }
    }
}