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


// ========================================
// Shared test fixture: 5 known students
// ========================================
// id | name            | email              | phone        | grade | dept | year
//  1 | Alice Johnson    | alice@mail.com     | 1111111111   | 90    | CS   | 1
//  2 | Bob Smith        | bob@mail.com       | 2222222222   | 75    | IT   | 2
//  3 | Charlie Brown    | charlie@mail.com   | 3333333333   | 88    | CS   | 3
//  4 | Diana Prince     | diana@mail.com     | 4444444444   | 60    | ECE  | 4
//  5 | Eve Adams        | eve@mail.com       | 5555555555   | 45    | IT   | 1
void seed_five(void) {
    Student s1 = {1, "Alice Johnson", "alice@mail.com", "1111111111", 90, "CS", 1};
    Student s2 = {2, "Bob Smith", "bob@mail.com", "2222222222", 75, "IT", 2};
    Student s3 = {3, "Charlie Brown", "charlie@mail.com", "3333333333", 88, "CS", 3};
    Student s4 = {4, "Diana Prince", "diana@mail.com", "4444444444", 60, "ECE", 4};
    Student s5 = {5, "Eve Adams", "eve@mail.com", "5555555555", 45, "IT", 1};
    add_student(s1);
    add_student(s2);
    add_student(s3);
    add_student(s4);
    add_student(s5);
}


// ========================================
// Issue #4-#6, #19: Getter Functions Tests
// ========================================

