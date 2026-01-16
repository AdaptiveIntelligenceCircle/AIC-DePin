#include "reputation_model.h"
#include <algorithm>

using namespace std; 

namespace aic :: consensus
{
    void ReputationModel :: update(double behavior_score)
    {
        // Exponential smoothing + decay.. // 
        reputation_ = (reputation_ *0.9) + (behavior_score * 0.1); 
        reputation_ = clamp(reputation_ , 0.0, 1.0); 
    }

    double ReputationModel :: value() const 
    {
        return reputation_ ; 
    }
}