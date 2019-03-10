file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Vector} ${srcs} ${hdrs}) 
target_link_libraries(${Vector} ${VectorLib}) 



