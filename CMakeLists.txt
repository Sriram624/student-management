cmake_minimum_required(VERSION 4.3)
project(clion_student_management C)

set(CMAKE_C_STANDARD 11)

# Pick up src/globals.c plus every per-issue source file (src/issue_*.c)
file(GLOB ISSUE_SOURCES ${CMAKE_SOURCE_DIR}/src/issue_*.c)

add_executable(clion_student_management
    main.c
    src/globals.c
    ${ISSUE_SOURCES}
)

target_include_directories(clion_student_management PRIVATE src)

# Optional: build the test runner as its own CLion target too
file(GLOB TEST_SOURCES ${CMAKE_SOURCE_DIR}/test/test.c)
add_executable(test_runner
    ${TEST_SOURCES}
    src/globals.c
    ${ISSUE_SOURCES}
)
target_include_directories(test_runner PRIVATE src)
