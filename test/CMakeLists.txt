cmake_minimum_required(VERSION 3.15)
project(test)

# 搜索源文件
aux_source_directory(./ SRC)
# 头文件包含路径
include_directories(${HEADPATH})
# 指定静态库路径
link_directories(${LIBPATH})
# 链接静态库
link_libraries(${CH2LIB} ${COSTRUCTLIB} ${CH5LIB})
# 可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})
# 生成可执行文件
add_executable(${APPNAME} ${SRC})