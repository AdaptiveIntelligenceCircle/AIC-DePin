#include <iostream>
using namespace std; 

#include <string> 
#include <vector>

namespace aic :: depin :: slashing 
{
    struct PenaltyModel
    {
        double stake_slash_ratio = 0.0; 
        double reward_freeze_time = 0.0; 
        bool temporary_ban = false; 
        bool permanent_ban = false; 

        string note; 
    }; 
} // namespace aic :: depin :: slashing. 