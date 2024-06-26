cmake_minimum_required(VERSION 3.20)
project(engine3d-physics C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)


add_subdirectory(src)



# Before we copy compile_commands.json to .vscode
# Making sure we should make sure if that dir already exists in the root of the projects directory
set(VSCODE_DIR "./")
# if(NOT EXISTS ${VSCODE_DIR})
#     file(MAKE_DIRECTORY ${VSCODE_DIR})
# endif()


# Creating a customize command specific for copying the compile_commands.json to users .vscode directory
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_LIST_DIR}/compile_commands.json
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_LIST_DIR}/.vscode/compile_commands.json
    DEPENDS
    # Unlike "proper" targets like executables and libraries, 
    # custom command / target pairs will not set up source
    # file dependencies, so we need to list file explicitly here
    generate-compile-commands
    ./compile_commands.json
)

# Generate the compilation commands. Necessary so cmake knows where it came
# from and if for some reason you delete it.
add_custom_target(generate-compile-commands
    DEPENDS
        ./compile_commands.json
)

install(TARGETS ${PROJECT_NAME})