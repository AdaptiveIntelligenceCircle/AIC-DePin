#include "../harness/test_harness.h"
#include "../harness/test_runner.h"
#include <string>

namespace aic::tests::integration {

enum class PenaltyDecision {
    APPLY,
    BLOCKED_BY_VETO,
    NO_PENALTY
};

struct FakeEvidence {
    std::string offender;
    std::string reason;
    double severity = 0.0;
};

struct FakeSlashingEngine {
    FakeEvidence generateEvidence(const std::string& node_id) const {
        FakeEvidence ev;
        ev.offender = node_id;
        ev.reason = "latency_cheating";
        ev.severity = 0.8;
        return ev;
    }
};

struct FakeGovernanceVeto {
    bool shouldVeto(const FakeEvidence& ev) const {
        // Governance veto example rule:
        // veto if evidence is weak or politically sensitive.
        if (ev.severity < 0.5)
            return true;

        // simulate veto for protected node (example)
        if (ev.offender == "protected_node")
            return true;

        return false;
    }
};

struct FakePenaltyModel {
    PenaltyDecision decide(
        const FakeEvidence& ev,
        const FakeGovernanceVeto& veto
    ) const {
        if (veto.shouldVeto(ev))
            return PenaltyDecision::BLOCKED_BY_VETO;

        if (ev.severity >= 0.7)
            return PenaltyDecision::APPLY;

        return PenaltyDecision::NO_PENALTY;
    }
};

void test_slashing_governance_pipeline_evidence_created() {
    FakeSlashingEngine slashing;
    auto ev = slashing.generateEvidence("bad_node");

    AIC_ASSERT_EQ(ev.offender, std::string("bad_node"));
    AIC_ASSERT_TRUE(ev.severity > 0.0);
    AIC_ASSERT_EQ(ev.reason, std::string("latency_cheating"));
}

void test_slashing_governance_pipeline_veto_blocks_penalty() {
    FakeSlashingEngine slashing;
    FakeGovernanceVeto veto;
    FakePenaltyModel penalty;

    auto ev = slashing.generateEvidence("protected_node");
    auto decision = penalty.decide(ev, veto);

    AIC_ASSERT_EQ(decision, PenaltyDecision::BLOCKED_BY_VETO);
}

void test_slashing_governance_pipeline_apply_penalty_if_no_veto() {
    FakeSlashingEngine slashing;
    FakeGovernanceVeto veto;
    FakePenaltyModel penalty;

    auto ev = slashing.generateEvidence("bad_node");
    auto decision = penalty.decide(ev, veto);

    AIC_ASSERT_EQ(decision, PenaltyDecision::APPLY);
}

} // namespace aic::tests::integration

void register_slashing_governance_pipeline_tests(aic::tests::TestRunner& runner) {
    using namespace aic::tests::integration;

    runner.add("integration.slashing_governance.evidence_created",
               test_slashing_governance_pipeline_evidence_created);

    runner.add("integration.slashing_governance.veto_blocks_penalty",
               test_slashing_governance_pipeline_veto_blocks_penalty);

    runner.add("integration.slashing_governance.apply_penalty_if_no_veto",
               test_slashing_governance_pipeline_apply_penalty_if_no_veto);
}