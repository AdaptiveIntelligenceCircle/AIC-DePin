#include "sandbox_runner.h"
using namespace std; 

void SandboxRunner::load_scenario(Scenario* s) 
{
    scenario = s;
    scenario->setup();
}

void SandboxRunner::add_node(const SandboxNode& node) 
{
    nodes.push_back(node);
}

void SandboxRunner::run(int ticks) 
{
    for (int i = 0; i < ticks; ++i) 
    {
        scenario->step();
        for (auto& n : nodes) {
            n.tick();
            n.act();
        }
    }
}