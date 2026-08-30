cmake_minimum_required(VERSION 3.20)
project(Vulkanized)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)

set(GLFW_DIR "C:/VulkanGLFW/glfw-3.4.bin.WIN64")

file(GLOB SOURCES "src/*.cpp")

#Main Executable
add_executable(Vulkanized ${SOURCES})

target_include_directories(Vulkanized PRIVATE
    include
    ${Vulkan_INCLUDE_DIRS}
    ${GLFW_DIR}/include
)

target_link_libraries(Vulkanized PRIVATE
    Vulkan::Vulkan
    ${GLFW_DIR}/lib-vc2022/glfw3.lib
)

#Shader Compiler
find_program(GLSLC glslc
    HINTS "$ENV{VULKAN_SDK}/Bin" "C:/VulkanSDK/1.4.350.0/Bin"
)

if(GLSLC)
    set(SHADER_SOURCES
        ${CMAKE_SOURCE_DIR}/shaders/vk_shader.vert
        ${CMAKE_SOURCE_DIR}/shaders/vk_shader.frag
    )

    foreach(SHADER ${SHADER_SOURCES})
        get_filename_component(SHADER_NAME ${SHADER} NAME)
        set(SPIRV ${CMAKE_BINARY_DIR}/shaders/${SHADER_NAME}.spv)
        add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/shaders
            COMMAND ${GLSLC} ${SHADER} -o ${SPIRV}
            DEPENDS ${SHADER}
        )
        list(APPEND SPIRV_BINARIES ${SPIRV})
    endforeach()

    add_custom_target(Shaders DEPENDS ${SPIRV_BINARIES})
else()
    message(WARNING "glslc not found — Shaders target will be unavailable")
endif()