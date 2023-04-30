# ChordsEngine\core
set(CORE_NAME core)
set(GLFW_NAME glfw)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/lib)
# 查找所有include目录下的.h和.cpp文件
file(GLOB_RECURSE CORE_HEADERS "*.h")
file(GLOB_RECURSE CORE_SOURCES "*.cpp")
file(GLOB_RECURSE CORE_SOURCES "*.c")

# 通过source_group来对文件进行分组,TREE使用实际路径，第二个参数是相对路径截取
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CORE_HEADERS} ${CORE_SOURCES})

# add_library(${CORE_NAME} ${CORE_HEADERS} ${CORE_SOURCES})

add_library(${CORE_NAME} ${CORE_HEADERS} ${CORE_SOURCES})
# 设置可执行文件
# add_executable(${CORE_NAME} ${CORE_HEADERS} ${CORE_SOURCES})
target_link_libraries(${CORE_NAME} spdlog::spdlog)
target_link_libraries(${CORE_NAME} glfw)

# 2. 把工程加到文件夹中
set_target_properties(${CORE_NAME} PROPERTIES FOLDER "Engine")
target_include_directories(${CORE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(${CORE_NAME} PUBLIC ${THIRD_PARTY_DIR}) 
#target_include_directories(${CORE_NAME} PUBLIC ${ENGINE_CORE_DIR}/3rdParty/include)
target_include_directories(${CORE_NAME} PUBLIC ${THIRDPARTY_ROOT}/spdlog/include)
target_include_directories(${CORE_NAME} PUBLIC ${THIRDPARTY_ROOT}/glad/include)
target_include_directories(${CORE_NAME} PUBLIC ${THIRDPARTY_ROOT}/glad/src)
include_directories(${SPDLOG_INCLUDE_DIR}) 

link_libraries(${ENGINE_CORE_DIR}/3rdParty/lib/spdlog.lib)
link_libraries(${ENGINE_CORE_DIR}/3rdParty/lib/spdlogd.lib)
# target_link_libraries(${TARGET_NAME} PUBLIC spdlog::spdlog)

