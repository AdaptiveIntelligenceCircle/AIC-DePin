// #pragma once 
// class ReplayPolicy
// {
//     public: 
//     bool allow_full_replay() const; 
//     bool allow_partial_replay() const; 
// };

#pragma once 
#include "../event/event.h"

#include <iostream> 
using namespace std; 

namespace aic :: simulation :: replay 
{
    enum class ReplayMode 
    {
        OBSERVE_ONLY, 
        SIMULATE, 
        WHAT_IF
    }; 

    struct ReplayPolicy 
    {
        ReplayMode mode = ReplayMode :: OBSERVE_ONLY; 

        bool allow_override = false; 
        bool allow_governance_events = false; 
        bool allow_slashing_events = false; 

        bool canReplay(const Event &event) const{
            if (event.type == EventType :: SLASHING and !allow_slashing_events)
            {
                return false; 
            }

            if (event.type == EventType :: OVERRIDE and !allow_override)
            {
                return false; 
            }
            return true; 
        } 
    }; 
}