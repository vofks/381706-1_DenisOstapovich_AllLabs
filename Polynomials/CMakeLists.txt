file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${Polynomials} ${srcs} ${hdrs}) 
target_link_libraries(${Polynomials} ${PolynomialsLib}) 


