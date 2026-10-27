# 86-signedness-api-issue.sh

Checks PR #86: `Thresholder.threshold_uV` is `int32` and wire-compatible with the old `uint32`. Needs only `protoc`; `--device` is accepted and ignored.

- **L1-11** — header; argv (`--device <ip>` accepted, ignored).
- **L12-15** — protoc check, temp dir for the old schema, `fail` helper.
- **L17-20** — the field is `int32`; every proto compiles with `--fatal_warnings`.
- **L22-26** — rebuilds the pre-PR `uint32` schema; `enc`/`dec` helpers via `protoc --encode/--decode`.
- **L28-33** — old `uint32` encoder → new `int32` decoder: 1, 50, 1000, 2^31-1 decode unchanged.
- **L35-38** — a negative threshold (-400) round-trips under the new schema.
- **L39** — overall PASS.
