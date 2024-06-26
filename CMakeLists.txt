cmake_minimum_required(VERSION 3.1)

project(Project)

# Set C++ version
set(CMAKE_CXX_STANDARD 20)

# Find OpenGL
set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

set(GLFW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GLFW)
add_subdirectory(${GLFW_DIR})

# Add ImGUI and ImPlot sources
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ImGUI_custom_bundle)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/implot.cpp
    ${IMGUI_DIR}/implot_items.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_DIR}/context_setup/context_setup.cpp
)

set(OTHER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/OtherSources/examples.cpp
)

# Add executable target
add_executable(Project main.cpp ${IMGUI_SOURCES} ${OTHER_SOURCES})

find_package(OpenMP)
if(OpenMP_FOUND)
    message(STATUS "OpenMP found")
    target_link_libraries(Project OpenMP::OpenMP_CXX)
else()
    message(STATUS "OpenMP not found")
endif()

# Include directories for ImGUI
target_include_directories(Project PUBLIC ${IMGUI_DIR})
target_include_directories(Project PUBLIC ${IMGUI_DIR}/backends)
target_include_directories(Project PUBLIC ${IMGUI_DIR}/context_setup)

target_include_directories(Project PUBLIC ${GLFW_DIR}/include)

# Link OpenGL and GLFW libraries
target_link_libraries(Project ${OPENGL_gl_LIBRARY} glfw)
target_compile_options(Project PRIVATE -O2 -Wall)