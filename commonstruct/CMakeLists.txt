cmake_minimum_required(VERSION 3.15)
project(commostruct)

# 搜索源文件
aux_source_directory(./ SRC)
# 头文件包含路径
include_directories(${HEADPATH})
# 指定静态库生成路径（存到哪）
set(LIBRARY_OUTPUT_PATH ${LIBPATH})
# 生成静态库
add_library(${COSTRUCTLIB} STATIC ${SRC})