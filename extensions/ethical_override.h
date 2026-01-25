#pragma once 
#include <string> 

using namespace std; 

namespace aic :: extensions
{
    enum class EthicalDecision
    {
        Allow, 
        Block, 
        Escalate
    };

    struct EthicalContext 
    {
        string action; 
        string node_id; 
        string reason; 
    }; 

    class EthicalOverride 
    {
        public: 
        virtual ~EthicalOverride() = default; 
        virtual EthicalDecision evaluate(const EthicalContext &ctx) = 0;
    }; 
}