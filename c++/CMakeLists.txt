cmake_minimum_required (VERSION 3.5)

project(text-search-algorithm)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add sub directories
add_subdirectory(algorithms)
add_subdirectory(helper)
add_subdirectory(application)
