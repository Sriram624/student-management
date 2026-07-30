#include "student.h"
#include <string.h>

// ========================================
// Issue #49: Implement search_students_starting_with
// ========================================
// TODO: Find students whose names start with letter
//
int search_students_starting_with(char letter, Student *results, int max_results) {
    int count = 0;

    letter = tolower((unsigned char)letter);

    for (int i = 0; i < total_students && count < max_results; i++) {
        if (tolower((unsigned char)students[i].name[0]) == letter) {
            results[count] = students[i];
            count++;
        }
    }

    return count;
}
