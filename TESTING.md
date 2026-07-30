# Testing Guide

Learn how to run tests and understand test failures.

## Running Tests

### Basic Test Run

```bash
make test
```

This will:
1. Compile the test suite
2. Run all tests
3. Show results

### Clean and Re-test

If something seems broken:

```bash
make clean
make test
```

This clears old build files and rebuilds everything.

---

## Understanding Test Output

### Passing Tests ✅

```
Test: Add single student
  ✓ PASS: add_student should return 1 on success
  ✓ PASS: total_students should be 1
  ✓ PASS: student name should match
  ✓ PASS: student grade should be 85
```

- Each checkmark ✓ is a passing assertion
- Read the message to understand what was tested

### Failing Tests ❌

```
Test: Add single student
  ✗ FAIL: add_student should return 1 on success (expected 1, got 0)
  ✗ FAIL: total_students should be 1 (expected 1, got 0)
```

Error format: `(expected X, got Y)`

**What to do:**
1. Read the error message
2. Look at the test case in `test/test.c`
3. Compare expected vs actual
4. Fix your implementation
5. Re-run tests

---

## Example: Debugging a Test Failure

### Scenario: Your test fails with this error:

```
Test: Add single student
  ✗ FAIL: total_students should be 1 (expected 1, got 0)
```

**Step 1:** Find the test in `test/test.c`

```c
void test_add_student_single() {
    setup();  // Clear database

    Student s = {1, "John Doe", "john@mail.com", "9999999999", 85, "CS", 2};
    int result = add_student(s);

    ASSERT_EQUAL(total_students, 1, "total_students should be 1");
}
```

**Step 2:** The test expects `total_students` to be 1, but it's 0.

This means: **You didn't increment total_students in your add_student() function!**

**Step 3:** Check your implementation in `src/student.c`

```c
int add_student(Student s) {
    students[0] = s;  // ❌ Missing: total_students++
    return 1;
}
```

**Step 4:** Fix it:

```c
int add_student(Student s) {
    if (total_students >= MAX_STUDENTS) {
        return 0;
    }
    students[total_students] = s;
    total_students++;  // ✅ Add this line!
    return 1;
}
```

**Step 5:** Re-run tests:

```bash
make test
```

**Step 6:** All tests pass! ✅

---

## Test Structure

Each test follows this pattern:

```c
void test_add_student_single() {
    // SETUP: Clear database
    setup();

    // ARRANGE: Create test data
    Student s = {1, "John Doe", "john@mail.com", "9999999999", 85, "CS", 2};

    // ACT: Call the function
    int result = add_student(s);

    // ASSERT: Check results
    ASSERT_EQUAL(result, 1, "Should return 1");
    ASSERT_EQUAL(total_students, 1, "Counter should increment");
}
```

---

## Test Isolation

**Important:** Each test starts with a clean database via `setup()`:

```c
void setup() {
    total_students = 0;
    memset(students, 0, sizeof(students));
}
```

This means:
- ✅ Each test is independent
- ✅ Test 1 won't affect Test 2
- ✅ You don't need to worry about test order

---

## Common Test Failures and Fixes

### 1. Function returns wrong value

```
✗ FAIL: should return 1 (expected 1, got 0)
```

**Fix:** Make sure you're returning the correct value

```c
// ❌ Wrong
return 0;

// ✅ Correct
return 1;
```

### 2. Global counter not updated

```
✗ FAIL: total_students should be 1 (expected 1, got 0)
```

**Fix:** Increment the global counter

```c
// ❌ Wrong
int add_student(Student s) {
    students[0] = s;
    return 1;
}

// ✅ Correct
int add_student(Student s) {
    students[total_students] = s;
    total_students++;
    return 1;
}
```

### 3. String doesn't match

```
✗ FAIL: student name should match (expected 'John', got '')
```

**Fix:** Make sure you're copying the data correctly

```c
// ❌ Wrong
students[total_students] = s;  // Need strcpy for strings

// ✅ Correct
strcpy(students[total_students].name, s.name);
// OR
students[total_students] = s;  // This works too (struct assignment)
```

### 4. Edge case not handled

```
✗ FAIL: should return 0 when full (expected 0, got 1)
```

**Fix:** Add boundary checks

```c
// ❌ Wrong
int add_student(Student s) {
    students[total_students] = s;
    total_students++;
    return 1;
}

// ✅ Correct
int add_student(Student s) {
    if (total_students >= MAX_STUDENTS) {
        return 0;  // Check if full!
    }
    students[total_students] = s;
    total_students++;
    return 1;
}
```

---

## Assertions Explained

### ASSERT_EQUAL

Compares two integers:

```c
ASSERT_EQUAL(actual, expected, "message");
```

Example:
```c
ASSERT_EQUAL(total_students, 1, "Counter should be 1");
// ✓ PASS if total_students == 1
// ✗ FAIL if total_students != 1
```

### ASSERT_STRING_EQUAL

Compares two strings:

```c
ASSERT_STRING_EQUAL(actual, expected, "message");
```

Example:
```c
ASSERT_STRING_EQUAL(students[0].name, "John", "Name should be John");
// ✓ PASS if names match exactly
// ✗ FAIL if they differ
```

---

## Test Results Summary

At the end of each test run:

```
========================================
Test Results:
  Passed: 11
  Failed: 0
========================================
```

- **Passed:** Number of assertions that passed ✓
- **Failed:** Number of assertions that failed ✗

**Goal:** 0 failed tests for your issue!

---

## Running Tests in CLion

### Method 1: Terminal in CLion

1. Open Terminal in CLion (View → Tool Windows → Terminal)
2. Type: `make test`
3. See results

### Method 2: Run Configuration

1. Add run configuration for tests (optional advanced)
2. Configure build to run tests

### Method 3: From Command Line

```bash
make test
```

---

## Complexity Verification

Tests verify your implementation meets:
- **Time Complexity** - How fast (e.g., O(n), O(n log n))
- **Space Complexity** - How much memory (e.g., O(1), O(n))

You should ensure your code is efficient as specified in the issue!

---

## Getting Help

If you're stuck:
1. Read the test case carefully
2. Compare expected vs actual
3. Check the function requirements
4. Ask a mentor!

Remember: **Tests show you exactly what to do!** 💡
