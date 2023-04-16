# ChordsEngine\core
set(CORE_NAME Core)
# 查找所有include目录下的.h和.cpp文件
file(GLOB_RECURSE CORE_HEADERS "*.h")
file(GLOB_RECURSE CORE_SOURCES "*.cpp")


# 通过source_group来对文件进行分组,TREE使用实际路径，第二个参数是相对路径截取
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CORE_HEADERS} ${CORE_SOURCES})

# add_library(${CORE_NAME} ${CORE_HEADERS} ${CORE_SOURCES})


# 设置可执行文件
add_executable(${CORE_NAME} ${CORE_HEADERS} ${CORE_SOURCES})

# 2. 把工程加到文件夹中
set_target_properties(${CORE_NAME} PROPERTIES FOLDER "Engine")
# 3. 给 cmake 自动创建的工程重新命名, 默认名为 "CMakePredefinedTargets" 
# set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "Engine")
