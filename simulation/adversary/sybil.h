#pragma once 
#include "adversary_base.h"

using namespace std;

namespace aic :: simulation :: adversary
{
    class SybilAttack : public Adversary
    {
        public: 
        explicit SybilAttack(int fake_nodes); 

        string name() const override; 

        void beforeConsensus(
            vector<NodeContext> &nodes, 
            vector<TaskContext> &tasks
        ) override;

        private: 
        int fake_nodes_; 
    }; 
}