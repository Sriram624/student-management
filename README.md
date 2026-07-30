# Student Management System - C Project

A beginner-friendly C project for learning software development practices with a focus on collaborative development using GitHub.

## Project Structure

```
student_management/
├── src/
│   ├── student.h         (Struct definitions & constants - DO NOT MODIFY)
│   ├── student.c         (Function implementations - Students code here)
├── test/
│   ├── test.c            (Test cases - Pre-written, auto-run)
├── Makefile              (Build configuration)
├── main.c                (Entry point)
└── README.md             (This file)
```

## Setup

1. **Clone the repository**
   ```bash
   git clone <repo-url>
   cd student_management
   ```

2. **Check if you can build**
   ```bash
   make clean
   make test
   ```
   If tests compile and run, you're ready!

## Workflow for Solving Issues

### Step 1: Create a branch for your issue
```bash
# Replace X with your issue number
git checkout -b issue/X-function-name
```

### Step 2: Read the TODO in src/student.c
- Open `src/student.c`
- Find your issue number (e.g., Issue #1)
- Read the requirements carefully
- Look at the test cases to understand what's expected

### Step 3: Implement the function
- Write only the code inside your function
- Do NOT modify:
  - `student.h` (struct, constants)
  - Test cases
  - Function signatures
- Follow the complexity requirements (Time & Space)

### Step 4: Test locally
```bash
make test
```
You should see:
```
✓ PASS: test case name
✓ PASS: another test
Test Results:
  Passed: 3
  Failed: 0
```

### Step 5: Commit your changes
```bash
git add src/student.c
git commit -m "Issue #X: Implement function_name"
```

### Step 6: Push to GitHub
```bash
git push origin issue/X-function-name
```

### Step 7: Create a Pull Request (PR)
- Go to GitHub
- Click "Compare & Pull Request"
- Add a description of what you implemented
- Submit

### Step 8: Wait for auto-tests
GitHub will automatically run tests on your PR:
- ✅ If all tests pass → PR is ready to merge
- ❌ If tests fail → Fix the code, commit again, push again

### Step 9: Merge PR
Once tests pass, a maintainer will merge your PR.

## Building & Testing

### Run tests
```bash
make test
```

### Clean build
```bash
make clean
```

### Rebuild
```bash
make rebuild
```

## Important Rules for Students

✅ **You CAN:**
- Modify only your function implementation in `src/student.c`
- Use standard C library functions (stdio.h, string.h, math.h, etc.)
- Add local variables inside your function

❌ **You CANNOT:**
- Modify `student.h` or struct definitions
- Modify function signatures
- Modify test cases
- Use global variables (except students array)
- Create new files

## Understanding the Student Struct

```c
typedef struct {
    int id;                          // Student ID
    char name[MAX_NAME_LENGTH];      // Full name
    char email[MAX_EMAIL_LENGTH];    // Email address
    char phone[MAX_PHONE_LENGTH];    // Phone number
    int grade;                       // Grade (0-100)
    char department[MAX_DEPARTMENT_LENGTH];  // Department
    int year;                        // Year (1-4)
} Student;
```

## Global Database

All functions work with:
```c
Student students[MAX_STUDENTS];  // Array of students
int total_students;              // Current count
```

## Example: Solving Issue #1

**Issue:** Implement `add_student()`

**Steps:**
1. `git checkout -b issue/1-add-student`
2. Open `src/student.c`, find Issue #1
3. Read requirements and test cases
4. Write implementation:
   ```c
   int add_student(Student s) {
       if (total_students >= MAX_STUDENTS) {
           return 0;  // Database full
       }
       students[total_students] = s;
       total_students++;
       return 1;  // Success
   }
   ```
5. `make test` → See all tests pass ✓
6. `git add src/student.c`
7. `git commit -m "Issue #1: Implement add_student"`
8. `git push origin issue/1-add-student`
9. Create PR on GitHub
10. Wait for auto-tests to pass
11. PR merged ✓

## Help & Debugging

If your test fails:
1. Read the error message carefully
2. Run `make test` again to see exact output
3. Check the test case in `test/test.c` to understand what's expected
4. Verify your implementation matches requirements
5. Ask for help if stuck

## Complexity Requirements

Each function has Time and Space complexity requirements (LeetCode style).

Example:
- Issue #1 (add_student): O(1) time, O(1) space ✓ (Just append to array)

Make sure your solution meets these requirements!

---

Good luck! 🚀
