file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${ListOnArrayTest} ${srcs} ${hdrs}) 
target_link_libraries(${ListOnArrayTest} ${ListOnArrayLib} gtest) 


