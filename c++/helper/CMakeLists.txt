# Set the project name
project (helper)

# Add a library with the above sources
add_library(${PROJECT_NAME}
    print.cpp
)
add_library(lib::helper ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
