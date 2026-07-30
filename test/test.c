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
// Issue #2 Tests: delete_student_by_id
// ========================================

void test_delete_student_single() {
    printf("\nTest: Delete single student\n");
    setup();

    // Add a student
    Student s = {1, "John Doe", "john@mail.com", "9999999999", 85, "CS", 2};
    add_student(s);
    ASSERT_EQUAL(total_students, 1, "total_students should be 1 after adding");

    // Delete the student
    int result = delete_student_by_id(1);

    ASSERT_EQUAL(result, 1, "delete_student_by_id should return 1 on success");
    ASSERT_EQUAL(total_students, 0, "total_students should be 0 after deleting");
}

void test_delete_nonexistent_student() {
    printf("\nTest: Delete non-existent student\n");
    setup();

    // Try to delete student that doesn't exist
    int result = delete_student_by_id(999);

    ASSERT_EQUAL(result, 0, "delete_student_by_id should return 0 if not found");
    ASSERT_EQUAL(total_students, 0, "total_students should remain 0");
}

void test_delete_and_shift() {
    printf("\nTest: Delete student and verify shift\n");
    setup();

    // Add 3 students
    Student s1 = {1, "Alice", "alice@mail.com", "1111111111", 90, "CS", 1};
    Student s2 = {2, "Bob", "bob@mail.com", "2222222222", 75, "IT", 2};
    Student s3 = {3, "Charlie", "charlie@mail.com", "3333333333", 88, "ECE", 3};

    add_student(s1);
    add_student(s2);
    add_student(s3);
    ASSERT_EQUAL(total_students, 3, "total_students should be 3");

    // Delete middle student (ID=2)
    int result = delete_student_by_id(2);

    ASSERT_EQUAL(result, 1, "delete_student_by_id should return 1");
    ASSERT_EQUAL(total_students, 2, "total_students should be 2 after delete");

    // Verify remaining students are shifted correctly
    ASSERT_EQUAL(students[0].id, 1, "First student should be Alice (ID=1)");
    ASSERT_EQUAL(students[1].id, 3, "Second student should be Charlie (ID=3)");
}

// ========================================
// Main test execution
// ========================================
// ========================================
// Issue #3-#10: Get/Retrieve Functions Tests
// ========================================

void test_get_student_by_id_found() {
    printf("\nTest: Get student by ID - found\n");
    setup();
    Student s = {1, "Alice", "alice@mail.com", "1111111111", 90, "CS", 1};
    add_student(s);
    Student result = {0};
    int ret = get_student_by_id(1, &result);
    ASSERT_EQUAL(ret, 1, "Should return 1 when student found");
}

void test_get_total_students_count() {
    printf("\nTest: Get total students count\n");
    setup();
    ASSERT_EQUAL(get_total_students_count(), 0, "Count should be 0");
    Student s = {1, "Alice", "alice@mail.com", "1111111111", 90, "CS", 1};
    add_student(s);
    ASSERT_EQUAL(get_total_students_count(), 1, "Count should be 1");
}

void test_student_exists() {
    printf("\nTest: Student exists\n");
    setup();
    Student s = {5, "David", "david@mail.com", "5555555555", 92, "CS", 4};
    add_student(s);
    ASSERT_EQUAL(student_exists(5), 1, "Should exist");
}

void test_is_database_empty() {
    printf("\nTest: Database empty check\n");
    setup();
    ASSERT_EQUAL(is_database_empty(), 1, "Should be empty");
    Student s = {1, "Alice", "alice@mail.com", "1111111111", 90, "CS", 1};
    add_student(s);
    ASSERT_EQUAL(is_database_empty(), 0, "Should not be empty");
}

// ========================================
// Issue #21-#35: Validation Functions Tests
// ========================================

void test_is_valid_student_id() {
    printf("\nTest: Validate student ID\n");
    setup();
    ASSERT_EQUAL(is_valid_student_id(1), 1, "ID 1 valid");
    ASSERT_EQUAL(is_valid_student_id(0), 0, "ID 0 invalid");
}

void test_is_valid_grade() {
    printf("\nTest: Validate grade\n");
    setup();
    ASSERT_EQUAL(is_valid_grade(50), 1, "Grade 50 valid");
    ASSERT_EQUAL(is_valid_grade(101), 0, "Grade 101 invalid");
}

void test_is_valid_year() {
    printf("\nTest: Validate year\n");
    setup();
    ASSERT_EQUAL(is_valid_year(1), 1, "Year 1 valid");
    ASSERT_EQUAL(is_valid_year(5), 0, "Year 5 invalid");
}

void test_check_duplicate_id() {
    printf("\nTest: Check duplicate ID\n");
    setup();
    Student s = {1, "Alice", "alice@mail.com", "1111111111", 90, "CS", 1};
    add_student(s);
    ASSERT_EQUAL(check_duplicate_id(1), 1, "ID 1 exists");
}

// ========================================
// Issue #51-#60: Sorting Functions Tests
// ========================================

void test_sort_students_by_id() {
    printf("\nTest: Sort by ID\n");
    setup();
    Student s1 = {3, "C", "c@mail.com", "3333333333", 88, "CS", 3};
    Student s2 = {1, "A", "a@mail.com", "1111111111", 90, "CS", 1};
    add_student(s1);
    add_student(s2);
    sort_students_by_id();
    ASSERT_EQUAL(students[0].id, 1, "First should be 1");
}

