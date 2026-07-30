#include "student.h"
#include <string.h>

// Global database
Student students[MAX_STUDENTS];
int total_students = 0;

// ========================================
// Issue #1: Implement add_student
// ========================================
// TODO: Add a new student to the database
//
// Requirements:
// - Add the student struct to the global students array
// - Increment total_students counter
// - Return 1 if successful, 0 if array is full (total_students >= MAX_STUDENTS)
//
// Example:
// Student s = {1, "John", "john@mail.com", "9999999999", 85, "CS", 2};
// int result = add_student(s);  // Should return 1 and total_students becomes 1
//
// Test Case:
// - Empty database, add one student → should succeed
// - Full database (100 students), add one more → should fail
//
int add_student(Student s) {
    // Check if database is full
    if (total_students >= MAX_STUDENTS) {
        return 0;  // Database full, cannot add
    }

    // Add student to array
    students[total_students] = s;
    total_students++;

    return 1;  // Success
}
