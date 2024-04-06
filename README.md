# Lua Dialects Playground 🛝

## Building
On macOS, run the following script first to install dependencies and set up env variables:
```bash
brew install cmake llvm
export SDKROOT="$(xcrun --sdk macosx --show-sdk-path)"
```
And then use CMake:
```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=/llvm/install/path
cmake --build build
```