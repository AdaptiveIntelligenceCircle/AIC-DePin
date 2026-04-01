#include "../harness/test_harness.h"
#include "../harness/test_runner.h"

#include <string> 
using namespace std; 

namespace aic :: tests :: intergration 
{
    enum class QuorumDecision 
    {
        ACCEPT, 
        REJECT 
    };

    struct FakeTrustEngine 
    {
        double trustScore(const string &node_id)  const 
        {
            if (node_id == "bad_node") return 0.2;
            if (node_id == "good_node") return 0.85; 
            return 0.5; 
        }
    }; 

    struct FakeQuorumPolicy
    {
        double threshold = 0.6; 

        QuorumDecision evaluate(double trust_score) const 
        {
            return trust_score >= threshold? 
            QuorumDecision :: ACCEPT : 
            QuorumDecision :: REJECT; 
        }
    };

    void test_consensus_trust_pipeline_low_trust_reject()
    {
        FakeTrustEngine trust; 
        FakeQuorumPolicy quorum; 

        double score = trust.trustScore("bad node");
        auto decision = quorum.evaluate(score); 

        AIC_ASSERT_EQ(decision, QuorumDecision :: REJECT); 
    }

    void test_consensus_trust_pipeline_high_trust_accept()
    {
        FakeTrustEngine trust; 
        FakeQuorumPolicy quorum; 

        double score  = trust.trustScore("good node"); 
        auto decision = quorum.evaluate(score); 

        AIC_ASSERT_EQ(decision, QuorumDecision:: ACCEPT);
    }
}