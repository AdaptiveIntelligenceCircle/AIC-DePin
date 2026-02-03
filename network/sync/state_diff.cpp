#include "state_diff.h"
using namespace std ;

namespace aic :: network :: sync 
{
    void StateDiff :: addChange(const StateChange &change)
    {
        m_changes.push_back(change); 
    }   

    const vector<StateChange> &StateDiff :: changes() const 
    {
        return m_changes; 
    }

    bool StateDiff :: empty() const 
    {
        return m_changes.empty(); 
    }

    size_t StateDiff :: size() const 
    {
        return m_changes.size(); 
    }
}