cmake_minimum_required(VERSION 3.5)
project(PascalCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories("include")

set(SOURCE_FILES
    include/cgen.h
    include/constTab.h
    include/globals.h
    include/optimize.h
    include/symbol.h
    include/util.h
    include/x86.h
    include/y.tab.h
    src/cgen.c
    src/constTab.c
    src/lex.yy.c
  #  src/main.c
    src/main_x86.c
    src/optimize.c
    src/symbol.c
    src/util.c
 #   src/x86.c
    src/y.tab.c src/x86_new.c)

add_executable(PascalCompiler ${SOURCE_FILES})