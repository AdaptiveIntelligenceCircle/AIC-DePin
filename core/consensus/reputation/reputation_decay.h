#pragma once 
#include <iostream>

using namespace std; 

namespace aic :: consensus :: reputation 
{
    // context anh huong toi reputation decay. 
    // Khong chi la thoi gian - ma la hanh vi.. 

    struct ReputationContext 
    {
        string node_id; 

        double last_active_time; 
        double current_time; 

        bool has_recent_slash; 
        double slash_severity; 

        bool under_dispute; 
        bool human_override; 
    }; 

    // Reputation decay interface.. 
    // output : multiplier [0.0 - 1.0]

    class ReputationDecay 
    {
        public: 
        virtual ~ReputationDecay() = default; 

        // return decay mlutiplier 
        // giu nguyen reputation.. 


        virtual double decay(
            double current_reputation, 
            const ReputationContext &context
        ) const = 0; 
    }; 
}