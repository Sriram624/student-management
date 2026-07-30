# Student Submission Workflow

**Important:** Each student has their own GitHub account and submits code via **Pull Requests (PRs)**.

## How It Works

### The Setup

```
Main Repository (dharanigowthamsampath)
    ↑ (Pull Request from)
├─ Student 1 Fork (student1-username)
├─ Student 2 Fork (student2-username)
├─ Student 3 Fork (student3-username)
└─ ... (60 students total)
```

Each student:
1. ✅ Forks the main repository (personal copy)
2. ✅ Clones their fork locally
3. ✅ Works on their fork (not the main repo)
4. ✅ Creates a Pull Request to the main repo
5. ✅ Auto-tests run on the PR
6. ✅ Maintainer merges when all tests pass

---

## Student Workflow (Detailed)

### Step 1: Fork the Repository

**Go to:** https://github.com/dharanigowthamsampath/student-management

Click **"Fork"** → Creates your personal copy:
```
https://github.com/YOUR-USERNAME/student-management
```

### Step 2: Clone Your Fork

```bash
git clone https://github.com/YOUR-USERNAME/student-management.git
cd student-management
```

### Step 3: Configure Git (ONE TIME ONLY)

```bash
git config user.name "Your Full Name"
git config user.email "your-email@example.com"
```

This ensures your commits show YOUR name, not someone else's!

### Step 4: Create Issue Branch

```bash
git checkout -b issue/X-function-name

# Example:
git checkout -b issue/1-add-student
```

### Step 5: Read Documentation

1. **SETUP.md** - Set up the project
2. **WORKFLOW.md** - Step-by-step workflow
3. **TESTING.md** - Understanding tests

### Step 6: Implement the Function

1. Open `src/student.c`
2. Find your issue number
3. Read the TODO requirements
4. Write the implementation
5. Don't modify anything else!

### Step 7: Test Locally

```bash
make test
```

All tests must pass ✅

### Step 8: Commit Your Changes

```bash
git add src/student.c
git commit -m "Issue #X: Implement function_name

- Detailed description of changes
- All Y tests passing"
```

**Important:** Use your OWN email (already configured in Step 3)

### Step 9: Push to YOUR Fork

```bash
git push origin issue/X-function-name
```

You should see:
```
remote: Create a pull request for 'issue/X-function-name' on GitHub by visiting:
remote: https://github.com/YOUR-USERNAME/student-management/pull/new/issue/X-function-name
```

### Step 10: Create a Pull Request

**Option A: Via GitHub Web UI** (Easiest)
1. Go to your fork on GitHub
2. Click the yellow banner: **"Compare & Pull Request"**
3. Add description
4. Click **"Create Pull Request"**

**Option B: Via CLI**
```bash
gh pr create \
  --title "Issue #X: Function description" \
  --body "Description of changes" \
  --base dharanigowthamsampath:main \
  --head YOUR-USERNAME:issue/X-function-name
```

### Step 11: Wait for Auto-Tests

GitHub Actions will:
1. ✅ Check out your code
2. ✅ Run `make test`
3. ✅ Show results on the PR

**Possible outcomes:**

✅ **All tests pass:**
```
✓ Passed: 11
✓ Failed: 0
```
Your PR is ready to merge!

❌ **Tests fail:**
```
✗ Passed: 8
✗ Failed: 3
```
- Fix the code locally
- Commit again: `git commit -m "Fix: add_student test"`
- Push again: `git push origin issue/X-function-name`
- PR updates automatically ✅

### Step 12: Maintainer Reviews & Merges

Once all tests pass:
1. Maintainer reviews your code
2. If good: Clicks **"Merge Pull Request"**
3. Your code goes to main branch! 🎉

---

## Example: Complete Student Flow

