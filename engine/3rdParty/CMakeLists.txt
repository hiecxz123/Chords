set(THIRD_PARTY_FOLDER "ThirdParty")

option(GLFW_BUILD_EXAMPLES "" OFF)
option(GLFW_BUILD_TESTS "" OFF)
option(GLFW_BUILD_DOCS "" OFF)
option(GLFW_INSTALL "" OFF)
add_subdirectory(glfw)
set_target_properties(glfw PROPERTIES FOLDER ${THIRD_PARTY_FOLDER})
#set_target_properties(update_mappings PROPERTIES FOLDER ${THIRD_PARTY_FOLDER}/glfw)