file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${StackOnLists} ${srcs} ${hdrs}) 
target_link_libraries(${StackOnLists} ${StackOnListsLib}) 


