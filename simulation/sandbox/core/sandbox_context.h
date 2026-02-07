#pragma once 
#include <iostream>

#include "../adversary/adversary_profile.h"
#include "../scenario/scenario_constraint.h"

using namespace std; 

namespace aic :: sandbox 
{
    struct SandboxContext 
    {
        AdversaryProfile adversary; 
        ScenarioConstraints constraints;
    }; 
}