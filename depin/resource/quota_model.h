#pragma once 
#include "resource_type.h"

namespace aic :: depin :: resource 
{
    struct Quota
    {
        double max = 0.0; 
        double burst = 0.0; 
    }; 

    class QuotaModel
    {
        public: 
        Quota compute(double stake_weight, 
        double trust_score, ResourceType type) const
        {
            double base = stake_weight * trust_score;

        switch (type) {
            case ResourceType::Compute:
                return { base * 10.0, base * 2.0 };
            case ResourceType::Storage:
                return { base * 50.0, base * 5.0 };
            case ResourceType::Bandwidth:
                return { base * 20.0, base * 3.0 };
            case ResourceType::TaskPriority:
                return { base * 1.0, 0.0 };
            case ResourceType::GossipVisibility:
                return { base * 1.5, 0.0 };
        }
        return {};
        }
    }; 
}