#include "../harness/test_harness.h"
#include "../harness/test_runner.h"
#include <string>
#include <vector>

namespace aic::tests::integration {

enum class RouteDecision {
    ALLOW,
    DENY
};

enum class SyncResult {
    APPLIED,
    FAILED
};

struct FakeRoutePolicy {
    RouteDecision evaluate(const std::string& from, const std::string& to) const {
        if (to == "blocked_peer") return RouteDecision::DENY;
        return RouteDecision::ALLOW;
    }
};

struct FakeStateDiff {
    std::vector<std::string> changes;
};

struct FakeSyncEngine {
    SyncResult applyDiff(const FakeStateDiff& diff) {
        if (diff.changes.empty())
            return SyncResult::FAILED;

        applied_changes.insert(applied_changes.end(),
                               diff.changes.begin(),
                               diff.changes.end());
        return SyncResult::APPLIED;
    }

    std::vector<std::string> applied_changes;
};

struct FakeRouter {
    FakeRouter(FakeRoutePolicy p) : policy(std::move(p)) {}

    bool canRoute(const std::string& from, const std::string& to) const {
        return policy.evaluate(from, to) == RouteDecision::ALLOW;
    }

private:
    FakeRoutePolicy policy;
};

void test_routing_sync_pipeline_route_deny_sync_fail() {
    FakeRouter router(FakeRoutePolicy{});
    FakeSyncEngine sync;

    bool routed = router.canRoute("nodeA", "blocked_peer");
    AIC_ASSERT_FALSE(routed);

    FakeStateDiff diff;
    diff.changes = {"k1=updated"};

    if (!routed) {
        auto result = SyncResult::FAILED;
        AIC_ASSERT_EQ(result, SyncResult::FAILED);
        AIC_ASSERT_EQ(sync.applied_changes.size(), (size_t)0);
        return;
    }

    auto result = sync.applyDiff(diff);
    AIC_ASSERT_EQ(result, SyncResult::FAILED);
}

void test_routing_sync_pipeline_route_allow_sync_apply() {
    FakeRouter router(FakeRoutePolicy{});
    FakeSyncEngine sync;

    bool routed = router.canRoute("nodeA", "peerB");
    AIC_ASSERT_TRUE(routed);

    FakeStateDiff diff;
    diff.changes = {"quota=10", "stake=5"};

    auto result = sync.applyDiff(diff);

    AIC_ASSERT_EQ(result, SyncResult::APPLIED);
    AIC_ASSERT_EQ(sync.applied_changes.size(), (size_t)2);
}

} // namespace aic::tests::integration

void register_routing_sync_pipeline_tests(aic::tests::TestRunner& runner) {
    using namespace aic::tests::integration;

    runner.add("integration.routing_sync.route_deny_sync_fail",
               test_routing_sync_pipeline_route_deny_sync_fail);

    runner.add("integration.routing_sync.route_allow_sync_apply",
               test_routing_sync_pipeline_route_allow_sync_apply);
}