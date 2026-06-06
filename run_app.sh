#!/bin/bash
# Launcher for rrt-app: builds if necessary and runs the Qt app.
set -e

if [ ! -x "./build/rrt-app" ]; then
  if [ ! -d "build" ]; then
    echo "No build found. Running build.sh..."
    chmod +x build.sh
    ./build.sh
  else
    echo "Build exists but executable missing. Rebuilding..."
    chmod +x build.sh
    ./build.sh
  fi
fi

echo "Launching rrt-app. Click and drag with the left mouse button to draw rectangular obstacles (press -> drag -> release)."
./build/rrt-app
