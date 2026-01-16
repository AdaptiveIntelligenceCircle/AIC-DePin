#include "dispute_resolver.h"
#include <iostream> 

using namespace std; 

namespace aic :: consensus
{
    void DisputeResolver :: triggerReplay(const char *task_id)
    {
        cout << "Replay - Triggering replay for task:" 
        << task_id << endl; 
    }
}