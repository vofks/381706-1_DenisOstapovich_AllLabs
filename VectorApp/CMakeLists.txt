file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h

add_executable(${VectorApp} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${VectorApp} ${VectorLib}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}