# ChordsEngine
# set CMake minimum version
cmake_minimum_required (VERSION 3.10.2)

# ���û�����Ŀ
set(PROJECT_VERSION "0.0.1.0" CACHE STRING "Ĭ�ϰ汾��")
# 1. �����������ļ��еĿ���
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(BINARY_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# ������Ŀ���� ������Ŀ���ƺ���?�� PROJECT_NAME ��ȡ��Ŀ����
project(GameEngine)

add_subdirectory(engine)
add_subdirectory(3rdParty/spdlog)


# print project name
# Ҳ����ͨ��set(PROJECT_NAME set_test) ������Ŀ���� ����PROJECT_NAME������
message ("project name: ${PROJECT_NAME}")
# �Ӷ���CMakeLists.txt����ʱ������project���ƴ洢�ڱ���CMAKE_PROJECT_NAME��
message("cmake project name: ${CMAKE_PROJECT_NAME}")
# ��ӡ��Ŀ·����CMakeLists.txt�ļ�����·��
message("project source dir: ${PROJECT_SOURCE_DIR}")

message("project name source dir: ${${PROJECT_NAME}_SOURCE_DIR}")
# project is top level: ON
message("project is top level: ${PROJECT_IS_TOP_LEVEL}")
# project name is top level: ON
message("project name is top level: ${${PROJECT_NAME}_IS_TOP_LEVEL}") 

# message("lib path: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}") 

# message("CMAKE_INSTALL_PREFIX:::" ${CMAKE_INSTALL_PREFIX})

# ���ñ���normal_var��ֵΪa;b;c
set (normal_var a b c)
# �����??>>> value = a;b;c
message (">>> value = ${normal_var}")
# ���ñ���Ϊ��
set (normal_var) 
# �����??>>> value = 
message (">>> value = ${normal_var}")

# ���庯��
function(func)
    # ��ӡ������־��
    # STATUS:�����ڱ�������е�Debug��Ϣ;
    # FATAL_ERROR:����CMake Error,��ֹͣ����ϵͳ�Ĺ�������
    message(STATUS "call func")
    # �������ʾ��??
    # CMAKE_SIZEOF_VOID_P ������ȡVoid���͵Ĵ�С
    if (CMAKE_SIZEOF_VOID_P EQUAL 4)
        message(STATUS "X86")   # 32λϵͳ����ӡX86
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 8)
        message(STATUS "X64")   # 32λϵͳ����ӡX64
    endif()
endfunction(func)
# �������÷�ʽ�������ִ�Сд
func()
FUnc()
fuNC()


