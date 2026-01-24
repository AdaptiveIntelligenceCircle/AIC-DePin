#pragma once 
#include <iostream>

#include <string> 
#include <vector> 

#include "evidence.h"
using namespace std;

namespace aic :: depin :: slashing 
{
    enum class AppealStatus 
    {
        Pending, 
        Accepted, 
        Rejected
    }; 

    struct AppealProcess 
    {
        string appeal_id; 
        string node_id; 

        vector<Evidence> counter_evidence; 
        AppealStatus status  = AppealStatus :: Pending; 

        string human_reviewer; 
        string decision_note; 
    }; 
}