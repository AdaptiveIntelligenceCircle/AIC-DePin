#include "test_runner.h"
#include "test_runner.cpp"

using namespace std;

// Forward declarations of test registration.. // 
void register_unit_tests(aic :: tests :: TestRunner &runner); 
void register_intergration_tests(aic :: tests :: TestRunner &runner);
void register_simulation_tests(aic :: tests :: TestRunner &runner); 
void register_replay_tests(aic::tests:: TestRunner &runner); 

int main()
{
    aic :: tests :: TestRunner runner; 

    register_unit_tests(runner); 
    register_intergration_tests(runner); 
    register_simulation_tests(runner); 
    register_replay_tests(runner);

    return runner.runAll(); 
}