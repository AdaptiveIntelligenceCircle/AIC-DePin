# Rollback Policy

Rollback is a governance action, not an automated panic reaction.

## Rollback Allowed When
- replay diff indicates policy bug
- consensus fragmentation detected
- mass slashing cascade triggered

## Rollback Forbidden When
- rollback destroys evidence integrity
- rollback is used to hide governance capture

Rollback must preserve:
- event log chain
- dispute records
- human approval decisions