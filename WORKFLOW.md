# Workflow Guide - How to Solve an Issue

Complete step-by-step guide to solve any issue in this project.

## Before You Start

- ✅ Completed [SETUP.md](SETUP.md)?
- ✅ Can run `make test`?
- ✅ Understand the project structure?

If yes, let's go! 🚀

---

## Step 1: Find Your Issue

Go to: https://github.com/dharanigowthamsampath/student-management/issues

Click on an issue assigned to you. Example: **Issue #1: Implement add_student()**

**Read the issue description carefully** - it contains:
- What function to implement
- Requirements
- Example usage
- Time & Space complexity expectations

---

## Step 2: Create a Branch

Create a Git branch for your issue:

```bash
# Replace X with your issue number
# Example: issue/1-add-student
git checkout -b issue/X-function-name
```

Verify you're on the correct branch:

```bash
git branch  # Should show * issue/X-function-name
```

---

## Step 3: Read the Function Requirements

1. Open file: `src/student.c`
2. Search for your issue number (Ctrl+F / Cmd+F)
3. Read the TODO comments carefully:
   - What does the function do?
   - What are the inputs/outputs?
   - What constraints exist?
   - What test cases should pass?

Example for Issue #1:

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
// Time Complexity: O(1)
// Space Complexity: O(1)
//
int add_student(Student s) {
    // TODO: Implement this function
    // Write your code here

    return 0;  // Change this
}
```

---

## Step 4: Look at Test Cases

1. Open file: `test/test.c`
2. Search for your issue number (Ctrl+F)
3. **Read the test cases** - they show exactly what your function should do

Example test for Issue #1:

```c
void test_add_student_single() {
    setup();  // Clear database

    Student s = {1, "John Doe", "john@mail.com", "9999999999", 85, "CS", 2};
    int result = add_student(s);

    // Expected: result should be 1, total_students should be 1
    ASSERT_EQUAL(result, 1, "add_student should return 1 on success");
    ASSERT_EQUAL(total_students, 1, "total_students should be 1");
}
```

**This test tells you:**
- Create a Student with ID=1, name="John Doe", etc.
- Call `add_student(s)`
- Function should return 1
- Global counter `total_students` should be 1

---

## Step 5: Implement the Function

Go back to `src/student.c` and write your implementation:

```c
int add_student(Student s) {
    // Check if database is full
    if (total_students >= MAX_STUDENTS) {
        return 0;  // Database full
    }

    // Add student to array
    students[total_students] = s;
    total_students++;

    return 1;  // Success
}
```

**Rules:**
- ✅ Only modify your function body
- ✅ You can use standard C library (string.h, math.h, etc.)
- ✅ You can create local variables
- ❌ Don't modify struct definition
- ❌ Don't modify function signature
- ❌ Don't modify test cases
- ❌ Don't create new files

---

## Step 6: Test Locally

Run tests to verify your implementation:

```bash
make test
```

**If all tests pass:**

```
========================================
Issue #1: add_student Tests
========================================

Test: Add single student
  ✓ PASS: add_student should return 1 on success
  ✓ PASS: total_students should be 1
  ✓ PASS: student name should match
  ✓ PASS: student grade should be 85

Test: Add multiple students
  ✓ PASS: first add_student should return 1
  ✓ PASS: second add_student should return 1
  ✓ PASS: third add_student should return 1
  ✓ PASS: total_students should be 3

Test: Add student to full database
  ✓ Successfully added 100 students
  ✓ PASS: add_student should return 0 when database is full
  ✓ PASS: total_students should remain MAX_STUDENTS

========================================
Test Results:
  Passed: 11
  Failed: 0
========================================
```

✅ **Great! Your implementation is correct.**

**If tests fail:**

1. Read the error message carefully
2. Check your implementation
3. Check the test case to understand expectations
4. Ask for help if stuck!

---

## Step 7: Commit Your Changes

Stage your changes:

```bash
git add src/student.c
```

Verify what you're committing:

```bash
git status  # Should show src/student.c
```

Commit with a clear message:

```bash
git commit -m "Issue #X: Implement function_name

- Added function implementation
- All tests passing (X/X)"
```

---

## Step 8: Push to GitHub

Push your branch to GitHub:

```bash
git push origin issue/X-function-name
```

You should see:

```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 258 bytes | 258.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), reused pack 0 (delta 0)
remote: Resolving deltas: 100% (2/2), completed with 0 deltas.
remote:
remote: Create a pull request for 'issue/X-function-name' on GitHub by visiting:
remote:      https://github.com/dharanigowthamsampath/student-management/pull/new/issue/X-function-name
```

---

## Step 9: Create a Pull Request (PR)

1. Go to: https://github.com/dharanigowthamsampath/student-management
2. You'll see a yellow banner suggesting to create a PR
3. Click **"Compare & Pull Request"** or **"New Pull Request"**
4. Add a description:

```
Closes #X

## Summary
- Implemented add_student() function
- Handles database full scenario
- All 11 tests passing

## Testing
- Ran `make test` locally
- All tests passed
- Tested edge case: full database
```

5. Click **"Create Pull Request"**

---

## Step 10: Wait for Auto-Tests

GitHub Actions will automatically:
1. Clone your code
2. Run `make test`
3. Check if all tests pass

**Status will show:**
- ✅ **All checks passed** → Ready to merge!
- ❌ **Some checks failed** → Fix and push again

If tests fail:
1. Go back to Step 6
2. Fix your code
3. Run `make test` locally
4. Commit: `git commit -m "Fix: issue with add_student"`
5. Push: `git push origin issue/X-function-name`
6. PR will update automatically ✅

---

## Step 11: Merge PR

Once all tests pass:
- A maintainer will review your code
- They'll click **"Merge Pull Request"**
- Your code goes to main branch! 🎉

---

## Summary Checklist

- [ ] Created branch: `issue/X-function-name`
- [ ] Read function requirements in `src/student.c`
- [ ] Read test cases in `test/test.c`
- [ ] Implemented the function
- [ ] Ran `make test` - all passed ✅
- [ ] Committed: `git commit -m "Issue #X: ..."`
- [ ] Pushed: `git push origin issue/X-function-name`
- [ ] Created PR on GitHub
- [ ] Auto-tests passed ✅
- [ ] PR merged ✅

**Congratulations! You've completed an issue!** 🚀

---

## Need Help?

- **Tests failing?** Read the error message + test case
- **Don't understand function?** Check test cases (they show examples)
- **Git confused?** Check [WORKFLOW.md](WORKFLOW.md) again
- **Still stuck?** Ask a mentor!

Good luck! 💪
