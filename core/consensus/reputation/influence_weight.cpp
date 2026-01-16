#include "influence_weight.h"

using namespace std; 

namespace aic :: consensus
{
    double InfluenceWeight :: apply(double trust, double reputation)
    {
        // reputation influences signal weight but never dominates trust.
        return trust * (0.7 + 0.3 * reputation); 
    }
}