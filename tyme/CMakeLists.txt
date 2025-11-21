# tyme 库的 CMakeLists.txt（拆分后版本）
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(tyme)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 收集所有源文件
set(TYME_SOURCES
    # 主文件（临时禁用测试）
    # tyme.cpp
    # 工具类
    util.cpp
    # culture 模块（已拆分并启用）
    abstract_culture.cpp
    culture/elements.cpp
    culture/basic_culture.cpp
    culture/deities.cpp
    # culture/stars.cpp               # 待拆分
    # culture/geography.cpp           # 待拆分
    
    # sixtycycle 模块
    # sixtycycle/sixtycycle.cpp       # 待拆分
    # sixtycycle/sound.cpp            # 待拆分
    
    # solar 模块
    # solar/solar_calendar.cpp        # 待拆分
    # solar/solar_terms.cpp           # 待拆分
    
    # lunar 模块
    # lunar/lunar_calendar.cpp        # 待拆分
    # lunar/lunar_festival.cpp        # 待拆分
    # lunar/rab_byung.cpp             # 待拆分
    
    # festival 模块
    # festival/festivals.cpp          # 待拆分
    # festival/legal_holiday.cpp      # 待拆分
    
    # special_days 模块
    # special_days/dog_days.cpp       # 待拆分
    # special_days/nine_days.cpp      # 待拆分
    # special_days/plum_rain.cpp      # 待拆分
    # special_days/phenology.cpp      # 待拆分
    
    # divination 模块
    # divination/fetus.cpp            # 待拆分
    # divination/pengzu.cpp           # 待拆分
    # divination/taboo.cpp            # 待拆分
    # divination/minor_ren.cpp        # 待拆分
    
    # 临时保留原文件（拆分完成后删除）
    tyme.cpp
)

# 收集所有头文件
set(TYME_HEADERS
    util.h
    
    # culture 模块（已拆分并启用）
    abstract_culture.h
    culture/elements.h
    culture/basic_culture.h
    culture/deities.h
    
    # culture 模块（待拆分）
    # culture/stars.h
    # culture/geography.h
    
    # 其他头文件...
    
    tyme.h
)

# 创建共享库
add_library(tyme SHARED ${TYME_SOURCES} ${TYME_HEADERS})

# 设置包含目录（让子目录可以找到头文件）
target_include_directories(tyme 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/culture
        ${CMAKE_CURRENT_SOURCE_DIR}/sixtycycle
        ${CMAKE_CURRENT_SOURCE_DIR}/solar
        ${CMAKE_CURRENT_SOURCE_DIR}/lunar
        ${CMAKE_CURRENT_SOURCE_DIR}/festival
        ${CMAKE_CURRENT_SOURCE_DIR}/special_days
        ${CMAKE_CURRENT_SOURCE_DIR}/divination
)

# 设置输出目录
set_target_properties(tyme PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# 安装规则
install(TARGETS tyme
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# 安装头文件
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION include/tyme
    FILES_MATCHING PATTERN "*.h"
)

# 编译选项
if(MSVC)
    target_compile_options(tyme PRIVATE /W4)
else()
    target_compile_options(tyme PRIVATE -Wall -Wextra -Wpedantic)
endif()

# 显示配置信息
message(STATUS "Tyme library configuration:")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  Source files: ${TYME_SOURCES}")
