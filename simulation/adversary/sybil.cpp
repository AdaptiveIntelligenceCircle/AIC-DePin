#include "sybil.h"

using namespace std; 

namespace aic :: simulation :: adversary
{
    SybilAttack :: SybilAttack(int fake_nodes)
    {
        fake_nodes_ = fake_nodes; 
    }

    string SybilAttack :: name() const 
    {
        return "SybilAttack"; 
    }

    void SybilAttack :: beforeConsensus(
        vector<NodeContext> &nodes, 
        vector<TaskContext> &tasks
    ) 
    {
        
        for (int i = 0 ; i < fake_nodes_; ++i)
        {
            NodeContext fake; 
            fake.node_id = "sybil_" + to_string(i); 
            fake.reputation = 0.0; 
            fake.latency = 10.0; 
            fake.is_malicious = true; 

            nodes.push_back(fake); 
        }
    }
}
