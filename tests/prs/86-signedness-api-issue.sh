#!/usr/bin/env bash
# Verifies synapse-api PR #86: Thresholder.threshold_uV is a signed int32 (sign = direction)
# and stays wire-compatible with the old uint32 for every existing non-negative value.
# Needs only protoc. --device <ip> is accepted and ignored (nothing here touches hardware).
set -euo pipefail
while [[ $# -gt 0 ]]; do
    case "$1" in
        --device) shift 2 || true ;;
        *) echo "usage: $0 [--device <ip>]" >&2; exit 2 ;;
    esac
done
command -v protoc >/dev/null || { echo "FAIL: protoc not installed"; exit 1; }
SRC="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
OLD="$(mktemp -d)"; trap 'rm -rf "$OLD"' EXIT
fail() { echo "FAIL: $*"; exit 1; }

# 1. the field is int32 now, and every proto still compiles
grep -Eq '^\s*int32 threshold_uV = 1;' "$SRC/api/nodes/spike_detector.proto" || fail "threshold_uV is not int32"
(cd "$SRC" && protoc --proto_path=. $(find api -name '*.proto') -o /dev/null --fatal_warnings) || fail "protos do not compile"
echo "PASS: threshold_uV is int32 and all protos compile"

# 2. the old uint32 schema, as shipped before this PR
mkdir -p "$OLD/api/nodes"
sed 's/^\(\s*\)int32 threshold_uV = 1;/\1uint32 threshold_uV = 1;/' "$SRC/api/nodes/spike_detector.proto" > "$OLD/api/nodes/spike_detector.proto"
enc() { (cd "$1" && printf 'threshold_uV: %s\n' "$2" | protoc --proto_path=. api/nodes/spike_detector.proto --encode=synapse.Thresholder); }
dec() { (cd "$1" && protoc --proto_path=. api/nodes/spike_detector.proto --decode=synapse.Thresholder); }

# 3. old encoder -> new decoder: existing configs decode to the same value
for v in 1 50 1000 2147483647; do
    got="$(enc "$OLD" "$v" | dec "$SRC")"
    [[ "$got" == "threshold_uV: $v" ]] || fail "old uint32 $v decoded as '$got'"
done
echo "PASS: old uint32 values 1..2^31-1 decode unchanged under int32"

# 4. new encoder -> new decoder: a negative threshold round-trips
got="$(enc "$SRC" -400 | dec "$SRC")"
[[ "$got" == "threshold_uV: -400" ]] || fail "-400 round-tripped as '$got'"
echo "PASS: negative threshold -400 round-trips"
echo "PASS: PR #86"
