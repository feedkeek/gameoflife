add_library(console draw.h draw.c)
target_include_directories(console PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(console PRIVATE game)
