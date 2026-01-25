#pragma once 

namespace aic :: depin :: incentive 
{
    class DecayModel
    {
        public:
        virtual ~DecayModel () = default; 

        // returns mulitiplier [0,1]..
        virtual double decayFactor(
            double last_contribution_time, 
            double current_time
        ) const = 0;
    };  
}