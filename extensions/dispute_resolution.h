#pragma once 
using namespace std; 

#include <string>
#include <vector> 

namespace aic :: extensions 
{
    enum class DisputeType 
    {
        SlashingDispute, 
        RewardDispute, 
        TrustScoreDispute
    };

    enum class DisputeStatus 
    {
        Pending,
        Accepted, 
        Rejected, 
        Escalated
    };

    struct DisputeCase 
    {
        string dispute_id; 
        string node_id; 
        DisputeType type; 

        string description;
        vector<string> evidence_refs;
        DisputeStatus status; 
    }; 

    class DisputeResolution
    {
        public: 
        virtual ~DisputeResolution() = default; 

        virtual void submitDispute(const DisputeCase &dispute) = 0; 
        virtual DisputeStatus resolve(const string &dispute_id) = 0; 
    }; 
}