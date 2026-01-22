#pragma once 
#include "adversary_base.h"

using namespace std; 

namespace aic :: simulation :: adversary
{
    class CollusionAttack : public Adversary
    {
        public: 
        explicit CollusionAttack(double boost_factor = 1.2); 

        string name() const override; 

        void duringConsensus(
            vector<NodeContext> &nodes, 
            vector<TaskContext> &tasks
        )override ; 

        private: 
        double boost_factor; 
    }; 
}