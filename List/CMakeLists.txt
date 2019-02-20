file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${List} ${srcs} ${hdrs}) 
target_link_libraries(${List} ${ListLib}) 


