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

// Issue #2: delete_student_by_id
// Delete a student from database by ID
// Input: Student ID
// Output: Return 1 if success, 0 if student not found
// Time Complexity: O(n)
// Space Complexity: O(1)
// Constraints: Shift remaining students to maintain order
int delete_student_by_id(int id);

// Issue #3: get_student_by_id
int get_student_by_id(int id, Student *out);

// Issue #4: get_student_by_email
int get_student_by_email(const char *email, Student *out);

// Issue #5: get_student_by_name
int get_student_by_name(const char *name, Student *out);

// Issue #6: get_all_students
Student* get_all_students(void);

// Issue #7: get_total_students_count
int get_total_students_count(void);

// Issue #8: student_exists
int student_exists(int id);

// Issue #9: update_student_name
int update_student_name(int id, const char *new_name);

// Issue #10: update_student_email
int update_student_email(int id, const char *new_email);

// Issue #11: update_student_phone
int update_student_phone(int id, const char *new_phone);

// Issue #12: update_student_grade
int update_student_grade(int id, int new_grade);

// Issue #13: update_student_department
int update_student_department(int id, const char *new_dept);

// Issue #14: update_student_year
int update_student_year(int id, int new_year);

// Issue #15: print_student_details
void print_student_details(int id);

// Issue #16: print_all_students
void print_all_students(void);

// Issue #17: clear_all_students
void clear_all_students(void);

// Issue #18: is_database_empty
int is_database_empty(void);

// Issue #19: get_student_by_phone
int get_student_by_phone(const char *phone, Student *out);

// Issue #20: duplicate_student_record
int duplicate_student_record(int id);

// Issue #21: is_valid_student_id
int is_valid_student_id(int id);

// Issue #22: is_valid_email
int is_valid_email(const char *email);

// Issue #23: is_valid_phone
int is_valid_phone(const char *phone);

// Issue #24: is_valid_grade
int is_valid_grade(int grade);

// Issue #25: is_valid_name
int is_valid_name(const char *name);

// Issue #26: is_valid_year
int is_valid_year(int year);

// Issue #27: is_valid_department
int is_valid_department(const char *dept);

// Issue #28: is_valid_age
int is_valid_age(int age);

// Issue #29: check_duplicate_email
int check_duplicate_email(const char *email);

// Issue #30: check_duplicate_id
int check_duplicate_id(int id);

// Issue #31: check_duplicate_phone
int check_duplicate_phone(const char *phone);

// Issue #32: is_name_only_alphabetic
int is_name_only_alphabetic(const char *name);

// Issue #33: is_email_contains_at
int is_email_contains_at(const char *email);

// Issue #34: is_phone_only_digits
int is_phone_only_digits(const char *phone);

// Issue #35: is_grade_within_range
int is_grade_within_range(int grade);

// Issue #36: search_student_by_id
int search_student_by_id(int id, Student *out);

// Issue #37: search_student_by_email
int search_student_by_email(const char *email, Student *out);

// Issue #38: search_student_by_name
int search_student_by_name(const char *name, Student *out);

// Issue #39: search_students_by_department
int search_students_by_department(const char *dept, Student *results, int max_results);

// Issue #40: search_students_by_year
int search_students_by_year(int year, Student *results, int max_results);

// Issue #41: search_students_by_grade_range
int search_students_by_grade_range(int min_grade, int max_grade, Student *results, int max_results);

// Issue #42: search_students_above_gpa
int search_students_above_gpa(int threshold, Student *results, int max_results);

// Issue #43: search_students_below_gpa
int search_students_below_gpa(int threshold, Student *results, int max_results);

// Issue #44: search_students_with_same_department
int search_students_with_same_department(const char *dept, Student *results, int max_results);

// Issue #45: search_first_student_in_range
int search_first_student_in_range(int min_grade, int max_grade, Student *out);

// Issue #46: search_last_student_in_range
int search_last_student_in_range(int min_grade, int max_grade, Student *out);

// Issue #47: count_search_results
int count_search_results(int min_grade, int max_grade);

// Issue #48: search_by_multiple_criteria
int search_by_multiple_criteria(const char *dept, int year, Student *results, int max_results);

// Issue #49: search_students_starting_with
int search_students_starting_with(char letter, Student *results, int max_results);

// Issue #50: binary_search_by_id
int binary_search_by_id(int id, Student *out);

// Issue #51: sort_students_by_id
void sort_students_by_id(void);

// Issue #52: sort_students_by_name
void sort_students_by_name(void);

// Issue #53: sort_students_by_grade
void sort_students_by_grade(void);

// Issue #54: sort_students_by_email
void sort_students_by_email(void);

// Issue #55: sort_students_by_department
void sort_students_by_department(void);

// Issue #56: sort_students_by_year
void sort_students_by_year(void);

// Issue #57: sort_descending_by_grade
void sort_descending_by_grade(void);

// Issue #58: sort_descending_by_name
void sort_descending_by_name(void);

// Issue #59: sort_by_grade_then_name
void sort_by_grade_then_name(void);

// Issue #60: is_student_array_sorted
int is_student_array_sorted(void);

// Issue #61: get_median_grade
int get_median_grade(void);

