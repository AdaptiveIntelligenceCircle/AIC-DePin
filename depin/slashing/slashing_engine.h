#pragma once 
#include <iostream>

#include "slashing_rule.h"
#include "slashing_context.h"

#include "penalty_model.h"
#include "evidence.h"
#include "appeal_process.h"

#include <string> 
#include <algorithm> 

#include <vector> 
using namespace std; 

namespace aic :: depin :: slashing 
{
    class SlashingEngine 
    {
        public: 
        void register_rule(shared_ptr<SlashingRule> rule); 

        bool evaluate(const SlashingContext &ctx, 
        vector<Evidence> &out_evidence,
        PenaltyModel &out_penalty);

        void submit_appeal(const AppealProcess &appeal); 
        
        private: 
        vector<shared_ptr<SlashingRule>> rules_; 
        vector<AppealProcess> appeals_; 

        PenaltyModel compute_penalty(double severity) const ; 
    };
} // namespace aic :: depin :: slashing.. 