#include "student.h"
#include <string.h>

// ========================================
// Issue #50: Implement binary_search_by_id
// ========================================
// TODO: Binary search for student by ID
//
int binary_search_by_id(int id, Student *out) {
    int left = 0;
    int right = total_students - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].id == id) {
            *out = students[mid];
            return 1;
        }
        else if (students[mid].id < id) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}