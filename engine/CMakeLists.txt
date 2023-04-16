# ChordsEngine\engine



set(ENGINE_ROOT_DIR ${PROJECT_ROOT_DIR}/engine)
set(ENGINE_CORE_DIR ${ENGINE_ROOT_DIR}/core)
set(THIRD_PARTY_DIR ${ENGINE_ROOT_DIR}/3rdParty)

set(GLFW_INCLUDE ${THIRD_PARTY_DIR}/glfw/include)
set(GLFW_SRC ${THIRD_PARTY_DIR}/glfw/src)
set(GLFW_LIB ${THIRD_PARTY_DIR}/glfw/lib/glfw3.lib)


add_subdirectory(core)
add_subdirectory(editor)
add_subdirectory(3rdParty)

