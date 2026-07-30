# Getting Started - Complete Student Guide

**Read this file from top to bottom. It covers everything you need to know.**

---

## Table of Contents
1. [Overview](#overview)
2. [Setup (First Time Only)](#setup-first-time-only)
3. [Understanding the Project](#understanding-the-project)
4. [Solving an Issue (Step-by-Step)](#solving-an-issue-step-by-step)
5. [Testing Your Code](#testing-your-code)
6. [Submitting Your Work](#submitting-your-work)
7. [Troubleshooting](#troubleshooting)

---

## Overview

### What Is This Project?

A **Student Management System** in C - a beginner-friendly project to learn:
- ✅ How to write functions
- ✅ How to test code
- ✅ How to use Git & GitHub
- ✅ How professional software teams work

### How It Works

- **120 independent functions** to implement
- **60 students** × **2 issues each** = complete project
- **Each function is separate** - your code doesn't depend on others
- **Auto-testing** - tests run automatically on your submission

### Your Role

You will:
1. Pick an issue assigned to you
2. Fork the repository (create your own copy)
3. Implement the function
4. Test locally
5. Submit a Pull Request (PR)
6. Tests run automatically
7. Maintainer merges your code ✓

---

## Setup (First Time Only)

### Prerequisites

You need three tools. Check if you have them:

```bash
# Check Git
git --version

# Check GCC (C compiler)
gcc --version

# Check Make
make --version
```

**If any are missing:**

**macOS:**
```bash
brew install gcc make
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get install build-essential git
```

**Windows:**
- Git: https://git-scm.com/download/win
- MinGW (GCC + Make): https://www.mingw-w64.org/

### Step 1: Fork the Repository

Go to: https://github.com/dharanigowthamsampath/student-management

Click **"Fork"** button in top-right corner.

This creates YOUR personal copy:
```
https://github.com/YOUR-USERNAME/student-management
```

### Step 2: Clone Your Fork

```bash
git clone https://github.com/YOUR-USERNAME/student-management.git
cd student-management
```

### Step 3: Configure Git (ONE TIME ONLY)

Tell Git who you are:

```bash
git config user.name "Your Full Name"
git config user.email "your-email@example.com"
```

Replace with YOUR actual name and email!

### Step 4: Verify Setup

Test that everything works:

```bash
make clean
make test
```

You should see tests running (they'll fail - that's normal! No functions implemented yet).

**Congrats! Setup is complete.** ✅

---

## Understanding the Project

### Project Structure

```
student-management/
├── src/
│   ├── student.h       (Struct & constants - DON'T MODIFY)
│   └── student.c       (Function stubs - YOU IMPLEMENT HERE)
├── test/
│   └── test.c          (Test cases - DON'T MODIFY)
├── Makefile            (Build instructions)
└── main.c
```

### The Student Struct

All functions work with this structure:

```c
typedef struct {
    int id;                          // Student ID
    char name[50];                   // Full name
    char email[100];                 // Email
    char phone[15];                  // Phone number
    int grade;                       // Grade (0-100)
    char department[50];             // Department
    int year;                        // Year (1-4)
} Student;
```

### Global Database

All functions access this shared data:

```c
Student students[100];   // Array of up to 100 students
int total_students;      // Current count
```

### Function Types

Different functions do different things:

- **CRUD**: Add, delete, get, update students
- **Search**: Find students by ID, name, email, etc.
- **Validation**: Check if email/phone/grade are valid
- **Statistics**: Calculate average, rank, percentile, etc.
- **Sorting**: Sort by grade, name, ID, etc.
- **String Operations**: Uppercase, trim, reverse, etc.

---

## Solving an Issue (Step-by-Step)

### Step 1: Pick Your Issue

Go to: https://github.com/dharanigowthamsampath/student-management/issues

Click on an issue assigned to you (e.g., **Issue #1: Implement add_student()**)

Read the description carefully:
- What function to implement
- What it should do
- Example usage
- Time & Space complexity

### Step 2: Create a Branch

Create a feature branch (never work on main!):

```bash
# Replace X with issue number
git checkout -b issue/X-function-name

# Example:
git checkout -b issue/1-add-student
```

Verify you're on the correct branch:

```bash
git branch
# Should show: * issue/1-add-student
```

### Step 3: Find Your Function

Open `src/student.c` and search for your issue number:

```bash
# macOS/Linux - open in editor
vim src/student.c

# OR use Ctrl+F in your IDE to search for "Issue #1"
```

You'll see something like:

```c
// ========================================
// Issue #1: Implement add_student
// ========================================
// TODO: Add a new student to the database
//
// Requirements:
// - Add the student struct to the global students array
// - Increment total_students counter
// - Return 1 if successful, 0 if array is full
//
int add_student(Student s) {
    // TODO: Implement this function
    return 0;  // Change this
}
```

**Read the TODO comments carefully.** They tell you exactly what to do.

### Step 4: Look at Test Cases

Open `test/test.c` and search for your issue number:

```bash
vim test/test.c
# Search for: Issue #1
```

The test cases show **exactly** what your function should do:

```c
void test_add_student_single() {
    setup();  // Clear database

    // Create test data
    Student s = {1, "John Doe", "john@mail.com", "9999999999", 85, "CS", 2};

    // Call your function
    int result = add_student(s);

    // Verify results
    ASSERT_EQUAL(result, 1, "Should return 1");
    ASSERT_EQUAL(total_students, 1, "Counter should be 1");
}
```

**This test tells you:**
- Input: A Student struct
- Expected output: Return 1, total_students becomes 1
- If your code does this, test passes ✓

### Step 5: Implement the Function

Write your implementation inside the function body:

```c
int add_student(Student s) {
    // Check if database is full
    if (total_students >= 100) {
        return 0;  // Full
    }

    // Add student
    students[total_students] = s;
    total_students++;

    return 1;  // Success
}
```

**Rules:**
- ✅ Only modify your function body
- ✅ Use standard C library (string.h, math.h, etc.)
- ✅ Create local variables if needed
- ❌ DON'T modify struct definition
- ❌ DON'T modify function signature
- ❌ DON'T modify test cases
- ❌ DON'T create new files

### Step 6: Check Complexity

Verify your solution meets Time & Space complexity:

**Example:** Issue #1 requires O(1) time and O(1) space
- ✅ Your code doesn't loop → O(1) ✓
- ✅ You only use 1 student → O(1) ✓

If your code loops through all 100 students → O(n) → Won't meet requirement!

---

## Testing Your Code

### Run Tests

```bash
make test
```

This will:
1. Compile your code
2. Run all test cases
3. Show results

### Understanding Test Output

#### Passing Tests ✅

```
Test: Add single student
  ✓ PASS: add_student should return 1 on success
  ✓ PASS: total_students should be 1
  ✓ PASS: student name should match
  ✓ PASS: student grade should be 85

Test Results:
  Passed: 4
  Failed: 0
```

Every checkmark = one assertion passed ✓

#### Failing Tests ❌

```
Test: Add single student
  ✗ FAIL: add_student should return 1 on success (expected 1, got 0)
  ✗ FAIL: total_students should be 1 (expected 1, got 0)

Test Results:
  Passed: 0
  Failed: 2
```

**What to do when tests fail:**

1. **Read the error:** "expected 1, got 0"
2. **Understand:** Your function returned 0, but should return 1
3. **Find the bug:** Check your code
4. **Fix it:** Update implementation
5. **Re-test:** Run `make test` again

### Common Test Failures

**Issue: Function returns wrong value**
```
✗ FAIL: (expected 1, got 0)
```
→ Make sure you `return 1` not `return 0`

**Issue: Global counter not updated**
```
✗ FAIL: total_students should be 1 (expected 1, got 0)
```
→ Did you increment? Add: `total_students++;`

**Issue: String doesn't match**
```
✗ FAIL: name should be 'John' (expected 'John', got '')
```
→ Did you copy the data? `students[total_students] = s;`

**Issue: Edge case not handled**
```
✗ FAIL: should return 0 when full (expected 0, got 1)
```
→ Add boundary check: `if (total_students >= MAX_STUDENTS) return 0;`

### Test Tips

- **Each test is independent** - they don't affect each other
- **Tests show exactly what's expected** - read them carefully!
- **Run tests after EVERY change** - don't assume it works
- **All tests must pass** before you submit

---

## Submitting Your Work

### Step 1: Make Sure Tests Pass

```bash
make test
```

Output must show:
```
Test Results:
  Passed: X
  Failed: 0
```

### Step 2: Commit Your Changes

Stage your work:

```bash
git add src/student.c
```

Verify you're committing the right file:

```bash
git status
# Should show src/student.c with green "M" (modified)
```

Commit with a clear message:

```bash
git commit -m "Issue #X: Implement function_name

- Brief description of what you did
- All Y tests passing ✓"
```

**Example:**
```bash
git commit -m "Issue #1: Implement add_student

- Added check for database full (total_students >= MAX_STUDENTS)
- Stores student in global array
- Increments counter
- All 4 tests passing ✓"
```

### Step 3: Push to Your Fork

```bash
git push origin issue/X-function-name
```

You should see:
```
To https://github.com/YOUR-USERNAME/student-management.git
 * [new branch]      issue/1-add-student -> issue/1-add-student
```

GitHub will suggest creating a Pull Request. Click the link or follow Step 4.

### Step 4: Create a Pull Request

**⚠️ Important:** The PR must be created FROM your fork TO the main repo!

**Option A: Web UI (Easiest)**

1. Go to your fork: `https://github.com/YOUR-USERNAME/student-management`
2. You should see a yellow/blue banner saying: **"Create a pull request"**
   - It shows: **your-fork:issue/X-... → dharanigowthamsampath:main**
3. Click: **"Compare & Pull Request"**
4. Verify the PR is targeting the correct repos:
   - **Base:** dharanigowthamsampath/student-management (main)
   - **Head:** YOUR-USERNAME/student-management (your fork)
5. Add title: `Issue #X: Function description`
6. Add description:
   ```
   ## Summary
   Implemented add_student() function to add students to database

   ## Testing
   - Ran `make test` locally
   - All tests passing (4/4)
   - Tested: single student, multiple students, full database

   ## Changes
   - Check if database is full
   - Add student to array
   - Increment counter

   Closes #1
   ```
5. Click **"Create Pull Request"**

**Option B: GitHub CLI**

```bash
gh pr create \
  --title "Issue #X: Function description" \
  --body "Description of changes" \
  --base dharanigowthamsampath:main \
  --head YOUR-USERNAME:issue/X-function-name
```

### Step 5: Wait for Auto-Tests

GitHub Actions will automatically:
1. ✅ Clone your code
2. ✅ Run `make test`
3. ✅ Show results on your PR

**Results:**

✅ **All tests pass** (Green checkmark)
```
✓ Checks passed
```
Your PR is ready! Maintainer will merge it.

❌ **Tests fail** (Red X)
```
✗ Checks failed
```
**Fix and resubmit:**
1. Go back to Step 5 of "Solving an Issue"
2. Fix your code
3. Run `make test` locally (verify fix)
4. Commit: `git commit -m "Fix: issue with add_student"`
5. Push: `git push origin issue/X-function-name`
6. PR updates automatically! ✓

### Step 6: Celebrate! 🎉

Once all tests pass and maintainer merges:
- ✅ Your code is in main branch
- ✅ **GitHub automatically closes the issue** (because your PR says "Closes #X")
- ✅ Move to next issue
- ✅ Repeat process

**Important:** Notice the PR description includes:
```
Closes #1
```

This is a **GitHub magic keyword**. When the PR is merged:
1. ✅ Your code goes to main
2. ✅ Issue #1 automatically closes (no admin needed!)
3. ✅ Issue marked as solved

**For your issues, always include this in PR description:**
```
Closes #X
```
(Replace X with your issue number)

---

## Troubleshooting

### "Permission denied" Error

```
remote: Permission to dharanigowthamsampath/student-management denied
fatal: unable to access
```

**Problem:** You're trying to push to the main repo (not your fork)

**Solution:**
```bash
# Check your remote
git remote -v

# Should show: github.com/YOUR-USERNAME/student-management

# If wrong, fix it:
git remote set-url origin https://github.com/YOUR-USERNAME/student-management.git
```

### "I can't find my PR"

**Go to:** `https://github.com/YOUR-USERNAME/student-management`

Click **"Pull requests"** tab → You should see it there

### "My code compiles but tests fail"

**Steps to debug:**
1. Read error message: `(expected X, got Y)`
2. Open `test/test.c` → Find your test
3. Compare: What the test expects vs. what you returned
4. Fix your code
5. Run `make test` again

### "I accidentally committed to main branch"

```bash
# Undo last commit (keep changes)
git reset --soft HEAD~1

# Create correct branch
git checkout -b issue/X-function-name

# Commit again
git commit -m "Issue #X: ..."
git push origin issue/X-function-name
```

### "make test says gcc not found"

**macOS:**
```bash
brew install gcc make
```

**Linux:**
```bash
sudo apt-get install build-essential
```

### "I modified the wrong file"

```bash
# Undo changes to file
git checkout src/student.c

# Try again
```

### "Tests pass locally but fail on GitHub"

This shouldn't happen! But if it does:
1. Double-check you ran `make test`
2. Make sure you're on correct branch: `git branch`
3. Push again: `git push origin issue/X-function-name`

---

## Summary Checklist

For each issue, follow this checklist:

- [ ] **Setup (First time only)**
  - [ ] Installed GCC, Make, Git
  - [ ] Forked repo on GitHub
  - [ ] Cloned your fork
  - [ ] Configured Git (name & email)

- [ ] **Work on Issue**
  - [ ] Read issue description
  - [ ] Created branch: `git checkout -b issue/X-...`
  - [ ] Read function requirements in `src/student.c`
  - [ ] Read test cases in `test/test.c`
  - [ ] Implemented function
  - [ ] Ran `make test` → All pass ✓

- [ ] **Submit Work**
  - [ ] Committed: `git commit -m "Issue #X: ..."`
  - [ ] Pushed: `git push origin issue/X-...`
  - [ ] Created Pull Request on GitHub
  - [ ] Auto-tests ran ✓
  - [ ] Maintainer merged ✓

- [ ] **Move to Next Issue**
  - [ ] Back to main: `git checkout main`
  - [ ] Update: `git pull origin main`
  - [ ] Pick next issue
  - [ ] Create new branch: `git checkout -b issue/Y-...`

---

## Quick Reference

### Commands You'll Use

```bash
# Setup (first time)
git clone https://github.com/YOUR-USERNAME/student-management.git
cd student-management
git config user.name "Your Name"
git config user.email "your@email.com"

# Start an issue
git checkout -b issue/X-function-name

# Test locally
make test

# Commit & push
git add src/student.c
git commit -m "Issue #X: Description"
git push origin issue/X-function-name

# Next issue
git checkout main
git pull origin main
git checkout -b issue/Y-function-name
```

### Important Rules

✅ **Always:**
- Work on a feature branch (`issue/X-...`)
- Test before pushing (`make test`)
- Use YOUR email in commits
- Create a Pull Request (never push to main)

❌ **Never:**
- Work on `main` branch
- Modify test files
- Modify struct definitions
- Push directly to main repo
- Submit without testing

---

## You're Ready! 🚀

You now know:
- ✅ How to set up the project
- ✅ How to implement a function
- ✅ How to test your code
- ✅ How to submit via Pull Request
- ✅ How to handle failures

**Pick your first issue and start coding!**

Questions? Check the troubleshooting section or ask a mentor.

Good luck! 💪
