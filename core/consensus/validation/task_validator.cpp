#include "task_validator.h"
using namespace std; 
namespace aic :: consensus
{
    ValidationResult TaskValidator :: validate(
        const Task &task, 
        const QuorumContext &ctx, 
        const vector<QuorumSignal> &signals 
    )
    {
        QuorumEngine engine; 
        bool ok = engine.evaluate(ctx, signals); 
        if (!ok) return ValidationResult :: REJECTED; 

        if (task.critically > 0.7 and signals.size() < 3)
        {
            return ValidationResult :: PARTIAL; 
        }
        return ValidationResult :: ACCEPTED; 
    }
}