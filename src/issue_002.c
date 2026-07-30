#include "student.h"
#include <string.h>

// ========================================
// Issue #2: Implement delete_student_by_id
// ========================================
// TODO: Delete a student from database by ID
//
// Requirements:
// - Find student by ID
// - Remove from array (shift remaining students down)
// - Decrement total_students counter
// - Return 1 if successful, 0 if student not found
//
// Example:
// int result = delete_student_by_id(1);  // Delete student with ID=1
// // Should return 1 and total_students decremented
//
// Test Cases:
// - Delete existing student → should succeed
// - Delete non-existing student → should fail
// - Verify remaining students are intact
//
int delete_student_by_id(int id) {
    // Find student by ID
    int index = -1;
    for (int i = 0; i < total_students; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    // Student not found
    if (index == -1) {
        return 0;
    }

    // Shift remaining students down
    for (int i = index; i < total_students - 1; i++) {
        students[i] = students[i + 1];
    }

    // Decrement counter
    total_students--;

    return 1;  // Success
}