void test_get_student_by_email() {
    printf("\nTest: Get student by email\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = get_student_by_email("bob@mail.com", &out_s);
    ASSERT_EQUAL(found, 1, "Should find student by email");
    ASSERT_EQUAL(found == 1 && out_s.id == 2, 1, "Found student should have ID 2");
    int not_found = get_student_by_email("nobody@mail.com", &out_s);
    ASSERT_EQUAL(not_found, 0, "Should return 0 for unknown email");
}

void test_get_student_by_name() {
    printf("\nTest: Get student by name\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = get_student_by_name("Charlie Brown", &out_s);
    ASSERT_EQUAL(found, 1, "Should find student by name");
    ASSERT_EQUAL(found == 1 && out_s.id == 3, 1, "Found student should have ID 3");
    int not_found = get_student_by_name("Nobody", &out_s);
    ASSERT_EQUAL(not_found, 0, "Should return 0 for unknown name");
}

void test_get_all_students() {
    printf("\nTest: Get all students\n");
    setup();
    seed_five();
    Student *all = get_all_students();
    if (all != NULL) {
        ASSERT_EQUAL(all[0].id, 1, "First student in returned array should have ID 1");
        ASSERT_EQUAL(all[4].id, 5, "Fifth student in returned array should have ID 5");
    } else {
        printf("  FAIL: get_all_students should not return NULL when database is populated\n");
        tests_failed += 2;
    }
}

void test_get_student_by_phone() {
    printf("\nTest: Get student by phone\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = get_student_by_phone("3333333333", &out_s);
    ASSERT_EQUAL(found, 1, "Should find student by phone");
    ASSERT_EQUAL(found == 1 && out_s.id == 3, 1, "Found student should have ID 3");
    int not_found = get_student_by_phone("0000000000", &out_s);
    ASSERT_EQUAL(not_found, 0, "Should return 0 for unknown phone");
}


// ========================================
// Issue #9-#14: Update Functions Tests
// ========================================

void test_update_student_name() {
    printf("\nTest: Update student name\n");
    setup();
    seed_five();
    int result = update_student_name(1, "Alicia Johnson");
    ASSERT_EQUAL(result, 1, "Should return 1 on success");
    ASSERT_STRING_EQUAL(students[0].name, "Alicia Johnson", "Name should be updated");
    int missing = update_student_name(999, "Nobody");
    ASSERT_EQUAL(missing, 0, "Should return 0 for unknown ID");
}

void test_update_student_email() {
    printf("\nTest: Update student email\n");
    setup();
    seed_five();
    int result = update_student_email(2, "bobby@mail.com");
    ASSERT_EQUAL(result, 1, "Should return 1 on success");
    ASSERT_STRING_EQUAL(students[1].email, "bobby@mail.com", "Email should be updated");
    int missing = update_student_email(999, "nobody@mail.com");
    ASSERT_EQUAL(missing, 0, "Should return 0 for unknown ID");
}

void test_update_student_phone() {
    printf("\nTest: Update student phone\n");
    setup();
    seed_five();
    int result = update_student_phone(3, "9998887777");
    ASSERT_EQUAL(result, 1, "Should return 1 on success");
    ASSERT_STRING_EQUAL(students[2].phone, "9998887777", "Phone should be updated");
    int missing = update_student_phone(999, "0000000000");
    ASSERT_EQUAL(missing, 0, "Should return 0 for unknown ID");
}

void test_update_student_grade() {
    printf("\nTest: Update student grade\n");
    setup();
    seed_five();
    int result = update_student_grade(4, 95);
    ASSERT_EQUAL(result, 1, "Should return 1 on success");
    ASSERT_EQUAL(students[3].grade, 95, "Grade should be updated");
    int missing = update_student_grade(999, 50);
    ASSERT_EQUAL(missing, 0, "Should return 0 for unknown ID");
}

void test_update_student_department() {
    printf("\nTest: Update student department\n");
    setup();
    seed_five();
    int result = update_student_department(5, "Math");
    ASSERT_EQUAL(result, 1, "Should return 1 on success");
    ASSERT_STRING_EQUAL(students[4].department, "Math", "Department should be updated");
    int missing = update_student_department(999, "Math");
    ASSERT_EQUAL(missing, 0, "Should return 0 for unknown ID");
}

void test_update_student_year() {
    printf("\nTest: Update student year\n");
    setup();
    seed_five();
    int result = update_student_year(1, 3);
    ASSERT_EQUAL(result, 1, "Should return 1 on success");
    ASSERT_EQUAL(students[0].year, 3, "Year should be updated");
    int missing = update_student_year(999, 2);
    ASSERT_EQUAL(missing, 0, "Should return 0 for unknown ID");
}


// ========================================
// Issue #15-#17, #20: Print/Clear/Duplicate Tests
// ========================================

void test_print_student_details() {
    printf("\nTest: Print student details (manual visual check)\n");
    setup();
    seed_five();
    print_student_details(1);
    printf("  (no crash printing an existing student)\n");
    tests_passed++;
    print_student_details(999);
    printf("  (no crash printing a missing student)\n");
    tests_passed++;
}

void test_print_all_students() {
    printf("\nTest: Print all students (manual visual check)\n");
    setup();
    seed_five();
    print_all_students();
    printf("  (no crash printing a populated database)\n");
    tests_passed++;
    setup();
    print_all_students();
    printf("  (no crash printing an empty database)\n");
    tests_passed++;
}

void test_clear_all_students() {
    printf("\nTest: Clear all students\n");
    setup();
    seed_five();
    ASSERT_EQUAL(total_students, 5, "Should have 5 students before clearing");
    clear_all_students();
    ASSERT_EQUAL(total_students, 0, "total_students should be 0 after clearing");
}

void test_duplicate_student_record() {
    printf("\nTest: Duplicate student record\n");
    setup();
    seed_five();
    int before = total_students;
    int result = duplicate_student_record(2);
    ASSERT_EQUAL(result, 1, "Should return 1 on success when source ID exists");
    ASSERT_EQUAL(total_students, before + 1, "total_students should increase by 1");
    int missing = duplicate_student_record(999);
    ASSERT_EQUAL(missing, 0, "Should return 0 when source ID does not exist");
}


// ========================================
// Issue #22-#35: Validation Functions Tests
// ========================================

void test_is_valid_email() {
    printf("\nTest: Validate email\n");
    setup();
    ASSERT_EQUAL(is_valid_email("alice@mail.com"), 1, "Well-formed email should be valid");
    ASSERT_EQUAL(is_valid_email("not-an-email"), 0, "Email without @ should be invalid");
    ASSERT_EQUAL(is_valid_email(""), 0, "Empty email should be invalid");
}

void test_is_valid_phone() {
    printf("\nTest: Validate phone\n");
    setup();
    ASSERT_EQUAL(is_valid_phone("1234567890"), 1, "10-digit phone should be valid");
    ASSERT_EQUAL(is_valid_phone("12abc"), 0, "Phone with letters should be invalid");
    ASSERT_EQUAL(is_valid_phone(""), 0, "Empty phone should be invalid");
}

void test_is_valid_name() {
    printf("\nTest: Validate name\n");
    setup();
    ASSERT_EQUAL(is_valid_name("Alice Johnson"), 1, "Non-empty name should be valid");
    ASSERT_EQUAL(is_valid_name(""), 0, "Empty name should be invalid");
}

void test_is_valid_department() {
    printf("\nTest: Validate department\n");
    setup();
    ASSERT_EQUAL(is_valid_department("CS"), 1, "Non-empty department should be valid");
    ASSERT_EQUAL(is_valid_department(""), 0, "Empty department should be invalid");
}

void test_is_valid_age() {
    printf("\nTest: Validate age\n");
    setup();
    ASSERT_EQUAL(is_valid_age(20), 1, "Age 20 should be valid (18-60)");
    ASSERT_EQUAL(is_valid_age(10), 0, "Age 10 should be invalid");
    ASSERT_EQUAL(is_valid_age(65), 0, "Age 65 should be invalid");
}

void test_check_duplicate_email() {
    printf("\nTest: Check duplicate email\n");
    setup();
    seed_five();
    ASSERT_EQUAL(check_duplicate_email("alice@mail.com"), 1, "Existing email should be flagged as duplicate");
    ASSERT_EQUAL(check_duplicate_email("nobody@mail.com"), 0, "Unknown email should not be a duplicate");
}

void test_check_duplicate_phone() {
    printf("\nTest: Check duplicate phone\n");
    setup();
    seed_five();
    ASSERT_EQUAL(check_duplicate_phone("1111111111"), 1, "Existing phone should be flagged as duplicate");
    ASSERT_EQUAL(check_duplicate_phone("0000000000"), 0, "Unknown phone should not be a duplicate");
}

void test_is_name_only_alphabetic() {
    printf("\nTest: Name is only alphabetic\n");
    setup();
    ASSERT_EQUAL(is_name_only_alphabetic("Alice"), 1, "Pure alphabetic name should be valid");
    ASSERT_EQUAL(is_name_only_alphabetic("Alice123"), 0, "Name with digits should be invalid");
}

void test_is_email_contains_at() {
    printf("\nTest: Email contains @\n");
    setup();
    ASSERT_EQUAL(is_email_contains_at("alice@mail.com"), 1, "Email with @ should return 1");
    ASSERT_EQUAL(is_email_contains_at("alicemail.com"), 0, "Email without @ should return 0");
}

void test_is_phone_only_digits() {
    printf("\nTest: Phone is only digits\n");
    setup();
    ASSERT_EQUAL(is_phone_only_digits("1234567890"), 1, "Pure digit phone should return 1");
    ASSERT_EQUAL(is_phone_only_digits("123-456"), 0, "Phone with dash should return 0");
}

void test_is_grade_within_range() {
    printf("\nTest: Grade within range\n");
    setup();
    ASSERT_EQUAL(is_grade_within_range(75), 1, "Grade 75 should be within range");
    ASSERT_EQUAL(is_grade_within_range(-5), 0, "Negative grade should be out of range");
    ASSERT_EQUAL(is_grade_within_range(150), 0, "Grade over 100 should be out of range");
}


// ========================================
// Issue #36-#50: Search Functions Tests
// ========================================

void test_search_student_by_id() {
    printf("\nTest: Search student by ID\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = search_student_by_id(3, &out_s);
    ASSERT_EQUAL(found, 1, "Should find student with ID 3");
    ASSERT_EQUAL(found == 1 && out_s.id == 3, 1, "Result should have ID 3");
    int not_found = search_student_by_id(999, &out_s);
    ASSERT_EQUAL(not_found, 0, "Should return 0 for unknown ID");
}

void test_search_student_by_email() {
    printf("\nTest: Search student by email\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = search_student_by_email("eve@mail.com", &out_s);
    ASSERT_EQUAL(found, 1, "Should find student by email");
    ASSERT_EQUAL(found == 1 && out_s.id == 5, 1, "Result should have ID 5");
    int not_found = search_student_by_email("nobody@mail.com", &out_s);
    ASSERT_EQUAL(not_found, 0, "Should return 0 for unknown email");
}

void test_search_student_by_name() {
    printf("\nTest: Search student by name\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = search_student_by_name("Diana Prince", &out_s);
    ASSERT_EQUAL(found, 1, "Should find student by name");
    ASSERT_EQUAL(found == 1 && out_s.id == 4, 1, "Result should have ID 4");
    int not_found = search_student_by_name("Nobody", &out_s);
    ASSERT_EQUAL(not_found, 0, "Should return 0 for unknown name");
}

void test_search_students_by_department() {
    printf("\nTest: Search students by department\n");
    setup();
    seed_five();
    Student results[10];
    int count = search_students_by_department("CS", results, 10);
    ASSERT_EQUAL(count, 2, "Should find 2 CS students (Alice, Charlie)");
    int none = search_students_by_department("Math", results, 10);
    ASSERT_EQUAL(none, 0, "Should find 0 students in unknown department");
}

void test_search_students_by_year() {
    printf("\nTest: Search students by year\n");
    setup();
    seed_five();
    Student results[10];
    int count = search_students_by_year(1, results, 10);
    ASSERT_EQUAL(count, 2, "Should find 2 students in year 1 (Alice, Eve)");
    int none = search_students_by_year(9, results, 10);
    ASSERT_EQUAL(none, 0, "Should find 0 students in unused year");
}

void test_search_students_by_grade_range() {
    printf("\nTest: Search students by grade range\n");
    setup();
    seed_five();
    Student results[10];
    int count = search_students_by_grade_range(70, 90, results, 10);
    ASSERT_EQUAL(count, 3, "Grades 70-90 should match Alice(90), Bob(75), Charlie(88)");
    int none = search_students_by_grade_range(1, 10, results, 10);
    ASSERT_EQUAL(none, 0, "Should find 0 students in an empty grade range");
}

void test_search_students_above_gpa() {
    printf("\nTest: Search students above GPA threshold\n");
    setup();
    seed_five();
    Student results[10];
    int count = search_students_above_gpa(80, results, 10);
    ASSERT_EQUAL(count, 2, "Grades above 80 should match Alice(90), Charlie(88)");
    int none = search_students_above_gpa(100, results, 10);
    ASSERT_EQUAL(none, 0, "No student should have grade above 100");
}

void test_search_students_below_gpa() {
    printf("\nTest: Search students below GPA threshold\n");
    setup();
    seed_five();
    Student results[10];
    int count = search_students_below_gpa(60, results, 10);
    ASSERT_EQUAL(count, 1, "Grade below 60 should match Eve(45)");
    int none = search_students_below_gpa(0, results, 10);
    ASSERT_EQUAL(none, 0, "No student should have grade below 0");
}

void test_search_students_with_same_department() {
    printf("\nTest: Search students with same department\n");
    setup();
    seed_five();
    Student results[10];
    int count = search_students_with_same_department("IT", results, 10);
    ASSERT_EQUAL(count, 2, "IT department should match Bob and Eve");
    int none = search_students_with_same_department("History", results, 10);
    ASSERT_EQUAL(none, 0, "Unknown department should match 0 students");
}

void test_search_first_student_in_range() {
    printf("\nTest: Search first student in grade range\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = search_first_student_in_range(70, 90, &out_s);
    ASSERT_EQUAL(found, 1, "Should find a student in range 70-90");
    int none = search_first_student_in_range(1, 10, &out_s);
    ASSERT_EQUAL(none, 0, "Should return 0 when no student is in range");
}

void test_search_last_student_in_range() {
    printf("\nTest: Search last student in grade range\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = search_last_student_in_range(70, 90, &out_s);
    ASSERT_EQUAL(found, 1, "Should find a student in range 70-90");
    int none = search_last_student_in_range(1, 10, &out_s);
    ASSERT_EQUAL(none, 0, "Should return 0 when no student is in range");
}

void test_count_search_results() {
    printf("\nTest: Count search results in grade range\n");
    setup();
    seed_five();
    int count = count_search_results(70, 90);
    ASSERT_EQUAL(count, 3, "Grades 70-90 should count Alice, Bob, Charlie");
    int none = count_search_results(1, 10);
    ASSERT_EQUAL(none, 0, "No student should be in range 1-10");
}

void test_search_by_multiple_criteria() {
    printf("\nTest: Search by multiple criteria (department AND year)\n");
    setup();
    seed_five();
    Student results[10];
    int count = search_by_multiple_criteria("CS", 1, results, 10);
    ASSERT_EQUAL(count, 1, "CS + year 1 should match only Alice");
    int none = search_by_multiple_criteria("CS", 4, results, 10);
    ASSERT_EQUAL(none, 0, "CS + year 4 should match nobody");
}

void test_search_students_starting_with() {
    printf("\nTest: Search students whose name starts with a letter\n");
    setup();
    seed_five();
    Student results[10];
    int count = search_students_starting_with('A', results, 10);
    ASSERT_EQUAL(count, 1, "Letter 'A' should match Alice");
    int none = search_students_starting_with('Z', results, 10);
    ASSERT_EQUAL(none, 0, "Letter 'Z' should match nobody");
}

void test_binary_search_by_id() {
    printf("\nTest: Binary search by ID (array must be sorted by ID first)\n");
    setup();
    seed_five();
    sort_students_by_id();
    Student out_s = {0};
    int found = binary_search_by_id(4, &out_s);
    ASSERT_EQUAL(found, 1, "Should find ID 4 in a sorted array");
    ASSERT_EQUAL(found == 1 && out_s.id == 4, 1, "Result should have ID 4");
    int missing = binary_search_by_id(999, &out_s);
    ASSERT_EQUAL(missing, 0, "Should return 0 for an absent ID");
}


// ========================================
// Issue #51-#60: Sorting Functions Tests
// ========================================

void test_sort_students_by_name() {
    printf("\nTest: Sort by name\n");
    setup();
    seed_five();
    sort_students_by_name();
    ASSERT_STRING_EQUAL(students[0].name, "Alice Johnson", "First student alphabetically should be Alice Johnson");
    ASSERT_STRING_EQUAL(students[4].name, "Eve Adams", "Last student alphabetically should be Eve Adams");
}

void test_sort_students_by_grade() {
    printf("\nTest: Sort by grade\n");
    setup();
    seed_five();
    sort_students_by_grade();
    ASSERT_EQUAL(students[0].grade, 45, "First student should have lowest grade (45)");
    ASSERT_EQUAL(students[4].grade, 90, "Last student should have highest grade (90)");
}

void test_sort_students_by_email() {
    printf("\nTest: Sort by email\n");
    setup();
    seed_five();
    sort_students_by_email();
    ASSERT_STRING_EQUAL(students[0].email, "alice@mail.com", "First email alphabetically should be alice@mail.com");
}

void test_sort_students_by_department() {
    printf("\nTest: Sort by department\n");
    setup();
    seed_five();
    sort_students_by_department();
    ASSERT_STRING_EQUAL(students[0].department, "CS", "First department alphabetically should be CS");
}

void test_sort_students_by_year() {
    printf("\nTest: Sort by year\n");
    setup();
    seed_five();
    sort_students_by_year();
    ASSERT_EQUAL(students[0].year <= students[4].year, 1, "Years should be in ascending order after sort");
}

void test_sort_descending_by_grade() {
    printf("\nTest: Sort descending by grade\n");
    setup();
    seed_five();
    sort_descending_by_grade();
    ASSERT_EQUAL(students[0].grade, 90, "First student should have highest grade (90)");
    ASSERT_EQUAL(students[4].grade, 45, "Last student should have lowest grade (45)");
}

void test_sort_descending_by_name() {
    printf("\nTest: Sort descending by name\n");
    setup();
    seed_five();
    sort_descending_by_name();
    ASSERT_STRING_EQUAL(students[0].name, "Eve Adams", "First name descending should be Eve Adams");
}

void test_sort_by_grade_then_name() {
    printf("\nTest: Multi-key sort (grade then name)\n");
    setup();
    seed_five();
    sort_by_grade_then_name();
    ASSERT_EQUAL(students[0].grade <= students[4].grade, 1, "Grades should be in ascending order after multi-key sort");
}

void test_is_student_array_sorted() {
    printf("\nTest: Check if student array is sorted by ID\n");
    setup();
    seed_five();
    sort_students_by_id();
    ASSERT_EQUAL(is_student_array_sorted(), 1, "Array sorted by ID should report as sorted");
}


// ========================================
// Issue #61-#80: Statistics Functions Tests
// ========================================

void test_get_median_grade() {
    printf("\nTest: Get median grade\n");
    setup();
    seed_five();
    int median = get_median_grade();
    ASSERT_EQUAL(median, 75, "Median of {45,60,75,88,90} should be 75");
}

void test_get_mode_grade() {
    printf("\nTest: Get mode grade\n");
    setup();
    seed_five();
    int mode = get_mode_grade();
    ASSERT_EQUAL(mode == 45 || mode == 60 || mode == 75 || mode == 88 || mode == 90, 1,
                 "Mode should be one of the existing grades (all distinct in this fixture)");
}

void test_get_grade_range() {
    printf("\nTest: Get grade range (max - min)\n");
    setup();
    seed_five();
    int range = get_grade_range();
    ASSERT_EQUAL(range, 45, "Range of {45..90} should be 90 - 45 = 45");
}

void test_get_student_rank() {
    printf("\nTest: Get student rank by grade\n");
    setup();
    seed_five();
    int rank = get_student_rank(1);
    ASSERT_EQUAL(rank, 1, "Alice (grade 90, highest) should be rank 1");
}

void test_get_student_percentile() {
    printf("\nTest: Get student percentile\n");
    setup();
    seed_five();
    double pct = get_student_percentile(1);
    ASSERT_EQUAL(pct >= 0.0 && pct <= 100.0, 1, "Percentile should be between 0 and 100");
}

void test_count_students_failed() {
    printf("\nTest: Count students failed (grade < 60)\n");
    setup();
    seed_five();
    int failed = count_students_failed();
    ASSERT_EQUAL(failed, 1, "Only Eve (45) should count as failed");
}

void test_get_pass_percentage() {
    printf("\nTest: Get pass percentage\n");
    setup();
    seed_five();
    double pct = get_pass_percentage();
    ASSERT_EQUAL(pct > 79.0 && pct < 81.0, 1, "4/5 passing should be ~80%%");
}

void test_get_pass_fail_ratio() {
    printf("\nTest: Get pass/fail ratio\n");
    setup();
    seed_five();
    double ratio = get_pass_fail_ratio();
    ASSERT_EQUAL(ratio > 3.9 && ratio < 4.1, 1, "4 passed : 1 failed should give ratio ~4.0");
}

void test_get_average_by_department() {
    printf("\nTest: Get average grade by department\n");
    setup();
    seed_five();
    double avg = get_average_by_department("CS");
    ASSERT_EQUAL(avg > 88.0 && avg < 90.0, 1, "CS average of (90+88)/2 should be ~89");
}

void test_get_students_per_department() {
    printf("\nTest: Get student count per department\n");
    setup();
    seed_five();
    int count = get_students_per_department("IT");
    ASSERT_EQUAL(count, 2, "IT should have 2 students (Bob, Eve)");
}

void test_get_top_performer_name() {
    printf("\nTest: Get top performer name\n");
    setup();
    seed_five();
    char *name = get_top_performer_name();
    if (name != NULL) {
        ASSERT_STRING_EQUAL(name, "Alice Johnson", "Top performer (grade 90) should be Alice Johnson");
    } else {
        printf("  FAIL: get_top_performer_name should not return NULL when database is populated\n");
        tests_failed++;
    }
}

void test_get_bottom_performer_name() {
    printf("\nTest: Get bottom performer name\n");
    setup();
    seed_five();
    char *name = get_bottom_performer_name();
    if (name != NULL) {
        ASSERT_STRING_EQUAL(name, "Eve Adams", "Bottom performer (grade 45) should be Eve Adams");
    } else {
        printf("  FAIL: get_bottom_performer_name should not return NULL when database is populated\n");
        tests_failed++;
    }
}

void test_calculate_standard_deviation() {
    printf("\nTest: Calculate standard deviation\n");
    setup();
    seed_five();
    double sd = calculate_standard_deviation();
    ASSERT_EQUAL(sd > 0.0, 1, "Standard deviation of varied grades should be positive");
}

void test_get_honor_roll_count() {
    printf("\nTest: Get honor roll count (top 10%%)\n");
    setup();
    seed_five();
    int count = get_honor_roll_count();
    ASSERT_EQUAL(count >= 0 && count <= total_students, 1, "Honor roll count should be between 0 and total_students");
}

void test_get_gpa_statistics() {
    printf("\nTest: Get GPA statistics summary\n");
    setup();
    seed_five();
    double stats = get_gpa_statistics();
    ASSERT_EQUAL(stats >= 0.0, 1, "GPA statistics value should be non-negative");
}

void test_count_students_in_range() {
    printf("\nTest: Count students in grade range\n");
    setup();
    seed_five();
    int count = count_students_in_range(70, 90);
    ASSERT_EQUAL(count, 3, "Grades 70-90 should count Alice, Bob, Charlie");
}


// ========================================
// Issue #81-#95: String Functions Tests
// ========================================

void test_string_to_uppercase() {
    printf("\nTest: String to uppercase\n");
    setup();
    char buf[50] = "Hello World";
    char *result = string_to_uppercase(buf);
    if (result != NULL) {
        ASSERT_STRING_EQUAL(result, "HELLO WORLD", "Should convert to uppercase");
    } else {
        printf("  FAIL: string_to_uppercase should not return NULL\n");
        tests_failed++;
    }
}

void test_string_to_lowercase() {
    printf("\nTest: String to lowercase\n");
    setup();
    char buf[50] = "Hello World";
    char *result = string_to_lowercase(buf);
    if (result != NULL) {
        ASSERT_STRING_EQUAL(result, "hello world", "Should convert to lowercase");
    } else {
        printf("  FAIL: string_to_lowercase should not return NULL\n");
        tests_failed++;
    }
}

void test_trim_whitespace() {
    printf("\nTest: Trim whitespace\n");
    setup();
    char buf[50] = "  Hello World  ";
    char *result = trim_whitespace(buf);
    if (result != NULL) {
        ASSERT_STRING_EQUAL(result, "Hello World", "Should remove leading/trailing spaces");
    } else {
        printf("  FAIL: trim_whitespace should not return NULL\n");
        tests_failed++;
    }
}

void test_reverse_string() {
    printf("\nTest: Reverse string\n");
    setup();
    char buf[50] = "Hello";
    char *result = reverse_string(buf);
    if (result != NULL) {
        ASSERT_STRING_EQUAL(result, "olleH", "Should reverse the characters");
    } else {
        printf("  FAIL: reverse_string should not return NULL\n");
        tests_failed++;
    }
}

void test_compare_strings() {
    printf("\nTest: Compare strings (case-sensitive)\n");
    setup();
    ASSERT_EQUAL(compare_strings("Hello", "Hello"), 1, "Identical strings should be equal (1)");
    ASSERT_EQUAL(compare_strings("Hello", "hello"), 0, "Case-sensitive mismatch should not be equal (0)");
}

void test_compare_strings_ignore_case() {
    printf("\nTest: Compare strings (case-insensitive)\n");
    setup();
    ASSERT_EQUAL(compare_strings_ignore_case("Hello", "hello"), 1, "Case-insensitive match should be equal (1)");
    ASSERT_EQUAL(compare_strings_ignore_case("Hello", "World"), 0, "Different strings should not be equal (0)");
}

void test_get_substring() {
    printf("\nTest: Get substring\n");
    setup();
    char *result = get_substring("Hello World", 0, 5);
    if (result != NULL) {
        ASSERT_STRING_EQUAL(result, "Hello", "First 5 characters should be 'Hello'");
    } else {
        printf("  FAIL: get_substring should not return NULL\n");
        tests_failed++;
    }
}

void test_count_consonants_in_string() {
    printf("\nTest: Count consonants\n");
    setup();
    int count = count_consonants_in_string("hello");
    ASSERT_EQUAL(count, 3, "'hello' has 3 consonants (h,l,l)");
}

void test_is_palindrome() {
    printf("\nTest: Is palindrome\n");
    setup();
    ASSERT_EQUAL(is_palindrome("madam"), 1, "'madam' should be a palindrome");
    ASSERT_EQUAL(is_palindrome("hello"), 0, "'hello' should not be a palindrome");
}

void test_concatenate_strings() {
    printf("\nTest: Concatenate strings\n");
    setup();
    char *result = concatenate_strings("Hello ", "World");
    if (result != NULL) {
        ASSERT_STRING_EQUAL(result, "Hello World", "Should join into 'Hello World'");
    } else {
        printf("  FAIL: concatenate_strings should not return NULL\n");
        tests_failed++;
    }
}

void test_find_character_position() {
    printf("\nTest: Find character position\n");
    setup();
    int pos = find_character_position("Hello", 'e');
    ASSERT_EQUAL(pos, 1, "'e' is at index 1 in 'Hello'");
    int missing = find_character_position("Hello", 'z');
    ASSERT_EQUAL(missing, -1, "Character not present should return -1");
}

void test_count_character_occurrences() {
    printf("\nTest: Count character occurrences\n");
    setup();
    int count = count_character_occurrences("Hello", 'l');
    ASSERT_EQUAL(count, 2, "'l' appears twice in 'Hello'");
    int none = count_character_occurrences("Hello", 'z');
    ASSERT_EQUAL(none, 0, "'z' does not appear in 'Hello'");
}


// ========================================
// Issue #96-#107: Filter Functions Tests
// ========================================

void test_filter_students_by_gpa_above() {
    printf("\nTest: Filter students by GPA above threshold\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_students_by_gpa_above(80, results, 10);
    ASSERT_EQUAL(count, 2, "Grades above 80 should match Alice(90), Charlie(88)");
}

void test_filter_students_by_gpa_below() {
    printf("\nTest: Filter students by GPA below threshold\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_students_by_gpa_below(60, results, 10);
    ASSERT_EQUAL(count, 1, "Grade below 60 should match Eve(45)");
}

// NOTE: The Student struct has no "active" field. This is a smoke test only
// (verifies the call doesn't crash and returns a sane count) until the
// struct/requirements are clarified.
void test_filter_active_students() {
    printf("\nTest: Filter active students (smoke test - no 'active' field on Student)\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_active_students(results, 10);
    ASSERT_EQUAL(count >= 0 && count <= total_students, 1, "Count should be between 0 and total_students");
}

void test_filter_inactive_students() {
    printf("\nTest: Filter inactive students (smoke test - no 'active' field on Student)\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_inactive_students(results, 10);
    ASSERT_EQUAL(count >= 0 && count <= total_students, 1, "Count should be between 0 and total_students");
}

void test_filter_students_with_scholarship() {
    printf("\nTest: Filter students with scholarship (smoke test - no 'scholarship' field on Student)\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_students_with_scholarship(results, 10);
    ASSERT_EQUAL(count >= 0 && count <= total_students, 1, "Count should be between 0 and total_students");
}

void test_filter_students_without_scholarship() {
    printf("\nTest: Filter students without scholarship (smoke test - no 'scholarship' field on Student)\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_students_without_scholarship(results, 10);
    ASSERT_EQUAL(count >= 0 && count <= total_students, 1, "Count should be between 0 and total_students");
}

void test_filter_by_name_first_letter() {
    printf("\nTest: Filter by name first letter\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_by_name_first_letter('A', results, 10);
    ASSERT_EQUAL(count, 1, "Letter 'A' should match only Alice");
}

void test_filter_by_name_length() {
    printf("\nTest: Filter by name length\n");
    setup();
    seed_five();
    Student results[10];
    int len = (int)strlen("Bob Smith");
    int count = filter_by_name_length(len, results, 10);
    ASSERT_EQUAL(count >= 1, 1, "At least Bob Smith should match its own name length");
}

void test_filter_students_by_department() {
    printf("\nTest: Filter students by department\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_students_by_department("CS", results, 10);
    ASSERT_EQUAL(count, 2, "CS department should match Alice and Charlie");
}

void test_filter_students_enrolled_after() {
    printf("\nTest: Filter students enrolled after a given year (using struct 'year' field)\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_students_enrolled_after(1, results, 10);
    ASSERT_EQUAL(count >= 0 && count <= total_students, 1, "Count should be between 0 and total_students");
}

void test_filter_distinct_departments() {
    printf("\nTest: Filter distinct departments (smoke test)\n");
    setup();
    seed_five();
    char *results[10] = {0};
    int count = filter_distinct_departments(results);
    ASSERT_EQUAL(count == 3, 1, "Fixture has 3 distinct departments: CS, IT, ECE");
}

void test_filter_students_same_grade() {
    printf("\nTest: Filter students with the same exact grade\n");
    setup();
    seed_five();
    Student results[10];
    int count = filter_students_same_grade(90, results, 10);
    ASSERT_EQUAL(count, 1, "Only Alice has grade 90");
    int none = filter_students_same_grade(1, results, 10);
    ASSERT_EQUAL(none, 0, "No student has grade 1");
}


// ========================================
// Issue #108-#120: Advanced Analytics Tests
// ========================================

void test_get_highest_grade_in_department() {
    printf("\nTest: Get highest grade in department\n");
    setup();
    seed_five();
    int highest = get_highest_grade_in_department("CS");
    ASSERT_EQUAL(highest, 90, "Highest CS grade should be Alice's 90");
}

void test_get_lowest_grade_in_department() {
    printf("\nTest: Get lowest grade in department\n");
    setup();
    seed_five();
    int lowest = get_lowest_grade_in_department("IT");
    ASSERT_EQUAL(lowest, 45, "Lowest IT grade should be Eve's 45");
}

void test_get_students_with_same_name() {
    printf("\nTest: Get students with the same name (duplicates)\n");
    setup();
    seed_five();
    Student dup = {6, "Alice Johnson", "alice2@mail.com", "6666666666", 70, "Math", 2};
    add_student(dup);
    Student results[10];
    int count = get_students_with_same_name("Alice Johnson", results, 10);
    ASSERT_EQUAL(count, 2, "Two students are named Alice Johnson after adding a duplicate");
}

void test_get_students_same_department_and_year() {
    printf("\nTest: Get students in same department and year\n");
    setup();
    seed_five();
    Student results[10];
    int count = get_students_same_department_and_year("CS", 1, results, 10);
    ASSERT_EQUAL(count, 1, "Only Alice is CS + year 1");
}

void test_find_grade_closest_to_average() {
    printf("\nTest: Find student with grade closest to average\n");
    setup();
    seed_five();
    Student out_s = {0};
    int found = find_grade_closest_to_average(&out_s);
    ASSERT_EQUAL(found, 1, "Should find a student when database is populated");
}

void test_compare_grades_between_departments() {
    printf("\nTest: Compare grades between two departments\n");
    setup();
    seed_five();
    int cmp = compare_grades_between_departments("CS", "IT");
    ASSERT_EQUAL(cmp > 0, 1, "CS average (89) should be higher than IT average (60)");
}

void test_get_top_n_students() {
    printf("\nTest: Get top N students by grade\n");
    setup();
    seed_five();
    Student results[5];
    int count = get_top_n_students(2, results);
    ASSERT_EQUAL(count, 2, "Should return exactly 2 students");
}

void test_get_bottom_n_students() {
    printf("\nTest: Get bottom N students by grade\n");
    setup();
    seed_five();
    Student results[5];
    int count = get_bottom_n_students(2, results);
    ASSERT_EQUAL(count, 2, "Should return exactly 2 students");
}

void test_identify_outliers() {
    printf("\nTest: Identify grade outliers (smoke test)\n");
    setup();
    seed_five();
    Student results[10];
    int count = identify_outliers(results, 10);
    ASSERT_EQUAL(count >= 0 && count <= total_students, 1, "Outlier count should be between 0 and total_students");
}

void test_get_grade_distribution() {
    printf("\nTest: Get grade distribution (smoke test)\n");
    setup();
    seed_five();
    int distribution[101] = {0};
    int result = get_grade_distribution(distribution);
    ASSERT_EQUAL(result >= 0, 1, "Should not crash and should return a non-negative status/count");
}

void test_compare_year_wise_performance() {
    printf("\nTest: Compare year-wise performance (uses struct 'year' field)\n");
    setup();
    seed_five();
    double avg = compare_year_wise_performance(1);
    ASSERT_EQUAL(avg >= 0.0, 1, "Year 1 average should be non-negative (Alice=90, Eve=45)");
}

void test_get_semester_wise_average() {
    printf("\nTest: Get semester-wise average (smoke test - no 'semester' field on Student)\n");
    setup();
    seed_five();
    double avg = get_semester_wise_average(1);
    ASSERT_EQUAL(avg >= 0.0, 1, "Result should be non-negative");
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
    printf("Issue #4-#6, #19: Getter Functions\n");
    printf("========================================\n");
    test_get_student_by_email();
    test_get_student_by_name();
    test_get_all_students();
    test_get_student_by_phone();

    printf("\n========================================\n");
    printf("Issue #9-#14: Update Functions\n");
    printf("========================================\n");
    test_update_student_name();
    test_update_student_email();
    test_update_student_phone();
    test_update_student_grade();
    test_update_student_department();
    test_update_student_year();

    printf("\n========================================\n");
    printf("Issue #15-#17, #20: Print/Clear/Duplicate\n");
    printf("========================================\n");
    test_print_student_details();
    test_print_all_students();
    test_clear_all_students();
    test_duplicate_student_record();

    printf("\n========================================\n");
    printf("Issue #22-#35: Validation Functions (extra)\n");
    printf("========================================\n");
    test_is_valid_email();
    test_is_valid_phone();
    test_is_valid_name();
    test_is_valid_department();
    test_is_valid_age();
    test_check_duplicate_email();
    test_check_duplicate_phone();
    test_is_name_only_alphabetic();
    test_is_email_contains_at();
    test_is_phone_only_digits();
    test_is_grade_within_range();

    printf("\n========================================\n");
    printf("Issue #36-#50: Search Functions\n");
    printf("========================================\n");
    test_search_student_by_id();
    test_search_student_by_email();
    test_search_student_by_name();
    test_search_students_by_department();
    test_search_students_by_year();
    test_search_students_by_grade_range();
    test_search_students_above_gpa();
    test_search_students_below_gpa();
    test_search_students_with_same_department();
    test_search_first_student_in_range();
    test_search_last_student_in_range();
    test_count_search_results();
    test_search_by_multiple_criteria();
    test_search_students_starting_with();
    test_binary_search_by_id();

    printf("\n========================================\n");
    printf("Issue #52-#60: Sorting Functions (extra)\n");
    printf("========================================\n");
    test_sort_students_by_name();
    test_sort_students_by_grade();
    test_sort_students_by_email();
    test_sort_students_by_department();
    test_sort_students_by_year();
    test_sort_descending_by_grade();
    test_sort_descending_by_name();
    test_sort_by_grade_then_name();
    test_is_student_array_sorted();

    printf("\n========================================\n");
    printf("Issue #61-#80: Statistics Functions (extra)\n");
    printf("========================================\n");
    test_get_median_grade();
    test_get_mode_grade();
    test_get_grade_range();
    test_get_student_rank();
    test_get_student_percentile();
    test_count_students_failed();
    test_get_pass_percentage();
    test_get_pass_fail_ratio();
    test_get_average_by_department();
    test_get_students_per_department();
    test_get_top_performer_name();
    test_get_bottom_performer_name();
    test_calculate_standard_deviation();
    test_get_honor_roll_count();
    test_get_gpa_statistics();
    test_count_students_in_range();

    printf("\n========================================\n");
    printf("Issue #81-#95: String Functions (extra)\n");
    printf("========================================\n");
    test_string_to_uppercase();
    test_string_to_lowercase();
    test_trim_whitespace();
    test_reverse_string();
    test_compare_strings();
    test_compare_strings_ignore_case();
    test_get_substring();
    test_count_consonants_in_string();
    test_is_palindrome();
    test_concatenate_strings();
    test_find_character_position();
    test_count_character_occurrences();

    printf("\n========================================\n");
    printf("Issue #96-#107: Filter Functions\n");
    printf("========================================\n");
    test_filter_students_by_gpa_above();
    test_filter_students_by_gpa_below();
    test_filter_active_students();
    test_filter_inactive_students();
    test_filter_students_with_scholarship();
    test_filter_students_without_scholarship();
    test_filter_by_name_first_letter();
    test_filter_by_name_length();
    test_filter_students_by_department();
    test_filter_students_enrolled_after();
    test_filter_distinct_departments();
    test_filter_students_same_grade();

    printf("\n========================================\n");
    printf("Issue #108-#120: Advanced Analytics\n");
    printf("========================================\n");
    test_get_highest_grade_in_department();
    test_get_lowest_grade_in_department();
    test_get_students_with_same_name();
    test_get_students_same_department_and_year();
    test_find_grade_closest_to_average();
    test_compare_grades_between_departments();
    test_get_top_n_students();
    test_get_bottom_n_students();
    test_identify_outliers();
    test_get_grade_distribution();
    test_compare_year_wise_performance();
    test_get_semester_wise_average();

    printf("\n========================================\n");
    printf("Test Results:\n");
    printf("  Passed: %d\n", tests_passed);
    printf("  Failed: %d\n", tests_failed);
    printf("========================================\n");

    return tests_failed > 0 ? 1 : 0;
}