// Issue #62: get_mode_grade
int get_mode_grade(void);

// Issue #63: calculate_average_grade
double calculate_average_grade(void);

// Issue #64: get_max_grade
int get_max_grade(void);

// Issue #65: get_min_grade
int get_min_grade(void);

// Issue #66: get_grade_range
int get_grade_range(void);

// Issue #67: get_student_rank
int get_student_rank(int id);

// Issue #68: get_student_percentile
double get_student_percentile(int id);

// Issue #69: count_students_passed
int count_students_passed(void);

// Issue #70: count_students_failed
int count_students_failed(void);

// Issue #71: get_pass_percentage
double get_pass_percentage(void);

// Issue #72: get_pass_fail_ratio
double get_pass_fail_ratio(void);

// Issue #73: get_average_by_department
double get_average_by_department(const char *dept);

// Issue #74: get_students_per_department
int get_students_per_department(const char *dept);

// Issue #75: get_top_performer_name
char* get_top_performer_name(void);

// Issue #76: get_bottom_performer_name
char* get_bottom_performer_name(void);

// Issue #77: calculate_standard_deviation
double calculate_standard_deviation(void);

// Issue #78: get_honor_roll_count
int get_honor_roll_count(void);

// Issue #79: get_gpa_statistics
double get_gpa_statistics(void);

// Issue #80: count_students_in_range
int count_students_in_range(int min_grade, int max_grade);

// Issue #81: string_to_uppercase
char* string_to_uppercase(char *str);

// Issue #82: string_to_lowercase
char* string_to_lowercase(char *str);

// Issue #83: trim_whitespace
char* trim_whitespace(char *str);

// Issue #84: reverse_string
char* reverse_string(char *str);

// Issue #85: get_string_length
int get_string_length(const char *str);

// Issue #86: compare_strings
int compare_strings(const char *str1, const char *str2);

// Issue #87: compare_strings_ignore_case
int compare_strings_ignore_case(const char *str1, const char *str2);

// Issue #88: get_substring
char* get_substring(const char *str, int start, int length);

// Issue #89: count_vowels_in_string
int count_vowels_in_string(const char *str);

// Issue #90: count_consonants_in_string
int count_consonants_in_string(const char *str);

// Issue #91: is_palindrome
int is_palindrome(const char *str);

// Issue #92: concatenate_strings
char* concatenate_strings(const char *str1, const char *str2);

// Issue #93: find_character_position
int find_character_position(const char *str, char c);

// Issue #94: count_character_occurrences
int count_character_occurrences(const char *str, char c);

// Issue #95: string_contains_substring
int string_contains_substring(const char *str, const char *substr);

// Issue #96: filter_students_by_gpa_above
int filter_students_by_gpa_above(int threshold, Student *results, int max_results);

// Issue #97: filter_students_by_gpa_below
int filter_students_by_gpa_below(int threshold, Student *results, int max_results);

// Issue #98: filter_active_students
int filter_active_students(Student *results, int max_results);

// Issue #99: filter_inactive_students
int filter_inactive_students(Student *results, int max_results);

// Issue #100: filter_students_with_scholarship
int filter_students_with_scholarship(Student *results, int max_results);

// Issue #101: filter_students_without_scholarship
int filter_students_without_scholarship(Student *results, int max_results);

// Issue #102: filter_by_name_first_letter
int filter_by_name_first_letter(char letter, Student *results, int max_results);

// Issue #103: filter_by_name_length
int filter_by_name_length(int length, Student *results, int max_results);

// Issue #104: filter_students_by_department
int filter_students_by_department(const char *dept, Student *results, int max_results);

// Issue #105: filter_students_enrolled_after
int filter_students_enrolled_after(int year, Student *results, int max_results);

// Issue #106: filter_distinct_departments
int filter_distinct_departments(char *results[]);

// Issue #107: filter_students_same_grade
int filter_students_same_grade(int grade, Student *results, int max_results);

// Issue #108: get_highest_grade_in_department
int get_highest_grade_in_department(const char *dept);

// Issue #109: get_lowest_grade_in_department
int get_lowest_grade_in_department(const char *dept);

// Issue #110: compare_two_students
int compare_two_students(int id1, int id2);

// Issue #111: get_students_with_same_name
int get_students_with_same_name(const char *name, Student *results, int max_results);

// Issue #112: get_students_same_department_and_year
int get_students_same_department_and_year(const char *dept, int year, Student *results, int max_results);

// Issue #113: find_grade_closest_to_average
int find_grade_closest_to_average(Student *out);

// Issue #114: compare_grades_between_departments
int compare_grades_between_departments(const char *dept1, const char *dept2);

// Issue #115: get_top_n_students
int get_top_n_students(int n, Student *results);

// Issue #116: get_bottom_n_students
int get_bottom_n_students(int n, Student *results);

// Issue #117: identify_outliers
int identify_outliers(Student *results, int max_results);

// Issue #118: get_grade_distribution
int get_grade_distribution(int *distribution);

// Issue #119: compare_year_wise_performance
double compare_year_wise_performance(int year);

// Issue #120: get_semester_wise_average
double get_semester_wise_average(int semester);

#endif
