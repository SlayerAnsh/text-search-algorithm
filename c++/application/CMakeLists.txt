project(application)

# Create the executable
add_executable(${PROJECT_NAME} main.cpp)

# Link the static library from subproject1 using its alias sub::lib1
target_link_libraries(${PROJECT_NAME}
    lib::algorithms
    lib::helper
)
