cmake_minimum_required(VERSION 3.10)
project(StringSort)

set(CMAKE_CXX_STANDARD 17)

include_directories(generators testers algorithms)

add_executable(StringSort
        main.cpp
        generators/StringGenerator.cpp
        testers/StringSortTester.cpp
        algorithms/mergesort.cpp
        algorithms/quicksort.cpp
        algorithms/msd_radix.cpp
        algorithms/msd_radix_qs.cpp
#        main_a1m.cpp
#        main_a1q.cpp
#        main_a1r.cpp
#        main_a1rq.cpp
)