// ========================================
// Issue #61-#80: Statistics Functions Tests
// ========================================

void test_calculate_average_grade() {
    printf("\nTest: Calculate average grade\n");
    setup();
    Student s1 = {1, "A", "a@mail.com", "1111111111", 80, "CS", 1};
    Student s2 = {2, "B", "b@mail.com", "2222222222", 90, "IT", 2};
    add_student(s1);
    add_student(s2);
    double avg = calculate_average_grade();
    ASSERT_EQUAL(avg > 80, 1, "Average should be > 80");
}

void test_get_max_grade() {
    printf("\nTest: Get max grade\n");
    setup();
    Student s1 = {1, "A", "a@mail.com", "1111111111", 75, "CS", 1};
    Student s2 = {2, "B", "b@mail.com", "2222222222", 95, "IT", 2};
    add_student(s1);
    add_student(s2);
    int max = get_max_grade();
    ASSERT_EQUAL(max, 95, "Max should be 95");
}

void test_get_min_grade() {
    printf("\nTest: Get min grade\n");
    setup();
    Student s1 = {1, "A", "a@mail.com", "1111111111", 65, "CS", 1};
    Student s2 = {2, "B", "b@mail.com", "2222222222", 85, "IT", 2};
    add_student(s1);
    add_student(s2);
    int min = get_min_grade();
    ASSERT_EQUAL(min, 65, "Min should be 65");
}

void test_count_students_passed() {
    printf("\nTest: Count passed\n");
    setup();
    Student s1 = {1, "A", "a@mail.com", "1111111111", 70, "CS", 1};
    Student s2 = {2, "B", "b@mail.com", "2222222222", 50, "IT", 2};
    add_student(s1);
    add_student(s2);
    int passed = count_students_passed();
    ASSERT_EQUAL(passed, 1, "1 passed");
}

// ========================================
// Issue #81-#95: String Functions Tests
// ========================================

void test_get_string_length() {
    printf("\nTest: String length\n");
    setup();
    int len = get_string_length("hello");
    ASSERT_EQUAL(len, 5, "Length 5");
}

void test_count_vowels_in_string() {
    printf("\nTest: Count vowels\n");
    setup();
    int vowels = count_vowels_in_string("hello");
    ASSERT_EQUAL(vowels, 2, "2 vowels");
}

void test_string_contains_substring() {
    printf("\nTest: Contains substring\n");
    setup();
    ASSERT_EQUAL(string_contains_substring("hello world", "world"), 1, "Contains");
}

// ========================================
// Issue #96-#120: Filter/Compare Functions
// ========================================

void test_compare_two_students() {
    printf("\nTest: Compare students\n");
    setup();
    Student s1 = {1, "A", "a@mail.com", "1111111111", 80, "CS", 1};
    Student s2 = {2, "B", "b@mail.com", "2222222222", 90, "IT", 2};
    add_student(s1);
    add_student(s2);
    int cmp = compare_two_students(1, 2);
    ASSERT_EQUAL(cmp < 0, 1, "A < B");
}

int main() {
    printf("========================================\n");
    printf("Student Management System - Test Suite\n");
    printf("========================================\n");

    printf("\n========================================\n");
    printf("Issue #1: add_student Tests\n");
    printf("========================================\n");
    test_add_student_single();
    test_add_student_multiple();
    test_add_student_full_database();

    printf("\n========================================\n");
    printf("Issue #2: delete_student_by_id Tests\n");
    printf("========================================\n");
    test_delete_student_single();
    test_delete_nonexistent_student();
    test_delete_and_shift();

    printf("\n========================================\n");
    printf("Issue #3-#10: Get/Retrieve Functions\n");
    printf("========================================\n");
    test_get_student_by_id_found();
    test_get_total_students_count();
    test_student_exists();
    test_is_database_empty();

    printf("\n========================================\n");
    printf("Issue #21-#35: Validation Functions\n");
    printf("========================================\n");
    test_is_valid_student_id();
    test_is_valid_grade();
    test_is_valid_year();
    test_check_duplicate_id();

    printf("\n========================================\n");
    printf("Issue #51-#60: Sorting Functions\n");
    printf("========================================\n");
    test_sort_students_by_id();

    printf("\n========================================\n");
    printf("Issue #61-#80: Statistics Functions\n");
    printf("========================================\n");
    test_calculate_average_grade();
    test_get_max_grade();
    test_get_min_grade();
    test_count_students_passed();

    printf("\n========================================\n");
    printf("Issue #81-#95: String Functions\n");
    printf("========================================\n");
    test_get_string_length();
    test_count_vowels_in_string();
    test_string_contains_substring();

    printf("\n========================================\n");
    printf("Issue #96-#120: Filter/Compare Functions\n");
    printf("========================================\n");
    test_compare_two_students();

    printf("\n========================================\n");
    printf("Test Results:\n");
    printf("  Passed: %d\n", tests_passed);
    printf("  Failed: %d\n", tests_failed);
    printf("========================================\n");

    return tests_failed > 0 ? 1 : 0;
}
