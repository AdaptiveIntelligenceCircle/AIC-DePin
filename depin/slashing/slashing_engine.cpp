#include "slashing_engine.h"
using namespace std; 

#include <iostream>
#include <string> 

namespace aic :: depin :: slashing 
{
    void SlashingEngine :: register_rule(shared_ptr<SlashingRule> rule)
    {
        rules_.push_back(rule); 
    }

    bool SlashingEngine :: evaluate(
        const SlashingContext &ctx , 
        vector<Evidence> &out_evidence, 
        PenaltyModel &out_penalty
    )
    {
        double max_severity = 0.0; 
        bool violated = false; 

        for (const auto &rule : rules_)
        {
            if (rule -> match(ctx))
            {
                violated = true; 
                max_severity  = max(max_severity, rule-> severity(ctx));

                Evidence ev; 
                ev.source = "slashing engine";
                ev.type = "rule match"; 
                ev.summary = rule -> description(); 
                out_evidence.push_back(ev); 
            }
        }

        if (!violated) return false; 
        out_penalty = compute_penalty(max_severity); 
        return true; 
    }

    PenaltyModel SlashingEngine :: compute_penalty(double severity) const 
    {
        PenaltyModel p; 

        if (severity < 0.3)
        {
            p.stake_slash_ratio = 0.05;
        }
        else if(severity < 0.7){
            p.stake_slash_ratio = 0.2;
            p.reward_freeze_time = 3600; 
        }
        else{
            p.stake_slash_ratio = 0.5; 
            p.temporary_ban  = true; 
        }
        return p; 
    }

    void SlashingEngine :: submit_appeal(const AppealProcess &appeal)
    {
        appeals_.push_back(appeal); 
    }
}