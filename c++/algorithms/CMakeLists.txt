# Set the project name
project (algorithms)

# Add a library with the above sources
add_library(${PROJECT_NAME}
 bruteforce.cpp
 kmp.cpp
)
add_library(lib::algorithms ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
