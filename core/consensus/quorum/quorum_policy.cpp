#include "quorum_policy.h"

using namespace std; 

namespace aic :: consensus :: quorum 
{
    // Default quorum policy.. 
    // Du so luong 
    // Trust khong qua thap.. 
    // Risk cao -> yeu cau quorum manh hon.. 

    class DefaultQuorumPolicy : public QuorumPolicy 
    {
        public: 
        bool isQuorumSatisfied (
            const QuorumContext &context, 
            size_t agree_count
        ) const override 
        {
            const size_t total = context.voters.size(); 
            if (total == 0) return false; 

            double agree_ratio = static_cast<double>(agree_count) / total; 

            // base queue.. 
            double required = 0.5; 

            // Trust yeu -> tang yeu cau.. 
            if (context.average_trust < 0.5)
            {
                required += 0.15; 
            }

            // Risk cao -> quorum chat hon.. 
            if (context.risk_level > 0.7)
            required += 0.2; 

            // sensitive topics.. 
            if (context.topic == "clashing" or 
            context.topic == "ethical_override"){
                required += 0.1; 
            }

            return agree_ratio >= required; 
        }
    }; 
}