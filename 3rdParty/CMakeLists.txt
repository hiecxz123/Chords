
add_subdirectory(spdlog)
add_subdirectory(glfw)

set_target_properties(glfw PROPERTIES FOLDER "ThirdParty/glfw")
set_target_properties(uninstall PROPERTIES FOLDER "ThirdParty/glfw")
set_target_properties(update_mappings PROPERTIES FOLDER "ThirdParty/glfw")

set_target_properties(spdlog PROPERTIES FOLDER "ThirdParty/spdlog")