#include "latency_cheating.h"

using namespace std; 

namespace aic :: simulation :: adversary
{
    LatencyCheating :: LatencyCheating(double fake_latency)
    : fake_latency(fake_latency){}

    string LatencyCheating :: name() const 
    {
        return "LatencyCheating"; 
    }

    void LatencyCheating :: beforeConsensus(
        vector<NodeContext> &nodes, 
        vector<TaskContext> &tasks
    ) 
    {
        for (auto &node : nodes)
        {
            if (node.is_malicious)
            {
                node.latency = fake_latency; 
            }
        }
    }
}