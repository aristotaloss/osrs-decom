cmake_minimum_required(VERSION 3.2)
project(osrs_decom)

find_package(Boost COMPONENTS system filesystem program_options)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(../librsfs/src ${Boost_INCLUDE_DIRS})
link_directories(lib)

set(SOURCE_FILES src/main.cpp)

add_executable(osrs_decom ${SOURCE_FILES} src/cs2file.cpp src/cs2file.h)
target_link_libraries(osrs_decom ${Boost_LIBRARIES} rsfs)