#!/bin/bash

# Exit immediately on error
set -e

echo "🔄 Cleaning previous build..."
rm -rf build

echo "📁 Creating build directory..."
mkdir build
cd build

echo "⚙️ Running CMake configuration..."
cmake .. -DCMAKE_VERBOSE_MAKEFILE=ON

echo "🚧 Building project..."
cmake --build .

echo "✅ Build complete!"