```bash
# Student: Alice (alice@gmail.com)

# 1. Fork on GitHub (web UI)

# 2. Clone fork
git clone https://github.com/alice-username/student-management.git
cd student-management

# 3. Configure git
git config user.name "Alice Johnson"
git config user.email "alice@gmail.com"

# 4. Create branch
git checkout -b issue/2-delete-student

# 5. Read documentation
cat SETUP.md WORKFLOW.md

# 6. Implement
vim src/student.c
# Write delete_student() function

# 7. Test
make test
# Output: Passed: 8, Failed: 0 ✓

# 8. Commit
git add src/student.c
git commit -m "Issue #2: Implement delete_student

- Removes student by ID
- Shifts remaining students
- Decrements counter
- All 8 tests passing"

# 9. Push to Alice's fork
git push origin issue/2-delete-student

# 10. Create PR (web UI)
# → Click "Compare & Pull Request"
# → Add description
# → Click "Create Pull Request"

# 11. GitHub Actions runs tests
# → All pass ✓

# 12. Maintainer merges
# → Alice's code now in main!
```

---

## What Each Student Will See

### On Their Fork
```
https://github.com/alice-username/student-management
├── origin (their fork)
└── upstream (main repo) - optional, for syncing
```

### On the Main Repo
```
https://github.com/dharanigowthamsampath/student-management
├── Pull Requests
│   ├── #1 from alice-username (Alice)
│   ├── #2 from bob-username (Bob)
│   └── ... (60 PRs total)
```

Each PR shows:
- Student's name
- Function they implemented
- Test results (✅ or ❌)
- Auto-test status

---

## Important Rules

✅ **DO:**
- Fork the main repo (create your own copy)
- Work only in your fork
- Submit a PR (never push to main directly)
- Test locally before pushing
- Use YOUR email (not someone else's)

❌ **DON'T:**
- Push directly to main repo (no permissions!)
- Modify other students' code
- Modify struct definitions or test cases
- Submit multiple PRs for one issue
- Work on main branch (use feature branches)

---

## Troubleshooting

### "Permission denied" error
```
remote: Permission to dharanigowthamsampath/student-management.git denied
```
**Solution:** Make sure you:
1. ✅ Cloned YOUR fork (not main repo)
2. ✅ Are pushing to YOUR fork (`git remote -v` should show your username)

### "Where is my PR?"
**Check:**
1. Go to YOUR fork: `https://github.com/YOUR-USERNAME/student-management`
2. Click **"Pull requests"** tab
3. You should see your PR there

### "My tests are failing"
**Steps:**
1. Read the error message carefully
2. Look at `test/test.c` for the test case
3. Compare expected vs actual
4. Fix your code
5. Run `make test` again
6. Commit & push again (PR updates automatically)

### "Which branch should I use?"
**Answer:** Always work on a feature branch!
```bash
# ✅ Correct
git checkout -b issue/1-add-student

# ❌ Wrong (don't use main)
git checkout main
```

---

## Timeline for 60 Students

If each student solves 2 issues:
- Total issues: 120
- Per student: 2 issues
- Expected PRs: ~120 (some might take 2-3 attempts)

**Flow:**
1. Issue #1 → PR from Student #1
2. Issue #2 → PR from Student #1
3. Issue #3 → PR from Student #2
4. ... (continue)
5. Issue #120 → PR from Student #60

Each PR:
- Auto-tests run ✅
- Passes or fails ✅
- Maintainer merges ✅
- Next PR can start ✅

---

## Summary

| Step | Action | Location | Result |
|------|--------|----------|--------|
| 1 | Fork repo | GitHub web | Create your copy |
| 2 | Clone | Your computer | Get code locally |
| 3 | Config git | Your computer | Set your name/email |
| 4 | Create branch | Your computer | `issue/X-function` |
| 5 | Read docs | Your computer | Understand requirements |
| 6 | Implement | Your computer | Write code |
| 7 | Test | Your computer | Run `make test` |
| 8 | Commit | Your computer | `git commit` |
| 9 | Push | Your fork | `git push` |
| 10 | PR | GitHub web | Create PR |
| 11 | Auto-test | GitHub | Tests run automatically |
| 12 | Merge | Maintainer | Code goes to main ✓ |

**You got this!** 🚀
