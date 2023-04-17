# ChordsEngine\engine\editor
set(EDITOR_NAME Editor)
# 查找所有include目录下的.h和.cpp文件
file(GLOB EDITOR_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB EDITOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB GLAD_C ${THIRD_PARTY_DIR}/glfw/src/*.c)
# 通过source_group来对文件进行分组
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${EDITOR_HEADERS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${EDITOR_SOURCES})

source_group("glad" ${GLAD_C})

# 设置可执行文件
add_executable(
    ${EDITOR_NAME}
    ${EDITOR_HEADERS}
    ${EDITOR_SOURCES}
    ${GLAD_C}
)
set_target_properties(${EDITOR_NAME} PROPERTIES FOLDER "Engine")


include_directories(${GLFW_INCLUDE})  
include_directories(${GLFW_SRC})
link_libraries(${GLFW_LIB})
target_link_libraries(${EDITOR_NAME} PUBLIC ${GLFW_LIB})
target_include_directories(${EDITOR_NAME} PUBLIC ${ENGINE_CORE_DIR})