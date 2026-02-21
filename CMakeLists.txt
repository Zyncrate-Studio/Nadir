cmake_minimum_required(VERSION 3.10)
project(MaterialSelector)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Tell CMake where your header files are (.h files)
include_directories(include)

# 2. List all the source files needed for the project
# We must include sqlite3.c so the database engine is built into your app
set(SOURCE_FILES 
    src/main.cpp 
    src/database.cpp 
    src/sqlite3.c
    src/mathutil.cpp
    src/selector.cpp
)

# 3. Create the executable
add_executable(material_app ${SOURCE_FILES})

# 4. Link the threading library (SQLite needs this to work safely)
#find_package(Threads REQUIRED)
#target_link_libraries(material_app THREADS::Threads)

if(WIN32)
	target_link_libraries(material_app -static-libgcc
	-static-libstdc++)
endif()
