project(numberFormats)

#cmake_minimum_required(VERSION 3.16)

#set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_C20_LINK_EXECUTABLE g++)

#set(CMAKE_SOURCE_DIR /home/gyda/exp)

add_executable(
test
Dummy.h
Dummy.cpp
floatx.hpp
test.cpp)

#set_target_properties(test PROPERTIES LINKER_LANGUAGE C20)

#set_source_files_properties(Dummy.h Dummy.c test.c PROPERTIES LANGUAGE CXX)
