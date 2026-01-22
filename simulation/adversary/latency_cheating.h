#pragma once 

#include "adversary_base.h"

namespace aic :: simulation :: adversary
{
    class LatencyCheating : public Adversary
    {
        public: 
        explicit LatencyCheating(double fake_latency); 
        // do tre gia cho node doc hai.. 
        string name() const override; 

        void beforeConsensus(
            vector<NodeContext> &nodes, 
            vector<TaskContext> &tasks 
        ) override; 

        private: 
        double fake_latency;
    }; 
}