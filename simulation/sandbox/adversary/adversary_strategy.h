#pragma once

#include "adversary_profile.h"
using namespace std;

namespace aic ::sandbox
{
    class AdversaryStrategy
    {
    public:
        virtual ~AdversaryStrategy() = default;

        virtual void plan(const AdversaryProfile); 
        virtual void act() = 0;
        virtual bool adapt() = 0; 
    };
}