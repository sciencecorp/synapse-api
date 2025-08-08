# Synapse API 2.0.0

The Synapse Protocol defines a standard interface for interacting with a wide range of possible neural interface devices.

Synapse uses gRPC for its control plane API and Taps for streaming data. Read the full Synapse protocol docs [here](https://science.xyz/docs/d/synapse/index).

# Python Installation

You can install the official [Synapse Python client library](https://github.com/sciencecorp/synapse-python) using:

`pip install science-synapse`

# Other Installation

You can use these protobufs in any language supported by gRPC, but we highly encourage you to use one of our existing clients in Python, C++, or TS/Node because they wrap it and add additional utilities.
