#pragma once 
using namespace std; 
#include <string> 

namespace aic :: extensions 
{
    enum class ApprovalResult 
    {
        Approved, 
        Rejected, 
        Deferred
    }; 

    struct ApprovalRequest
    {
        string request_id; 
        string action;
        string justification; 
    };

    class HumanApproval 
    {
        public: 
        virtual ~HumanApproval() = default; 
        virtual ApprovalResult requestApproval(const ApprovalRequest &request) = 0; 
    };
}