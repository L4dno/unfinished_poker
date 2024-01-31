cmake_minimum_required (VERSION 3.20)

project("SFMLTEST")

add_executable(main "naive.cpp" "card.hpp")

#find_package(SFML COMPONENTS graphics CONFIG REQUIRED)
#target_link_libraries(main PRIVATE sfml-graphics)