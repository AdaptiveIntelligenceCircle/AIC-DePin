#pragma once
#include <string>

using namespace std;

namespace aic ::sandbox
{
    class Scenario
    {
    public:
        virtual string name() const = 0;
        virtual void setup() = 0;
        virtual void Executive_step() = 0;
        virtual ~Scenario() = default;
        virtual bool is_finished() const = 0; 
    };
}
