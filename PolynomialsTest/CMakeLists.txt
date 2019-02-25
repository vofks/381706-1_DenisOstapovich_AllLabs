file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${PolynomialsTest} ${srcs} ${hdrs}) 
target_link_libraries(${PolynomialsTest} ${PolynomialsLib} gtest) 


