# Tools Architecture

Tools in AIC-DePIN do not control the system.
They expose it.

## CLI

- Operator and researcher interface.
- Executes observable commands.
- Cannot bypass policy or trust.

## Debugger

- Inspects behavioral and trust conditions.
- Supports breakpoints on system state.
- Cannot mutate state directly.

## Monitors

- Passive observation of trust, resource, and network health.
- No automated intervention.
- Designed for long-term drift detection.

## Principle

> Tools may observe everything, but control nothing.
