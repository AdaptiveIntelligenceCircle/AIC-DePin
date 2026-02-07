#include "sandbox_runner.h"
using namespace std; 
#include "../scenario/scenario.h"

namespace aic :: sandbox 
{
    SandboxRunner :: SandboxRunner(SandboxContext ctx)
    {
        scenario = nullptr ;
        context = ctx; 
    }

    void SandboxRunner :: attachScenario(Scenario *sc)
    {
         
    }

    void SandboxRunner :: run()
    {
        // scenario -> setup();

        // while (!scenario->is_finished() &&
        //    context.current_step < context.constraints.max_steps) {
        // scenario->execute_step();
        // context.current_step++;
        // }
    }

}


// void SandboxRunner::load_scenario(Scenario* s) 
// {
//     scenario = s;
//     scenario->setup();
// }

// void SandboxRunner::add_node(const SandboxNode& node) 
// {
//     nodes.push_back(node);
// }

// void SandboxRunner::run(int ticks) 
// {
//     for (int i = 0; i < ticks; ++i) 
//     {
//         scenario->step();
//         for (auto& n : nodes) {
//             n.tick();
//             n.act();
//         }
//     }
// }