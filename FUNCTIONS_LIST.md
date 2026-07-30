# Student Management System - 120 Functions List

| Issue # | Function Name                         | Description                           | Time Complexity | Space Complexity |
| ------- | ------------------------------------- | ------------------------------------- | --------------- | ---------------- |
| 1       | add_student                           | Add new student to system             | O(1)            | O(1)             |
| 2       | delete_student_by_id                  | Remove student record by ID           | O(n)            | O(1)             |
| 3       | get_student_by_id                     | Retrieve student by ID                | O(n)            | O(1)             |
| 4       | get_student_by_email                  | Retrieve student by email             | O(n)            | O(1)             |
| 5       | get_student_by_name                   | Retrieve student by name              | O(n)            | O(1)             |
| 6       | get_all_students                      | Get list of all students              | O(1)            | O(1)             |
| 7       | get_total_students_count              | Count total students                  | O(1)            | O(1)             |
| 8       | student_exists                        | Check if student exists               | O(n)            | O(1)             |
| 9       | update_student_name                   | Modify student name                   | O(n)            | O(1)             |
| 10      | update_student_email                  | Modify student email                  | O(n)            | O(1)             |
| 11      | update_student_phone                  | Modify student phone                  | O(n)            | O(1)             |
| 12      | update_student_grade                  | Modify student grade                  | O(n)            | O(1)             |
| 13      | update_student_department             | Modify student department             | O(n)            | O(1)             |
| 14      | update_student_year                   | Modify student year                   | O(n)            | O(1)             |
| 15      | print_student_details                 | Display single student info           | O(1)            | O(1)             |
| 16      | print_all_students                    | Display all students                  | O(n)            | O(1)             |
| 17      | clear_all_students                    | Delete all records                    | O(n)            | O(1)             |
| 18      | is_database_empty                     | Check if no students exist            | O(1)            | O(1)             |
| 19      | get_student_by_phone                  | Retrieve student by phone             | O(n)            | O(1)             |
| 20      | duplicate_student_record              | Create copy of student                | O(n)            | O(1)             |
| 21      | is_valid_student_id                   | Validate ID format (positive integer) | O(1)            | O(1)             |
| 22      | is_valid_email                        | Validate email format                 | O(n)            | O(1)             |
| 23      | is_valid_phone                        | Validate phone format                 | O(n)            | O(1)             |
| 24      | is_valid_grade                        | Validate grade (0-100 range)          | O(1)            | O(1)             |
| 25      | is_valid_name                         | Validate name (non-empty, length)     | O(n)            | O(1)             |
| 26      | is_valid_year                         | Validate year (1-4)                   | O(1)            | O(1)             |
| 27      | is_valid_department                   | Validate department string            | O(n)            | O(1)             |
| 28      | is_valid_age                          | Validate age (18-60)                  | O(1)            | O(1)             |
| 29      | check_duplicate_email                 | Check if email already exists         | O(n)            | O(1)             |
| 30      | check_duplicate_id                    | Check if ID already exists            | O(n)            | O(1)             |
| 31      | check_duplicate_phone                 | Check if phone already exists         | O(n)            | O(1)             |
| 32      | is_name_only_alphabetic               | Validate name has only letters        | O(n)            | O(1)             |
| 33      | is_email_contains_at                  | Check email has @ symbol              | O(n)            | O(1)             |
| 34      | is_phone_only_digits                  | Check phone has only digits           | O(n)            | O(1)             |
| 35      | is_grade_within_range                 | Check grade in valid range            | O(1)            | O(1)             |
| 36      | search_student_by_id                  | Find single student by ID             | O(n)            | O(1)             |
| 37      | search_student_by_email               | Find single student by email          | O(n)            | O(1)             |
| 38      | search_student_by_name                | Find student by name                  | O(n)            | O(1)             |
| 39      | search_students_by_department         | Find all in department                | O(n)            | O(n)             |
| 40      | search_students_by_year               | Find all in same year                 | O(n)            | O(n)             |
| 41      | search_students_by_grade_range        | Find in grade range                   | O(n)            | O(n)             |
| 42      | search_students_above_gpa             | Find with grade > threshold           | O(n)            | O(n)             |
| 43      | search_students_below_gpa             | Find with grade < threshold           | O(n)            | O(n)             |
| 44      | search_students_with_same_department  | Group by dept                         | O(n)            | O(n)             |
| 45      | search_first_student_in_range         | Get first match                       | O(n)            | O(1)             |
| 46      | search_last_student_in_range          | Get last match                        | O(n)            | O(1)             |
| 47      | count_search_results                  | Count matching records                | O(n)            | O(1)             |
| 48      | search_by_multiple_criteria           | Find by dept AND year                 | O(n)            | O(1)             |
| 49      | search_students_starting_with         | Name starts with letter               | O(n)            | O(n)             |
| 50      | binary_search_by_id                   | Binary search on ID (assumes sorted)  | O(log n)        | O(1)             |
| 51      | sort_students_by_id                   | Sort ascending by ID                  | O(n log n)      | O(1)             |
| 52      | sort_students_by_name                 | Sort ascending by name                | O(n log n)      | O(1)             |
| 53      | sort_students_by_grade                | Sort ascending by grade               | O(n log n)      | O(1)             |
| 54      | sort_students_by_email                | Sort ascending by email               | O(n log n)      | O(1)             |
| 55      | sort_students_by_department           | Sort ascending by dept                | O(n log n)      | O(1)             |
| 56      | sort_students_by_year                 | Sort ascending by year                | O(n log n)      | O(1)             |
| 57      | sort_descending_by_grade              | Sort descending by grade              | O(n log n)      | O(1)             |
| 58      | sort_descending_by_name               | Sort descending by name               | O(n log n)      | O(1)             |
| 59      | sort_by_grade_then_name               | Multi-key sort                        | O(n log n)      | O(1)             |
| 60      | is_student_array_sorted               | Check if sorted by ID                 | O(n)            | O(1)             |
| 61      | get_median_grade                      | Get middle grade value                | O(n log n)      | O(1)             |
| 62      | get_mode_grade                        | Get most frequent grade               | O(n)            | O(n)             |
| 63      | calculate_average_grade               | Mean of all grades                    | O(n)            | O(1)             |
| 64      | get_max_grade                         | Highest grade                         | O(n)            | O(1)             |
| 65      | get_min_grade                         | Lowest grade                          | O(n)            | O(1)             |
| 66      | get_grade_range                       | Max - Min                             | O(n)            | O(1)             |
| 67      | get_student_rank                      | Rank by grade (1 = highest)           | O(n)            | O(1)             |
| 68      | get_student_percentile                | Percentile rank                       | O(n log n)      | O(1)             |
| 69      | count_students_passed                 | Count with grade >= 60                | O(n)            | O(1)             |
| 70      | count_students_failed                 | Count with grade < 60                 | O(n)            | O(1)             |
| 71      | get_pass_percentage                   | % of students passed                  | O(n)            | O(1)             |
| 72      | get_pass_fail_ratio                   | Ratio of pass:fail                    | O(n)            | O(1)             |
| 73      | get_average_by_department             | Average grade per dept                | O(n)            | O(n)             |
| 74      | get_students_per_department           | Count per dept                        | O(n)            | O(n)             |
| 75      | get_top_performer_name                | Name of highest grade                 | O(n)            | O(1)             |
| 76      | get_bottom_performer_name             | Name of lowest grade                  | O(n)            | O(1)             |
| 77      | calculate_standard_deviation          | Std dev of grades                     | O(n)            | O(1)             |
| 78      | get_honor_roll_count                  | Count of top 10% students             | O(n log n)      | O(1)             |
| 79      | get_gpa_statistics                    | Min/max/avg combined                  | O(n)            | O(1)             |
| 80      | count_students_in_range               | Count in grade range                  | O(n)            | O(1)             |
| 81      | string_to_uppercase                   | Convert string to uppercase           | O(n)            | O(n)             |
| 82      | string_to_lowercase                   | Convert string to lowercase           | O(n)            | O(n)             |
| 83      | trim_whitespace                       | Remove leading/trailing spaces        | O(n)            | O(n)             |
| 84      | reverse_string                        | Reverse all characters                | O(n)            | O(n)             |
| 85      | get_string_length                     | Count characters                      | O(n)            | O(1)             |
| 86      | compare_strings                       | Case-sensitive comparison             | O(n)            | O(1)             |
| 87      | compare_strings_ignore_case           | Case-insensitive comparison           | O(n)            | O(1)             |
| 88      | get_substring                         | Extract portion of string             | O(n)            | O(n)             |
| 89      | count_vowels_in_string                | Count vowels (a,e,i,o,u)              | O(n)            | O(1)             |
| 90      | count_consonants_in_string            | Count consonants                      | O(n)            | O(1)             |
| 91      | is_palindrome                         | Check if string reads same backwards  | O(n)            | O(1)             |
| 92      | concatenate_strings                   | Join two strings                      | O(n)            | O(n)             |
| 93      | find_character_position               | Find index of char in string          | O(n)            | O(1)             |
| 94      | count_character_occurrences           | Count specific char                   | O(n)            | O(1)             |
| 95      | string_contains_substring             | Check if substring exists             | O(n\*m)         | O(1)             |
| 96      | filter_students_by_gpa_above          | Get all with grade > X                | O(n)            | O(n)             |
| 97      | filter_students_by_gpa_below          | Get all with grade < X                | O(n)            | O(n)             |
| 98      | filter_active_students                | Get only active status                | O(n)            | O(n)             |
| 99      | filter_inactive_students              | Get only inactive status              | O(n)            | O(n)             |
| 100     | filter_students_with_scholarship      | Get scholarship holders               | O(n)            | O(n)             |
| 101     | filter_students_without_scholarship   | Get non-scholarship                   | O(n)            | O(n)             |
| 102     | filter_by_name_first_letter           | Name starts with letter               | O(n)            | O(n)             |
| 103     | filter_by_name_length                 | Name has specific length              | O(n)            | O(n)             |
| 104     | filter_students_by_department         | Get specific dept                     | O(n)            | O(n)             |
| 105     | filter_students_enrolled_after        | Enrollment date filter                | O(n)            | O(n)             |
| 106     | filter_distinct_departments           | Get unique departments                | O(n)            | O(n)             |
| 107     | filter_students_same_grade            | Group by exact grade                  | O(n)            | O(n)             |
| 108     | get_highest_grade_in_department       | Max grade in dept                     | O(n)            | O(1)             |
| 109     | get_lowest_grade_in_department        | Min grade in dept                     | O(n)            | O(1)             |
| 110     | compare_two_students                  | Compare any two records               | O(1)            | O(1)             |
| 111     | get_students_with_same_name           | Find duplicates                       | O(n)            | O(n)             |
| 112     | get_students_same_department_and_year | Multi-filter                          | O(n)            | O(n)             |
| 113     | find_grade_closest_to_average         | Closest to mean                       | O(n)            | O(1)             |
| 114     | compare_grades_between_departments    | Dept comparison                       | O(n)            | O(1)             |
| 115     | get_top_n_students                    | Get top N by grade                    | O(n log n)      | O(n)             |
| 116     | get_bottom_n_students                 | Get bottom N by grade                 | O(n log n)      | O(n)             |
| 117     | identify_outliers                     | Grades far from average               | O(n)            | O(n)             |
| 118     | get_grade_distribution                | Grade frequency breakdown             | O(n)            | O(n)             |
| 119     | compare_year_wise_performance         | By year analysis                      | O(n)            | O(n)             |
| 120     | get_semester_wise_average             | By semester stats                     | O(n)            | O(n)             |
