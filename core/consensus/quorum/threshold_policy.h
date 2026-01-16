#pragma once 

namespace aic :: consensus
{
    class ThresholdPolicy
    {
        public: 
        static double compute(double risk, double instability); 
    }; 
}