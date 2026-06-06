# rrtstar_dubins

A small Qt-based demo implementing RRT* with Dubins paths.

Prerequisites
- CMake >= 3.21
- A C++ compiler with C++14 support (g++/clang++)
- Qt5 development packages (Core, Gui, Widgets) and Qt tools (e.g., qtbase5-dev on Debian/Ubuntu)
- make

Quick build
1. Ensure prerequisites are installed (example on Debian/Ubuntu):
   sudo apt update && sudo apt install build-essential cmake qtbase5-dev qttools5-dev-tools
2. Make the build script executable and run it:
   chmod +x build.sh
   ./build.sh
3. Run the built application:
   ./build/rrt-app

Notes & troubleshooting
- If CMake reports a cache/source mismatch, delete the build directory and retry:
   rm -rf build
   ./build.sh
- build/ is ignored by the repository (.gitignore). Local build artifacts remain on your machine but are not committed.
- The build script uses `make -j` (unbounded). To limit parallelism, edit build.sh and use `make -j$(nproc)`.
- Warnings about deprecated QLineF::intersect appear during compilation; they are non-fatal but can be updated to use `intersects()`.

Contributing
- Fork, create a branch, make changes, and open a pull request.

License
- See repository for license information (not included in this README).

Contact
- Maintainer: phatcvo
