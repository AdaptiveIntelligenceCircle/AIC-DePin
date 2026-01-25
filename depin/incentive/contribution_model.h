#pragma once 
#include <string>
using namespace std; 

namespace aic :: depin :: incentive 
{
    enum class ContributionType 
    {
        Compute, 
        Storage, 
        Relay, 
        PhysicalPresence,
        HumanAttendence
    }; 

    struct ContributionRecord 
    {
        string node_id; 
        ContributionType type ; 
        double amount; 
        double quality; // 0.0 -> 1.0  
        double timestamp; 
    }; 

    class ContributionModel 
    {
        public: 
        virtual ~ContributionModel() = default; 
        virtual double evaluate(const ContributionRecord &record) const = 0; 
    };
}