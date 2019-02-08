cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME AllLabs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(VectorApp VectorApplication)
set(VectorLib VectorLib) #Переменная с именем библиотеки

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)

add_subdirectory(VectorApp)
add_subdirectory(VectorLib) #Собираем проект в поддиректории lib1