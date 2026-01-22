#pragma once 
#include <string> 

#include <vector> 
using namespace std; 

namespace aic :: simulation :: adversary
{
    struct NodeContext
    {
        string node_id; 
        double reputation; 
        double latency; 
        bool is_malicious = false; 
    }; 

    struct TaskContext
    {
        string task_id; 
        string assigned_node; 
        bool valid = true; 
    }; 

    class Adversary
    {
        public: 
        virtual ~Adversary() = default; 

        virtual string name() const = 0; 

        // can thiep truoc consensus.. 
        virtual void beforeConsensus(
            vector<NodeContext> &nodes, 
            vector<TaskContext> &tasks
        ) {}

        // can thiep trong consensus.. 
        virtual void duringConsensus(
            vector<NodeContext> &nodes, 
            vector<TaskContext> &tasks
        ) {}

        // can thiep sau consensus.. 
        virtual void afterConsensus(
            vector<NodeContext> &nodes, 
            vector<TaskContext> &tasks 
        ) {}

    }; 
} // namespace aic :: simulation :: adversary..