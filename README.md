# Student Management System - C Project

A beginner-friendly C project for learning software development practices with a focus on collaborative development using GitHub.

**🎯 120 independent functions | 60 students | 2 issues per student**

## Getting Started (Choose Your Path)

### 👨‍💻 For New Students
Start here - complete these guides in order:
1. **[SETUP.md](SETUP.md)** - Install required tools and verify setup
2. **[WORKFLOW.md](WORKFLOW.md)** - Step-by-step guide to solve an issue
3. **[STUDENT_SUBMISSION.md](STUDENT_SUBMISSION.md)** - How to fork, commit, and submit PRs
4. **[TESTING.md](TESTING.md)** - Understand how tests work

### 👨‍🏫 For Instructors
- View all 120 functions: **[FUNCTIONS_LIST.md](FUNCTIONS_LIST.md)**
- Set up GitHub workflows and auto-testing

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

## How to Submit Your Work

### Quick Start (5 Steps)

1. **Fork** the repo (create your own copy)
2. **Clone** your fork: `git clone https://github.com/YOUR-USERNAME/student-management.git`
3. **Create branch**: `git checkout -b issue/X-function-name`
4. **Implement & test**: Edit code, run `make test`
5. **Submit PR**: Push to your fork, create Pull Request

### Detailed Guide

See **[STUDENT_SUBMISSION.md](STUDENT_SUBMISSION.md)** for:
- ✅ How to fork the repository
- ✅ How to commit and push properly
- ✅ How to create a Pull Request
- ✅ How to handle test failures
- ✅ Troubleshooting common issues

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
