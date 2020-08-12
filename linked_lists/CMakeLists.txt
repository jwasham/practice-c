cmake_minimum_required(VERSION 3.5)
project(linked_list_proj)

set(SOURCE_FILES main.c)
set(SOURCE_FILES2 addtwonum.c)
add_executable(linked_list ${SOURCE_FILES})
add_executable(addtwonum ${SOURCE_FILES2})
