#pragma once 
#include "../cursor/replay_cursor.h"

#include "../policy/replay_policy.h"
#include "../policy/replay_permission.h"

using namespace std; 

namespace aic :: simulation :: replay 
{
    struct ReplaySession 
    {
        ReplayCursor start; 
        ReplayCursor end; 

        ReplayPolicy policy; 
        ReplayPermission permission; 

        bool valid() const 
        {
            return permission.allow(); 
        }
    }; 
}   