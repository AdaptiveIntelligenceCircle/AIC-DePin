#include <iostream> 

using namespace std; 

#include <string> 
#include "slashing_context.h"

namespace aic :: depin :: slashing
{
    class SlashingRule 
    {
        public:
        virtual ~SlashingRule() = default; 

        virtual string rule_id() const = 0;
        virtual string description() const = 0;

        virtual bool match(const SlashingContext &ctx) const = 0; 
        virtual double severity(const SlashingContext &ctx) const = 0; 
    }; 
} // namespace aic :: depin :: slashing. 