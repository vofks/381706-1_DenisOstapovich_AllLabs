file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Matrix} ${srcs} ${hdrs}) 
target_link_libraries(${Matrix} ${MatrixLib}) 


