file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${ListLib} STATIC ${srcs} ${hdrs})