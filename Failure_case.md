# Failure Cases (AIC-DePin)

This document enumerates realistic failure modes of AIC-DePin.
It is not a pessimistic document.
It is a trust-building artifact: we explicitly list what can go wrong,
how it manifests, how it is detected, and how we respond.

AIC-DePin treats failures as inevitable.
The system must be designed to survive failure without becoming unethical,
authoritarian, or irreversibly corrupted.

---

## Core Principles

1. **Failure must be observable**
   - No silent corruption is acceptable.

2. **Failure must be replayable**
   - Every critical decision should be reconstructible.

3. **Failure must be reversible when possible**
   - Rollback and recovery are first-class mechanisms.

4. **Failure must not justify authoritarian escalation**
   - Emergency powers must be bounded and accountable.

5. **Humans must remain capable of intervention**
   - Human approval, ethical override, and dispute resolution are mandatory.

---

## Failure Categories

- Consensus Failures
- Trust & Reputation Failures
- Slashing & Incentive Failures
- Network Failures
- Resource Accounting Failures
- Governance Failures
- Simulation & Replay Failures
- Human-in-the-loop Failures
- Ethical Failures

---

# 1. Consensus Failures

## 1.1 Quorum Capture (Collusion Majority)
**Description**
A group of nodes coordinates to dominate quorum outcomes.

**Symptoms**
- Repeated approvals with low diversity
- Voting entropy drops sharply
- Honest minority votes consistently ignored

**Detection Signals**
- High vote correlation across identities
- Trust graph clustering
- Replay shows identical decision paths

**Impact**
- Incorrect validation of tasks
- Reward theft
- Governance manipulation

**Response**
- Raise quorum threshold temporarily
- Trigger dispute_resolution workflow
- Reduce weight of correlated cluster
- Force human approval for sensitive actions

**Long-Term Fix**
- Correlation-aware quorum policy
- Reputation decay tied to coordinated behavior

---

## 1.2 Quorum Fragmentation (Network Partition)
**Description**
Network partitions create multiple independent quorums.

**Symptoms**
- Conflicting decisions between regions
- Sync divergence
- Multiple "truth states"

**Detection Signals**
- Sync engine reports repeated diff conflicts
- Routing table divergence

**Impact**
- Double rewards
- Conflicting slashing outcomes
- Broken global fairness

**Response**
- Freeze incentives until sync convergence
- Activate safe-mode quorum policy
- Apply rollback policy if divergence exceeds threshold

---

# 2. Trust & Reputation Failures

## 2.1 Sybil Trust Inflation
**Description**
Adversary spawns identities that slowly build trust together.

**Symptoms**
- Many new nodes rise in trust simultaneously
- Similar behavioral signatures

**Detection Signals**
- Replay clustering detects similarity
- Reputation decay fails to separate identities
- Resource usage correlation across identities

**Impact**
- Quorum manipulation
- Resource hoarding
- Incentive drain

**Response**
- Apply trust dampening to new clusters
- Cap influence of low-age identities
- Require stronger proofs for physical presence

---

## 2.2 Reputation Lock-In (Unfair Permanent Stigma)
**Description**
A node receives a reputation collapse and can never recover.

**Symptoms**
- Reputation remains near-zero despite consistent good behavior

**Detection Signals**
- Reputation decay curve never converges upward
- Appeal processes repeatedly rejected without evidence

**Impact**
- Honest nodes leave
- Centralization pressure

**Response**
- Trigger human review
- Apply recovery curve policy
- Allow staged reputation rehabilitation

---

# 3. Slashing & Incentive Failures

## 3.1 Over-Slashing (Punishment Cascade)
**Description**
Slashing triggers repeatedly due to noisy evidence or policy bug.

**Symptoms**
- Sudden mass penalties
- Many nodes enter suspended state

**Detection Signals**
- Spike in slashing_event frequency
- Evidence quality low or identical

**Impact**
- Ecosystem collapse
- Trust erosion
- Governance panic

**Response**
- Activate ethical override: halt slashing
- Force dispute_resolution review
- Apply rollback to last stable state

---

## 3.2 Incentive Farming (Reward Without Contribution)
**Description**
Nodes exploit reward loopholes.

**Symptoms**
- High reward with low resource output
- Short-lived participation patterns

**Detection Signals**
- Contribution score mismatch with resource usage tracker
- Replay shows repeated micro-actions designed to trigger reward

**Impact**
- Inflation of reward budget
- Loss of honest participation

**Response**
- Patch reward policy (quality > quantity)
- Apply decay model aggressively
- Retroactive penalty if exploit is intentional

---

# 4. Network Failures

## 4.1 Routing Poisoning
**Description**
Nodes advertise fake routes to redirect traffic.

**Symptoms**
- Increased latency
- Packet drops
- Sync failures

**Detection Signals**
- Routing table instability
- Trust drop correlated with route changes

**Impact**
- Partition creation
- Denial-of-service

**Response**
- Policy-based route rejection
- Trust-weighted routing fallback
- Quarantine suspicious relays

---

## 4.2 Latency Cheating
**Description**
Adversary manipulates response timing to bypass validation.

**Symptoms**
- Responses arrive consistently near timeout boundary
- Selective participation

**Detection Signals**
- High conditional latency correlation
- Replay reveals timing exploitation

