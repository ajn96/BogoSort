cmake_minimum_required(VERSION 3.5)

project(bogosort CXX)

set(LIB_SOURCE
	bogosort.cpp)

add_executable(sorts ${LIB_SOURCE})