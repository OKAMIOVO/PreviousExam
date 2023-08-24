cmake_minimum_required(VERSION 3.15)
project(sort)

# 搜索源文件
aux_source_directory(./ SRC)
# 头文件包含路径
include_directories(${HEADPATH})
# 指定静态库生成路径（存到哪）
set(LIBRARY_OUTPUT_PATH ${LIBPATH})
# 生成静态库
add_library(${CH8LIB} STATIC ${SRC})
# 指定静态库路径
link_directories(${LIBPATH})
# 链接静态库
link_libraries(${COSTRUCTLIB})