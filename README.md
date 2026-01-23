# AIC-DePin
Enhance decentralized infrastructure for AI. 

<p align="center">
  <img src="assets/AIC-DePin.png" alt="AIC Logo" width="1024" length = "1024"/>
</p>

<p align="center">
  <strong> Human Meaning Network </strong><br>
  Decentralized nodes • Ethical scaling • Planetary readiness
</p>

## Phase 2: Core Architecture & Execution Layer

### 1. Mục tiêu Phase 2

Phase này chuyển AIC-DePIN từ **concept + repo structure** sang **hệ thống có thể chạy, mô phỏng và mở rộng**:

* Có node DePIN tối thiểu chạy được
* Có cơ chế staking / trust / resource accounting
* Có simulation trước khi deploy thực
* Không phụ thuộc cloud / big infra

---

### 2. Kiến trúc tổng thể (Revised)

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

**Vai trò:** runtime của một DePIN node

* lifecycle: join → evaluate → serve → earn → decay
* không phải miner, là **agent có trách nhiệm**

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

Quản lý tài nguyên **thực**, không giả lập token

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

Mỗi resource là plugin:

* `compute_resource`
* `storage_resource`
* `relay_resource`

Có thể thêm:

* human attention
* physical presence

---

#### 4.2 Staking (`depin/staking`)

Stake không nhất thiết là token:

* reputation stake
* time lock
* hardware bond

Files:

* `stake_contract.h`
* `stake_manager.cpp`

---

#### 4.3 Incentive (`depin/incentive`)

Reward không chỉ là tiền:

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

Không dùng PoW / PoS truyền thống.

#### Reputation Quorum

* quorum theo trust-weighted vote
* reject Byzantine cluster

Files:

* `quorum.h`
* `vote_aggregation.cpp`

---

### 6. Simulation First

#### 6.1 Sandbox (`simulation/sandbox`)

Chạy:

* fake nodes
* fake tasks
* malicious strategies

Files:

* `sandbox_runner.cpp`
* `scenario.lua`

#### 6.2 Adversary (`simulation/adversary`)

Mô phỏng:

* collusion
* sybil
* latency cheating

---

### 7. Extensions

#### 7.1 Human Interface

Cho phép:

* human approve task
* dispute resolution
* ethical override

#### 7.2 Hardware Interface

* IoT
* edge device
* sensor network

---

### 8. Nguyên tắc bất biến của AIC-DePIN

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

> AIC-DePIN không nhằm thắng crypto market.
> Nó nhằm tạo một lớp hạ tầng **không thể bị thao túng dễ dàng**.
