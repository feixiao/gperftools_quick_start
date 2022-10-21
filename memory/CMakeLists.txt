cmake_minimum_required(VERSION 2.8.0)
project(memory)


add_definitions(
        "-g"
        "-O0"
)

include_directories(
        /usr/local/Cellar/gperftools/2.9.1_1/include
)

add_executable(memory main.cpp)


link_libraries(
#        /usr/local/Cellar/gperftools/2.9.1_1
)
# 链接测试库
target_link_libraries( memory /usr/local/Cellar/gperftools/2.9.1_1/lib/libtcmalloc.a )


