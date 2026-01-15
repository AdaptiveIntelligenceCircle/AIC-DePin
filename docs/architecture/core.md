# Core Architecture

The `core/` layer defines how a node *exists*, *behaves*, and *earns trust*.

It does not handle networking or consensus.
It defines **responsibility**.

## Core Components

### Node

- Represents a running participant in the system.
- Has a lifecycle: INIT → ACTIVE → DEGRADED → QUARANTINED → EXPELLED.
- Does not decide its own trust.

### Policy

- Encodes behavioral rules.
- Policies are not configuration files.
- Policies express *what is allowed*, not *what is convenient*.

### Resource

- Represents real, measurable capacity (CPU, memory, bandwidth).
- No virtual staking.
- No synthetic tokens.

### Trust

- The central control signal of the system.
- Updated only through observed behavior.
- Decays over time.
- Can be slashed, reduced, or collapsed.

## Non-Responsibilities

The core layer must never:
- Route messages
- Discover peers
- Make consensus decisions
- Interact directly with humans

This separation is intentional to prevent privilege accumulation.
