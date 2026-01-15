# Network Architecture

The network layer enables communication without assuming trust.

AIC-DePIN networking is **peer-to-peer, decentralized, and adversarial-aware**.

## Subsystems

### Discovery

- Finds potential peers.
- Never assigns trust.
- Treats all discovered nodes as untrusted candidates.

### Protocol

- Defines message formats and validation rules.
- Does not decide routing.
- Does not decide state correctness.

### Routing

- Forwards messages across the network.
- Enforces diversity and anti-eclipse policies.
- Has no visibility into message semantics.

### Sync

- Exchanges state deltas, not full state.
- Does not resolve conflicts.
- Does not enforce correctness.

## Key Constraint

> The network layer must be replaceable without rewriting the core.

This allows:
- Simulation of hostile networks
- Operation in disconnected or degraded environments
- Long-term survivability
