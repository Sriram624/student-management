#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/student.h"

// ========================================
// Simple Test Framework (No external dependencies)
// ========================================

int tests_passed = 0;
int tests_failed = 0;

#define ASSERT_EQUAL(actual, expected, msg) \
    do { \
        if ((actual) == (expected)) { \
            printf("  ✓ PASS: %s\n", msg); \
            tests_passed++; \
        } else { \
            printf("  ✗ FAIL: %s (expected %d, got %d)\n", msg, expected, actual); \
            tests_failed++; \
        } \
    } while(0)

#define ASSERT_STRING_EQUAL(actual, expected, msg) \
    do { \
        if (strcmp(actual, expected) == 0) { \
            printf("  ✓ PASS: %s\n", msg); \
            tests_passed++; \
        } else { \
            printf("  ✗ FAIL: %s (expected '%s', got '%s')\n", msg, expected, actual); \
            tests_failed++; \
        } \
    } while(0)

// ========================================
// Helper function to reset database before each test
// ========================================
void setup() {
    total_students = 0;
    memset(students, 0, sizeof(students));
}

// ========================================
// Issue #1 Tests: add_student
// ========================================

void test_add_student_single() {
    printf("\nTest: Add single student\n");
    setup();

    Student s = {1, "John Doe", "john@mail.com", "9999999999", 85, "CS", 2};
    int result = add_student(s);

    ASSERT_EQUAL(result, 1, "add_student should return 1 on success");
    ASSERT_EQUAL(total_students, 1, "total_students should be 1");
    ASSERT_STRING_EQUAL(students[0].name, "John Doe", "student name should match");
    ASSERT_EQUAL(students[0].grade, 85, "student grade should be 85");
}

void test_add_student_multiple() {
    printf("\nTest: Add multiple students\n");
    setup();

    Student s1 = {1, "Alice", "alice@mail.com", "1111111111", 90, "CS", 1};
    Student s2 = {2, "Bob", "bob@mail.com", "2222222222", 75, "IT", 2};
    Student s3 = {3, "Charlie", "charlie@mail.com", "3333333333", 88, "ECE", 3};

    int r1 = add_student(s1);
    int r2 = add_student(s2);
    int r3 = add_student(s3);

    ASSERT_EQUAL(r1, 1, "first add_student should return 1");
    ASSERT_EQUAL(r2, 1, "second add_student should return 1");
    ASSERT_EQUAL(r3, 1, "third add_student should return 1");
    ASSERT_EQUAL(total_students, 3, "total_students should be 3");
}

void test_add_student_full_database() {
    printf("\nTest: Add student to full database\n");
    setup();

    // Fill database with MAX_STUDENTS
    for (int i = 0; i < MAX_STUDENTS; i++) {
        Student s;
        s.id = i + 1;
        sprintf(s.name, "Student%d", i + 1);
        sprintf(s.email, "student%d@mail.com", i + 1);
        sprintf(s.phone, "%010d", 1000000000 + i);
        s.grade = 50 + (i % 50);
        strcpy(s.department, "CS");
        s.year = 1 + (i % 4);

        int result = add_student(s);
        if (result != 1) {
            printf("  ✗ FAIL: Failed to add student at position %d\n", i);
            tests_failed++;
            return;
        }
    }

    printf("  ✓ Successfully added %d students\n", MAX_STUDENTS);
    tests_passed++;

    // Try to add one more - should fail
    Student extra = {999, "Extra", "extra@mail.com", "9999999999", 80, "CS", 1};
    int result = add_student(extra);

    ASSERT_EQUAL(result, 0, "add_student should return 0 when database is full");
    ASSERT_EQUAL(total_students, MAX_STUDENTS, "total_students should remain MAX_STUDENTS");
}

// ========================================
// Main test execution
// ========================================
int main() {
    printf("========================================\n");
    printf("Issue #1: add_student Tests\n");
    printf("========================================\n");

    test_add_student_single();
    test_add_student_multiple();
    test_add_student_full_database();

    printf("\n========================================\n");
    printf("Test Results:\n");
    printf("  Passed: %d\n", tests_passed);
    printf("  Failed: %d\n", tests_failed);
    printf("========================================\n");

    return tests_failed > 0 ? 1 : 0;
}
