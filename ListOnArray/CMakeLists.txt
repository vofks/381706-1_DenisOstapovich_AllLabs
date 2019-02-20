file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${ListOnArray} ${srcs} ${hdrs}) 
target_link_libraries(${ListOnArray} ${ListOnArrayLib}) 


