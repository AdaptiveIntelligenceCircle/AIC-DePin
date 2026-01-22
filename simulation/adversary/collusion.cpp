#include "collusion.h"

using namespace std; 

namespace aic :: simulation :: adversary
{
    CollusionAttack :: CollusionAttack(double boost_factor)
    : boost_factor(boost_factor){}

    string CollusionAttack :: name() const 
    {
        return "CollusionAttack"; 
    }

    void CollusionAttack :: duringConsensus(
        vector <NodeContext> &nodes, 
        vector<TaskContext> &tasks
    ) 
    {
        // cac node doc hai boost reputation cho nhau.. 
        for (auto &node : nodes)
        {
            if (node.is_malicious)
            {
                node.reputation *= boost_factor; 
            }
        }
    }
}