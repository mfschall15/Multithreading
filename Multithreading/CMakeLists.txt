# CMakeList.txt : CMake project for Multithreading, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Multithreading "main.cpp" "Matrix_multiplication.h" "Matrix_multiplication.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Multithreading PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Multithreading PUBLIC OpenMP::OpenMP_CXX)
endif()