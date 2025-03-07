cmake_minimum_required(VERSION 3.14)
project(NetworkProgramming)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Fetch GoogleTest and make it available
FetchContent_MakeAvailable(googletest)

# Automatically find all source files in src/ and tests/
file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/**/*.cpp")
list(APPEND SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")


file(GLOB_RECURSE TEST_FILES "tests/**/*.cpp")

# Debugging: Print the source files
message("Source files: ${SRC_FILES}")

# Add the executable for the main application
add_executable(NetworkProgramming ${SRC_FILES})

# Optionally install the application
install(TARGETS NetworkProgramming DESTINATION bin)

# Specify the include directories for your project (for both `NetworkProgramming` and `run_tests`)
target_include_directories(NetworkProgramming PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Enable testing
enable_testing()

# Exclude main.cpp from SRC_FILES for the test executable
list(FILTER SRC_FILES EXCLUDE REGEX ".*main.cpp")

# Add the test executable
add_executable(run_tests ${TEST_FILES} ${SRC_FILES})

# Now that the test executable exists, specify the include directories
target_include_directories(run_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link GoogleTest to the test executable
target_link_libraries(run_tests gtest gtest_main)

# Discover and register all GoogleTest tests with CTest
include(GoogleTest)
gtest_discover_tests(run_tests)

