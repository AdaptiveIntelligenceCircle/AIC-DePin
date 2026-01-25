#include "human_approve_task.h"

namespace aic::extensions 
{

class ManualHumanApproval : public HumanApproval 
{
    public:
    ApprovalResult requestApproval(const ApprovalRequest&) override 
    {
        // Placeholder: real impl via UI / CLI / governance
        return ApprovalResult::Deferred;
    }
};

}
