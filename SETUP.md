# Setup Guide - Student Management System

Follow these steps to set up the project locally on your machine.

## Prerequisites

You need:
- **Git** - Version control (`git --version` to check)
- **GCC** - C compiler (`gcc --version` to check)
- **Make** - Build tool (`make --version` to check)
- **CLion** (optional) - IDE for C development, OR any text editor

### macOS
```bash
# If you don't have Homebrew, install it first
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install required tools
brew install gcc make
```

### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install build-essential git
```

### Windows
- Download Git: https://git-scm.com/download/win
- Download MinGW (includes GCC & Make): https://www.mingw-w64.org/

## Step 1: Clone the Repository

```bash
# Clone the repo
git clone https://github.com/dharanigowthamsampath/student-management.git
cd student-management
```

## Step 2: Verify Setup

Test that everything is installed:

```bash
# Test if GCC works
gcc --version

# Test if Make works
make --version

# Test if Git works
git --version
```

## Step 3: Build and Test

Compile the project:

```bash
# Clean old builds
make clean

# Build test suite
make test
```

You should see output like:
```
gcc -Wall -Wextra -std=c99 -o build/test_runner test/test.c src/student.c -lm
./build/test_runner
========================================
Issue #1: add_student Tests
========================================
...
Test Results:
  Passed: 0
  Failed: 9
```

**If you see this, setup is complete!** ✅

## Step 4: Open in IDE (CLion)

1. Open CLion
2. **File** → **Open** → Select the `student-management` folder
3. CLion will automatically recognize the CMakeLists.txt
4. Wait for indexing to complete

Alternatively, use any text editor:
- VS Code
- Sublime Text
- Vim/Nano

---

**Next:** Read [WORKFLOW.md](WORKFLOW.md) to start solving issues!
