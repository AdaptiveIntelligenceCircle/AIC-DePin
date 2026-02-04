# AIC-DePin
Enhance decentralized infrastructure for AI. 

<p align="center">
  <img src="assets/AIC-DePin.png" alt="AIC Logo" width="1024" length = "1024"/>
</p>

<p align="center">
  <strong> AIC-DePin </strong><br>
  Decentralized nodes • Ethical scaling • Planetary readiness
</p>

## Phase 2: Core Architecture & Execution Layer

### 1. Phase 2 Objectives

This phase transforms AIC-DePIN from a **concept + repo structure** to a **runnable, simulated, and scalable system**:

* Minimum runnable DePIN node
* Staking/trust/resource accounting mechanism
* Simulation before actual deployment
* Cloud/big infrastructure independence

---

### 2. Overall Architecture (Revised)

```
AIC-DePIN/
├── core/              # Nhân hệ thống, chạy trên mọi node
│   ├── node_engine/
│   ├── trust_engine/
│   ├── resource_engine/
│   └── policy_engine/
│
├── network/           # Giao tiếp P2P
│   ├── discovery/
│   ├── routing/
│   ├── sync/
│   └── aicp/
│
├── consensus/         # Không blockchain-heavy
│   ├── reputation_consensus/
│   ├── task_validation/
│   └── quorum_logic/
│
├── depin/             # DePIN-specific logic
│   ├── resource_types/
│   ├── staking/
│   ├── incentive/
│   └── slashing/
│
├── simulation/        # Human-in-the-loop + agent sim
│   ├── sandbox/
│   ├── adversary/
│   └── replay/
│
├── extensions/        # Plugin: hardware, human, org
│   ├── hardware/
│   ├── human_interface/
│   └── org_interface/
│
└── tools/
    ├── cli/
    ├── monitor/
    └── debugger/
```

---

### 3. Core Engines

#### 3.1 Node Engine (`core/node_engine`)

**Role:** of a DePIN node runtime

* Lifecycle: join → evaluate → serve → earn → decay

* Not a miner, but a **responsible agent**

Files:

* `node.h / node.cpp`
* `node_state.h`
* `heartbeat.cpp`

Key states:

* ACTIVE
* DEGRADED
* QUARANTINED
* EXPELLED

---

#### 3.2 Trust Engine (`core/trust_engine`)

**Trust ≠ stake**

Trust = vector:

* behavior consistency
* task accuracy
* latency honesty
* human feedback

Files:

* `trust_score.h`
* `trust_update.cpp`
* `trust_decay.cpp`

Trust update = Bayesian + decay + anomaly penalty

---

#### 3.3 Resource Engine (`core/resource_engine`)

Manage real resources, not simulated tokens.

Resource abstraction:

* CPU time
* Storage
* Bandwidth
* Sensor / actuator

Files:

* `resource_descriptor.h`
* `resource_meter.cpp`
* `resource_commitment.cpp`

---

### 4. DePIN Logic Layer

#### 4.1 Resource Types (`depin/resource_types`)

Each resource is a plugin:

* `compute_resource`
* `storage_resource`
* `relay_resource`

Can add:

* human attention
* physical presence

---

#### 4.2 Staking (`depin/staking`)

Stake doesn't necessarily have to be a token:

* reputation stake
* time lock
* hardware bond

Files:

* `stake_contract.h`
* `stake_manager.cpp`

---

#### 4.3 Incentive (`depin/incentive`)

Rewards are more than just money:

* increased priority
* governance weight
* trust boost

Files:

* `reward_policy.h`
* `reward_engine.cpp`

---

#### 4.4 Slashing (`depin/slashing`)

Slashing = rollback + exclusion + trust collapse

Files:

* `slashing_rule.h`
* `slashing_executor.cpp`

---

### 5. Consensus (Lightweight)

No traditional PoW/PoS is used.

#### Reputation Quorum

* quorum theo trust-weighted vote
* reject Byzantine cluster

Files:

* `quorum.h`
* `vote_aggregation.cpp`

---

### 6. Simulation First

#### 6.1 Sandbox (`simulation/sandbox`)

Run:

* fake nodes
* fake tasks
* malicious strategies

Files:

* `sandbox_runner.cpp`
* `scenario.lua`

#### 6.2 Adversary (`simulation/adversary`)

Simulate:

* collusion
* sybil
* latency cheating

---

### 7. Extensions

#### 7.1 Human Interface

Allowed:

* human approve task
* dispute resolution
* ethical override

#### 7.2 Hardware Interface

* IoT
* edge device
* sensor network

---

### 8. The invariant principles of AIC-DePIN

1. Trust > Token
2. Behavior > Hashrate
3. Simulation before deployment
4. Human is part of the loop
5. Exit is allowed, attack is not

---

### 9. Next Immediate Steps (Concrete)

**Step 1:** Implement minimal runnable node

* node_engine + trust_engine stub

**Step 2:** Single-resource DePIN

* compute resource only

**Step 3:** 5-node local simulation

* honest + malicious

**Step 4:** Publish testnet-spec (no token)

---

> AIC-DePIN is not aimed at winning the crypto market.

> It aims to create an infrastructure that **cannot be easily manipulated**.