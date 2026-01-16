#pragma once 
#include "task.h"

#include "../quorum/quorum_engine.h"
#include <vector> 

using namespace std; 

namespace aic :: consensus
{
    enum class ValidationResult
    {
        ACCEPTED, 
        PARTIAL, 
        REJECTED
    }; 

    class TaskValidator
    {
        public: 
        ValidationResult validate(
            const Task &task, 
            const QuorumContext &ctx, 
            const vector<QuorumSignal> &signals
        ); 
    }; 
}