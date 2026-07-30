# Claude Instructions - Student Management System

## Project Overview

This is an **educational C project** designed to teach 60 students professional software development practices. Each student solves 2 independent issues (120 total functions).

**Goal:** Build production-ready skeleton with validated workflow for scaling to 120 functions.

---

## Key Context

### Current Status
- ✅ Skeleton complete with 2 working issues (#1 add_student, #2 delete_student)
- ✅ Test framework built (21/21 tests passing)
- ✅ GitHub Actions auto-testing configured
- ✅ Workflow validated end-to-end
- ✅ 4 common errors documented
- ✅ Ready to scale to 120 issues

### Project Structure
```
src/
  student.h       (Struct, constants, declarations - READ-ONLY)
  student.c       (Function stubs - students implement here)
test/
  test.c          (Pre-written test cases)
.github/workflows/
  test.yml        (GitHub Actions auto-testing)
GETTING_STARTED.md (Complete student guide - single file)
FUNCTIONS_LIST.md  (All 120 functions table)
```

---

## What Claude Should Know

### 1. Design Philosophy
- **No external dependencies** - Custom test framework, no CUnit
- **Simple > Complex** - Bare minimum needed for beginners
- **Independent functions** - Each function works standalone (no dependencies between issues)
- **Auto-everything** - GitHub auto-closes issues, auto-tests, auto-tracks students
- **Single documentation** - GETTING_STARTED.md is the ONLY guide students read

### 2. Student Workflow
```
Fork → Clone → Sync → Branch → Code → Test (all pass) → Commit → Push → PR → Auto-close → Done
```

### 3. Function Design
- **Each function is independent** (students work in parallel, no conflicts)
- **Clear requirements** (TODO comments in stub show exactly what to do)
- **Comprehensive tests** (test cases show expected behavior)
- **Complexity specs** (O(n), O(1), etc. documented)
- **No helper functions needed** (everything self-contained)

### 4. Test Framework
- **Setup pattern** - Each test calls `setup()` to reset database
- **Assertions** - ASSERT_EQUAL, ASSERT_STRING_EQUAL
- **Clear output** - ✓ PASS / ✗ FAIL with expected vs actual
- **No external deps** - Custom implementation in test/test.c

### 5. Student Tracking (Automatic!)
- Students use "Closes #X" in PR description
- GitHub auto-closes issue when PR merges
- Student name automatically linked to completed work
- Admin goes to closed issues to see progress
- **Zero manual work needed**

---

## Common Tasks & How to Approach

### Task #1: Create New Issue Stubs (Issues #3-#120)

**When:** Expanding from 2 issues to 120

**Steps:**
1. Pick next issue from FUNCTIONS_LIST.md
2. Add stub to `src/student.c` following this pattern:
   ```c
   // ========================================
   // Issue #X: Implement function_name
   // ========================================
   // TODO: Description of what to do
   //
   // Requirements:
   // - Clear requirements
   // - Time complexity: O(n)
   // - Space complexity: O(1)
   //
   int function_name(...) {
       // TODO: Implement this function
       return 0;  // Change this
   }
   ```
3. Add declaration to `src/student.h`
4. Add test cases to `test/test.c`
5. Commit: `git commit -m "feat: Add Issue #X - function_name"`
6. Push: `git push origin main`

**Key Points:**
- Use Issue #1 & #2 as templates
- Tests must verify correct behavior
- Include edge cases (empty, full, invalid)
- Each issue ~3-5 test cases

### Task #2: Create GitHub Issues (for tracking)

**When:** After adding function stubs

**Template:**
```markdown
## Objective
Implement the `function_name()` function...

## Requirements
- Requirement 1
- Requirement 2
- Return values explained

## Time Complexity: O(n)
## Space Complexity: O(1)

## Test Cases
Describe what tests expect

## How to Solve
1. Read GETTING_STARTED.md
2. Look at test cases in test/test.c
3. Follow workflow steps
4. Run `make test` to verify

Closes #X
```

**Key Points:**
- Always include "Closes #X" in description
- Link to test cases
- Show time/space requirements
- Make requirements crystal clear

### Task #3: Help Students Debug

**When:** Student comes with test failure

**Approach:**
1. **Read test case** in `test/test.c` - shows expected behavior
2. **Compare expected vs actual** - what did student's function return?
3. **Trace through code** - walk through implementation with example
4. **Suggest fix** - don't just give answer, guide to solution
5. **Verify** - ask them to run `make test` again

**Common Mistakes:**
- Forgot to increment counter
- Didn't check for full database
- Didn't shift array correctly
- Wrong return value
- Didn't handle edge cases

### Task #4: Add Documentation

**When:** Students report errors or ask clarification

**Policy:**
- Add solutions to GETTING_STARTED.md Troubleshooting section
- Keep GETTING_STARTED.md as the ONLY guide (all-in-one)
- Make solutions clear and actionable
- Include: Problem → Cause → Solution

### Task #5: Test Validation

**When:** After adding new issues

**Steps:**
1. Add stub to `src/student.c`
2. Add tests to `test/test.c`
3. Implement the function
4. Run `make test` → all should pass
5. Revert implementation back to stub (return 0)
6. Verify tests fail (expected behavior)
7. Implement again and commit

**Why:** Ensures tests actually validate behavior

---

## Important Guidelines

### DO:
- ✅ Keep functions **completely independent**
- ✅ Test thoroughly (3-5 test cases per function)
- ✅ Use clear TODO comments
- ✅ Document errors in GETTING_STARTED.md
- ✅ Maintain FUNCTIONS_LIST.md accurately
- ✅ Push to main repo only complete, tested code
- ✅ Use "Closes #X" in PRs to auto-close issues

### DON'T:
- ❌ Create dependencies between functions
- ❌ Require students to implement helper functions
- ❌ Use external libraries/dependencies
- ❌ Break existing tests
- ❌ Modify student.h struct definition
- ❌ Change function signatures
- ❌ Create more documentation files (only GETTING_STARTED.md)

---

## Useful Commands

### Build & Test
```bash
make clean       # Clean old builds
make test        # Run all tests
make rebuild     # Clean + build
```

### Git Workflow (As Admin)
```bash
git checkout -b feature/new-issues     # Create feature branch
git add src/student.c test/test.c      # Add changes
git commit -m "feat: Add Issues #X-#Y"
git push origin main                   # Push to main

# Create GitHub Issue via CLI:
gh issue create --title "Issue #X: ..." --body "..."
```

### Check Status
```bash
git log --oneline -10              # See recent commits
gh issue list --state open         # Open issues
gh issue list --state closed       # Completed issues
gh pr list --state merged          # Merged PRs
```

---

## Common Patterns

### Function Stub Pattern
```c
int function_name(int id) {
    // Find student by ID
    for (int i = 0; i < total_students; i++) {
        if (students[i].id == id) {
            // Do something
            return 1;  // Success
        }
    }
    return 0;  // Not found
}
```

### Test Case Pattern
```c
void test_function_name_success() {
    printf("\nTest: Description\n");
    setup();  // Clear database

    // Arrange
    Student s = {...};
    add_student(s);

    // Act
    int result = function_name(1);

    // Assert
    ASSERT_EQUAL(result, 1, "Should return 1");
    ASSERT_EQUAL(total_students, 1, "Counter correct");
}
```

### Troubleshooting Entry Pattern
```markdown
### "Error message here"

**Problem:** What causes this error

**Solution:** Steps to fix:
```bash
code example
```

Or description
```

---

## When in Doubt

1. **Check FUNCTIONS_LIST.md** - See what functions need to be implemented
2. **Look at Issue #1 & #2** - Use as templates
3. **Read test cases** - Tests show expected behavior
4. **Check GETTING_STARTED.md** - Student guide has answers
5. **Check git log** - See how previous issues were added

---

## Success Criteria

### For Each Issue:
- ✅ Stub created with clear TODO
- ✅ 3-5 test cases added
- ✅ All tests pass when implemented
- ✅ Tests fail when stub returns 0
- ✅ Can be solved independently
- ✅ GitHub issue created for tracking
- ✅ "Closes #X" works when PR merges

### For Entire Project:
- ✅ 120 functions available
- ✅ 60 students can work in parallel
- ✅ Each issue takes 15-30 min to solve
- ✅ Auto-testing on GitHub
- ✅ Auto-closing issues
- ✅ Student tracking automatic
- ✅ Zero manual admin tracking needed

---

## Quick Reference: File Locations

| File | Purpose | Edit? |
|------|---------|-------|
| `src/student.h` | Struct, constants, declarations | ❌ Rarely |
| `src/student.c` | Function stubs | ✅ Add stubs here |
| `test/test.c` | Test cases | ✅ Add tests here |
| `GETTING_STARTED.md` | Student guide | ✅ Add error solutions |
| `README.md` | Quick ref | ⚠️ If needed |
| `FUNCTIONS_LIST.md` | All 120 functions | ✅ Keep updated |
| `Makefile` | Build config | ❌ Rarely |
| `.github/workflows/test.yml` | GitHub Actions | ❌ Don't touch |

---

## Next Major Tasks

1. **Create Issues #3-#120** (~6-8 hours)
   - Add stubs to student.c
   - Add tests to test.c
   - Create GitHub Issues

2. **Assign to 60 Students** (2 per student)
   - Organize student accounts
   - Assign issues
   - Send GETTING_STARTED.md link

3. **Monitor Progress** (automatic!)
   - Check closed issues list
   - See which students completed what
   - No manual tracking needed

---

## Notes for Claude

- **This is a teaching project** - Focus on clarity and pedagogy
- **Students are beginners** - Keep explanations simple, comprehensive
- **Auto-tracking works** - Don't add manual work
- **One guide is best** - Don't create scattered docs
- **Template reusable** - Issue #1 & #2 are templates for #3-#120
- **Errors are learning** - Document common mistakes
- **Validation is key** - Always test implementations before committing

---

**Remember:** The goal is to teach 60 students professional development practices while automatically tracking their progress. Keep it simple, well-documented, and automated.

Good luck! 🚀
