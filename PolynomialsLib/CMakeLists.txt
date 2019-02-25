file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${PolynomialsLib} STATIC ${srcs} ${hdrs})