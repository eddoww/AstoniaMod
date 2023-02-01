cmake_minimum_required(VERSION 3.24)
project(AstoniaMod CXX)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(CMAKE_CROSSCOMPILING true)

SET(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
SET(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

# Specify the path to the header file
include_directories(${CMAKE_SOURCE_DIR}/include)

# Specify the path to the library file
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add the source files
file(GLOB SOURCES "src/*.cpp")

# Create the shared library
add_library(AstoniaMod SHARED ${SOURCES})

# Link the library file to the shared library
target_link_libraries(AstoniaMod -l:moac.a)

target_link_libraries(AstoniaMod -static)

# Specify the exported functions
set_target_properties(AstoniaMod PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
        SUFFIX ".dll"
        )