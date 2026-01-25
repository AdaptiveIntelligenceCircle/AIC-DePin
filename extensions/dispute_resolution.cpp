#include "dispute_resolution.h"
#include <unordered_map>

using namespace std; 

namespace aic :: extensions 
{
    class BasicDisputeResolutions : public DisputeResolution 
    {
        public:
        void submitDispute(const DisputeCase &dispute) override 
        {
            disputes_[dispute.dispute_id] = dispute; 
        }

        DisputeStatus resolve(const string &dispute_id) override 
        {
            auto it = disputes_.find(dispute_id); 
            if (it == disputes_.end())
            return DisputeStatus :: Rejected; 

            // Default conservative logic.. 
            it -> second.status = DisputeStatus :: Escalated; 
            return it -> second.status;
        }

        private: 
        unordered_map<string, DisputeCase> disputes_; 
    }; 
}