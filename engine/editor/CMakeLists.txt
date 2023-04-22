# ChordsEngine\engine\editor
set(EDITOR_NAME Editor)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/lib)
# 查找所有include目录下的.h和.cpp文件
file(GLOB EDITOR_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB EDITOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
# 通过source_group来对文件进行分组
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${EDITOR_HEADERS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${EDITOR_SOURCES})

message("cmake project name: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
link_libraries(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/Debug/Core.lib)


# 设置可执行文件
add_executable(
    ${EDITOR_NAME}
    ${EDITOR_HEADERS}
    ${EDITOR_SOURCES}
)
set_target_properties(${EDITOR_NAME} PROPERTIES FOLDER "Engine")


#include_directories(${GLFW_INCLUDE})  
#include_directories(${GLFW_SRC})
#link_libraries(${GLFW_LIB})
#target_link_libraries(${EDITOR_NAME} PUBLIC ${GLFW_LIB})
target_include_directories(${EDITOR_NAME} PUBLIC ${ENGINE_CORE_DIR})
target_include_directories(${EDITOR_NAME} PUBLIC ${SPDLOG_INCLUDE_DIR})
include_directories(${SPDLOG_INCLUDE_DIR}) 
include_directories(${THIRD_PARTY_DIR}) 

target_include_directories(${EDITOR_NAME} PUBLIC ${ENGINE_CORE_DIR}/3rdParty/include)