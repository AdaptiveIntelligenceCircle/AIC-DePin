# Sandbox Design

The sandbox is an isolated execution environment
used to observe behavior without causing irreversible impact.

## Goals
- Contain unsafe behavior
- Observe decision patterns
- Test policy and trust reactions
- Allow failure without damage

## Properties
- Deterministic execution (when replayed)
- Resource constraints
- Instrumented state transitions
- No implicit trust

## Sandbox Scope
- Node logic
- Policy evaluation
- Routing decisions
- Trust updates

The sandbox is not a toy environment.
It is a controlled mirror of reality.
