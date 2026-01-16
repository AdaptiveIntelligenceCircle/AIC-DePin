#include "threshold_policy.h"

using namespace std; 

namespace aic :: consensus
{
    double ThresholdPolicy :: compute(double risk, double instability)
    {
        return 0.5 + (risk *0.3) + (instability * 0.2); 
    }
}