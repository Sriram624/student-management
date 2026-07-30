#ifndef STUDENT_H
#define STUDENT_H

// Constants - DO NOT MODIFY
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_DEPARTMENT_LENGTH 50

// Student structure - DO NOT MODIFY
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int grade;
    char department[MAX_DEPARTMENT_LENGTH];
    int year;
} Student;

// Global student database - DO NOT MODIFY
extern Student students[MAX_STUDENTS];
extern int total_students;

// Function declarations - Students implement these
// ========================================

// Issue #1: add_student
// Add a new student to the database
// Input: Student struct with all details
// Output: Return 1 if success, 0 if database full
// Time Complexity: O(1)
// Space Complexity: O(1)
// Constraints: Only modify the students array, do not modify struct definition
int add_student(Student s);

#endif
