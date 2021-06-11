cmake_minimum_required(VERSION 3.10)
project(gameoflife C)

add_subdirectory(game)
add_subdirectory(console)
add_subdirectory(tests)

add_executable(main main.c )

target_link_libraries(main PRIVATE console)