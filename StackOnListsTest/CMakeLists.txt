file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${StackOnListsTest} ${srcs} ${hdrs}) 
target_link_libraries(${StackOnListsTest} ${StackOnListsLib} gtest) 


