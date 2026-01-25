#include "ethical_override.h"
using namespace std; 

namespace aic :: extensions 
{
    class DefaultEthicalOverride : public EthicalOverride 
    {
        public: 
        EthicalDecision evaluate(const EthicalContext &ctx) override 
        {
            // Minimal baseline ethics.. 
            if (ctx.reason.find("human harm") != string ::npos)
            return EthicalDecision ::Block; 

            if (ctx.reason.find("uncertain") != string :: npos)
            return EthicalDecision ::Escalate; 

            else 
            return EthicalDecision :: Allow; 
        }
    };  
}