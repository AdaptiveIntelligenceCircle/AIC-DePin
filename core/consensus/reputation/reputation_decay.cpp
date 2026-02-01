#include "reputation_decay.h"

#include <algorithm>
using namespace std; 

// default reputation decay modetl cho AIC-DePin.

namespace aic :: consensus :: reputation 
{
    class DefaultReputationDecay : public ReputationDecay 
    {
        public: 
        double decay(double current_reputation, 
        const ReputationContext &ctx) const override 
        {
            // human override -> giu nguyen ...
            if (ctx.human_override)
            return current_reputation; 

            double reputation = current_reputation; 

            // 1. Inactivity decay.. 
            double inactive_time = ctx.current_time - ctx.last_active_time; 
            if (inactive_time > kInactivityThreshold){
                double steps  = inactive_time / kInactivityThreshold; 
                reputation *= max(0.5, 1.0  - steps *kInactivityRate); 
            }

            if (ctx.has_recent_slash)
            {
                double slash_factor = 
                1.0 - clamp(ctx.slash_severity, 0.0, 1.0) * kSlashImpact; 

                reputation *= max(0.0, slash_factor); 
            }

            if (ctx.under_dispute)
            {
                reputation = min(reputation, current_reputation); 
            }

            return clamp(reputation, 0.0, 1.0);
        } 

        private:
    static constexpr double kInactivityThreshold = 3600.0 * 24 * 7; // 7 days
    static constexpr double kInactivityRate = 0.05;                 // 5% per step
    static constexpr double kSlashImpact = 0.7;                     // up to 70%
    }; 
}