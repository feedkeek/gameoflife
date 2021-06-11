add_library(console draw.h draw.c)
target_include_directories(console PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(console PRIVATE game ${SDL2_LIBRARIES})

