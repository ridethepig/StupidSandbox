cmake_minimum_required(VERSION 3.12)
project(StupidSandbox)

set(CMAKE_CXX_STANDARD 11)

add_executable(StupidSandbox main.cpp Test/test.cpp Test/test.h main.h include/log.h log.cpp include/exitcode.h include/stringutils.h parse_args.cpp include/parse_args.h include/data.h)