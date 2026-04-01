#include "../harness/test_runner.h"

// forward
// void register_consensus_trust_pipeline_tests(aic::tests::TestRunner& runner);
void register_routing_sync_pipeline_tests(aic::tests::TestRunner& runner);
void register_slashing_governance_pipeline_tests(aic::tests::TestRunner& runner);

void register_integration_tests(aic::tests::TestRunner& runner) {
    // register_consensus_trust_pipeline_tests(runner);
    register_routing_sync_pipeline_tests(runner);
    register_slashing_governance_pipeline_tests(runner);
}