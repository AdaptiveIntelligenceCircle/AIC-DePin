#pragma once 
using namespace std; 

#include <iostream>
#include <string> 

namespace aic :: cli 
{
    enum class CliPermission 
    {
        READ, 
        OPERATOR, 
        GOVERNANCE, 
        ROOT
    }; 

    struct PermissionContext 
    {
        string caller; 
        double trust_score; 
    }; 

    bool checkPermission 
    (
        CliPermission required, 
        const PermissionContext &ctx
    ); 
}