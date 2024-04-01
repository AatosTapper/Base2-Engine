cmake_minimum_required(VERSION 3.28)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

project(B2E VERSION 1.0)

find_package(glfw3 REQUIRED)

set(VULKAN_DIR "/Users/aatostapper/VulkanSDK/1.3.275.0/macOS")

include_directories(${VULKAN_DIR}/include ${CMAKE_SOURCE_DIR}/dep/include)
link_directories(${VULKAN_DIR}/lib ${CMAKE_SOURCE_DIR}/dep/lib)

file(GLOB files_src
    "src/*.h"
    "src/*.cpp"
)

add_executable(main 
    ${files_src}
)

target_compile_options(main PRIVATE -Wall -pedantic -Wno-deprecated-volatile)
target_link_libraries(main
    vulkan
    glfw
)