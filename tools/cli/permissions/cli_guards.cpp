#include "cli_permission.h"
using namespace std; 

#include <string> 
#include <vector> 

namespace aic :: cli 
{
    bool checkPermission(
        CliPermission required, 
        const PermissionContext &ctx
    )
    {
        switch(required)
        {
            case CliPermission :: READ: 
            return true; 
            case CliPermission :: OPERATOR: 
            return ctx.trust_score >= 0.3; 
            case CliPermission :: GOVERNANCE:
            return ctx.trust_score >= 0.6; 
            case CliPermission :: ROOT:
            return ctx.trust_score >= 0.9; 
        }
        return false; 
    }
} // namespace aic :: cli