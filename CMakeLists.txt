cmake_minimum_required(VERSION 3.23)
project(DS_learning)

set(CMAKE_CXX_STANDARD 14)

add_executable(DS_learning slist_test.cpp)

add_executable(main slist_test.cpp)
add_executable(LNode_test LNode_test.cpp)
add_executable(seqStack_test seqStack_test.cpp)
add_executable(linkedStack_test linkedStack_test.cpp)
add_executable(seqQueue_test seqQueue_test.cpp)
add_executable(BiTree_test BiTree_test.cpp)
add_executable(linkQueue_test linkQueue_test.cpp)
add_executable(MGraph_test MGraph_test.cpp)