# 测试项目的 CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加测试可执行文件
add_executable(tests tests.cpp)

# 链接 tyme 库
target_link_libraries(tests PRIVATE tyme)

# 设置包含目录
target_include_directories(tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/tyme
)

# 设置输出目录
set_target_properties(tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

# 显示配置信息
message(STATUS "Tests configuration:")
message(STATUS "  Test executable: tests")
message(STATUS "  Linked libraries: tyme")
