#pragma once 
#include <vector> 

#include <string> 
using namespace std; 

namespace aic :: consensus
{
    struct QuorumContext
    {
        string task_id; 
        double risk_level; 
        double network_stability;  
    }; 

    struct QuorumSignal
    {
        string node_id; 
        double trust_score; 
        bool approve;  
    }; 

    class QuorumEngine
    {
        public: 
        bool evaluate(
            const QuorumContext &ctx, 
            const vector<QuorumSignal> &signals 
        )const; 
    };
}