# Synapse API 1.0

The Synapse Protocol defines a standard interface for interacting with a wide range of possible neural interface devices.

Synapse uses gRPC for its control plane API and UDP for streaming data. Read the full Synapse protocol docs [here](science.xyz/docs/d/synapse/index).

# Python Installation

Before installing the Synapse Python client library, you will need:

- Python version 3.9 or later.
- pip version 23 or later.

You can install the official Synapse Python client library using:

`pip install science-synapse`

# Other Installation

You can use these protobufs in any language supported by gRPC, but we highly encourage you to use one of our existing clients in Python, C++, or TS/Node because they wrap it and add additional utilities.
