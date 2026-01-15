# AIC-DePIN Security Documentation

This directory describes the security model of AIC-DePIN.
Security in AIC-DePIN is not treated as a feature, but as a system-wide behavior
emerging from architecture, trust assumptions, and adversarial simulation.

Unlike traditional DePIN systems, AIC-DePIN assumes:
- Nodes can be compromised
- Consensus can be manipulated
- Identities can be forged
- Incentives can be gamed

The goal is not perfect security, but **bounded damage, recoverability, and behavioral containment**.

## Scope
This documentation covers:
- Threat models
- Adversary models
- Trust assumptions
- Attack surfaces
- Mitigation strategies
- Simulation-driven security validation
