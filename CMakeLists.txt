cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME AllLabs) 
project(${PROJECT_NAME})

# set(Vector Vector)
# set(VectorLib VectorLib)
# set(VectorTest VectorTest)

 # set(List List)
 # set(ListLib ListLib)
 # set(ListTest ListTest)

 # set(Matrix Matrix)
 # set(MatrixLib MatrixLib)
 # set(MatrixTest MatrixTest)

 # set(ListOnArray ListOnArray)
 # set(ListOnArrayLib ListOnArrayLib)
 # set(ListOnArrayTest ListOnArrayTest)

 # set(MultiStack MultiStack)
 # set(MultiStackLib MultiStackLib)
 # set(MultiStackTest MultiStackTest)

 # set(Polynomials Polynomials)
 # set(PolynomialsLib PolynomialsLib)
 # set(PolynomialsTest PolynomialsTest)

 # set(Queue Queue)
 # set(QueueLib QueueLib)
 # set(QueueTest QueueTest)

 # set(RPN RPN)
 # set(RPNLib RPNLib)
 # set(RPNTest RPNTest)

 set(Stack Stack)
 set(StackLib StackLib)
 set(StackTest StackTest)

 # set(StackOnLists StackOnLists)
 # set(StackOnListsLib StackOnListsLib)
 # set(StackOnListsTest StackOnListsTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release) 
endif()

file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib
${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib
${CMAKE_CURRENT_SOURCE_DIR}/StackLib
${CMAKE_CURRENT_SOURCE_DIR}/ListLib
${CMAKE_CURRENT_SOURCE_DIR}/ListOnArrayLib
${CMAKE_CURRENT_SOURCE_DIR}/MultiStackLib
${CMAKE_CURRENT_SOURCE_DIR}/RPNLib
${CMAKE_CURRENT_SOURCE_DIR}/StackOnListsLib
${CMAKE_CURRENT_SOURCE_DIR}/PolynomialsLib
${CMAKE_CURRENT_SOURCE_DIR}/QueueLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest
)

# add_subdirectory(Vector)
# add_subdirectory(VectorLib) 
# add_subdirectory(VectorTest)

 # add_subdirectory(Matrix)
 # add_subdirectory(MatrixLib) 
 # add_subdirectory(MatrixTest)

 # add_subdirectory(ListOnArray)
 # add_subdirectory(ListOnArrayLib) 
 # add_subdirectory(ListOnArrayTest)

 # add_subdirectory(Queue)
 # add_subdirectory(QueueLib) 
 # add_subdirectory(QueueTest)

 # add_subdirectory(RPN)
 # add_subdirectory(RPNLib) 
 # add_subdirectory(RPNTest)

 add_subdirectory(Stack)
 add_subdirectory(StackLib) 
 add_subdirectory(StackTest)

 # add_subdirectory(StackOnLists)
 # add_subdirectory(StackOnListsLib) 
 # add_subdirectory(StackOnListsTest)

 # add_subdirectory(MultiStack)
 # add_subdirectory(MultiStackLib) 
 # add_subdirectory(MultiStackTest)

 # add_subdirectory(Polynomials)
 # add_subdirectory(PolynomialsLib) 
 # add_subdirectory(PolynomialsTest)

 # add_subdirectory(List)
 # add_subdirectory(ListLib) 
 # add_subdirectory(ListTest)
 
 add_subdirectory(gtest)