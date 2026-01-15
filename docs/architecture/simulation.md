# Simulation Architecture

Simulation is not a testing accessory.
It is a **first-class architectural requirement**.

## Sandbox

- Executes nodes in controlled, adversarial conditions.
- Injects faulty, malicious, or irrational behavior.
- Does not decide correctness.

## Replay

- Records immutable event logs.
- Reconstructs historical system states.
- Enables forensic analysis and accountability.

## Why Simulation Is Mandatory

Traditional systems assume correctness first and debug later.
AIC-DePIN assumes failure first and proves resilience.

No feature is considered valid unless:
- It can be simulated
- It can be replayed
- Its failure modes are understood
