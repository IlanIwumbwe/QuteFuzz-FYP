#!/bin/bash

IMAGE_NAME="qutefuzz:latest"

docker run -it --rm -v $(pwd)/nightly_results:/app/nightly_results $IMAGE_NAME \
    uv run scripts/run.py "$@"