**Impact**
- Consensus manipulation
- Task validation distortion

**Response**
- Apply timing normalization
- Penalize suspicious timing patterns
- Require multi-path confirmation

---

# 5. Resource Accounting Failures

## 5.1 Resource Double-Spending (Allocation Drift)
**Description**
A node reports allocation that is not reflected in actual usage.

**Symptoms**
- Allocation > quota
- Storage/relay usage mismatch

**Detection Signals**
- Usage tracker inconsistencies
- Sync diffs conflicting

**Impact**
- Resource hoarding
- Incentive abuse

**Response**
- Freeze rewards
- Trigger audit replay
- Apply slashing only if evidence passes threshold

---

## 5.2 Fake Physical Presence
**Description**
Node claims physical presence without real proof.

**Symptoms**
- Presence proofs repeated or identical
- Presence claims inconsistent with network topology

**Detection Signals**
- Proof reuse patterns
- Multi-witness mismatch

**Impact**
- Geographic trust collapse
- Governance corruption

**Response**
- High severity slashing
- Require human approval
- Permanent ban if repeated

---

# 6. Governance Failures

## 6.1 Governance Capture
**Description**
A coordinated group dominates governance votes.

**Symptoms**
- Sudden policy changes benefiting a cluster
- Veto used strategically

**Detection Signals**
- Vote correlation
- Reputation rise in same group

**Impact**
- System becomes cartel-driven
- Ethical breakdown

**Response**
- Trigger ethical override
- Emergency governance freeze
- Human council intervention
- Publish forensic replay

---

## 6.2 Emergency Powers Abuse
**Description**
Emergency override becomes a permanent dictatorship mechanism.

**Symptoms**
- Override invoked frequently
- Policies become non-reversible

**Detection Signals**
- Override frequency spikes
- Lack of postmortems

**Impact**
- Loss of legitimacy
- Community collapse

**Response**
- Hard-limit emergency override usage
- Mandatory public postmortem
- Automatic expiration of emergency policies

---

# 7. Replay & Simulation Failures

## 7.1 Non-Deterministic Replay
**Description**
Replay produces different outcomes each run.

**Symptoms**
- Replay diff changes unexpectedly
- Forensic results inconsistent

**Detection Signals**
- Hash mismatch across runs
- Cursor boundaries unstable

**Impact**
- Dispute resolution becomes impossible
- Governance becomes subjective

**Response**
- Freeze replay usage for governance decisions
- Require deterministic seeds
- Enforce event ordering constraints

---

## 7.2 Replay Tampering
**Description**
Logs are modified or selectively deleted.

**Symptoms**
- Missing event IDs
- Hash chain breaks

**Detection Signals**
- Integrity checks fail
- Sequence discontinuities

**Impact**
- Evidence cannot be trusted

**Response**
- Immediate quarantine of node
- Force multi-party log reconstruction
- Slashing with maximum severity if proven intentional

---

# 8. Human-in-the-loop Failures

## 8.1 Human Approval Bottleneck
**Description**
Human approvals become a throughput bottleneck.

**Symptoms**
- Too many pending approvals
- System stalls on critical operations

**Detection Signals**
- Queue length increasing
- Time-to-decision rising

**Impact**
- System becomes unusable
- Incentive collapse

**Response**
- Restrict approvals to high-risk actions only
- Create tiered human roles
- Enable temporary automated fallback policy

---

## 8.2 Corrupt Human Reviewer
**Description**
Human reviewer accepts bribes or acts maliciously.

**Symptoms**
- Approvals inconsistent with evidence
- Overrides benefit a specific cluster

**Detection Signals**
- Replay diff between reviewer decisions and policy baseline
- Anomaly in reviewer behavior

**Impact**
- Ethical failure
- Governance legitimacy collapse

**Response**
- Multi-review requirement
- Reviewer reputation tracking
- Forced transparency and audit

---

# 9. Ethical Failures

## 9.1 Rewarding Harmful Behavior
**Description**
The incentive engine rewards behavior that damages society.

**Symptoms**
- Exploitative tasks prioritized
- Resource usage patterns correlate with harmful outcomes

**Detection Signals**
- Ethical override triggers repeatedly
- Community reports increase

**Impact**
- AIC-DePin becomes harmful infrastructure

**Response**
- Freeze incentives for task type
- Mandatory human approval
- Public disclosure and review

---

## 9.2 Slashing as Weaponization
**Description**
Slashing is used as a tool of political suppression.

**Symptoms**
- Slashing targets dissenting nodes
- Evidence quality degrades

**Detection Signals**
- Dispute rate spikes
- Slashing correlation with governance conflicts

**Impact**
- Authoritarian failure mode
- Loss of trust

**Response**
- Disable slashing temporarily
- Require multi-party evidence
- Introduce veto safeguards

---

# Exit Conditions

AIC-DePin must define when the system should stop operating rather than continue in corruption.

If any of the following occurs:
- replay integrity cannot be restored
- governance capture is confirmed and cannot be reversed
- ethical override is continuously triggered without resolution
- slashing causes mass collapse

then the system must enter **exit mode**:
- halt rewards
- freeze critical actions
- preserve logs
- allow human governance to decide termination or reboot

---

# Final Note

AIC-DePin is not designed to be invincible.
It is designed to be accountable, repairable, and ethically survivable.