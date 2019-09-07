# The project's name
project(EffekseerMaterialEditor)

# Check cmake version
cmake_minimum_required(VERSION 3.0)

# For MSVC
if (MSVC)
    option(USE_MSVC_RUNTIME_LIBRARY_DLL "Use MSVC runtime library DLL" OFF)
endif()

# For Mac
if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET 10.10)
endif()

if (MSVC)

elseif (MINGW)
    set(CMAKE_CXX_FLAGS "-std=c++14" ${CMAKE_CXX_FLAGS})
else()
    set(CMAKE_CXX_FLAGS "-std=c++14 -fPIC" ${CMAKE_CXX_FLAGS})
endif()

file(GLOB srcs 
    *.cpp
    Graphics/*.cpp)

file(GLOB hs 
    *.h
    Graphics/*.h)

file(GLOB srcs_third_imgui
    ThirdParty/imgui_main/*.cpp)

file(GLOB srcs_third_imgui_platform
    ThirdParty/imgui_platform/imgui_impl_opengl3.cpp
    ThirdParty/imgui_platform/imgui_impl_glfw.cpp)

file(GLOB srcs_third_node
    ThirdParty/NodeEditor/Source/*.cpp)

file(GLOB srcs_third_nfd
    ThirdParty/nfd/nfd_common.c
    ThirdParty/nfd/nfd_win.cpp)

link_directories(
    ${PROJECT_SOURCE_DIR}/../lib/
    )

# Add compile targets
add_executable(
    EffekseerMaterialEditor
    ${hs} ${srcs} ${srcs_third_imgui} ${srcs_third_imgui_platform} ${srcs_third_node} ${srcs_third_nfd})

# Flags
if (MSVC)
    if (NOT USE_MSVC_RUNTIME_LIBRARY_DLL)
        foreach (flag CMAKE_C_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            CMAKE_CXX_FLAGS
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE)

            if (${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif()
            if (${flag} MATCHES "/MDd")
                string(REGEX REPLACE "/MDd" "/MTd" ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
endif()

add_dependencies(EffekseerMaterialEditor ExternalProject_glew ExternalProject_glfw)

target_include_directories(
    EffekseerMaterialEditor
	PRIVATE
	${EFK_THIRDPARTY_INCLUDES}
    ../include/
    ${PROJECT_SOURCE_DIR}/../3rdParty/AltseedRHI/include/
    ../EffekseerMaterial/
    ThirdParty/imgui_platform/
    ThirdParty/imgui_main/
    ThirdParty/picojson/
    ThirdParty/stb_image/
    ThirdParty/NodeEditor/Include/)

target_link_directories(
    EffekseerMaterialEditor
    PRIVATE
    ${EFK_THIRDPARTY_LIBRARY_DIRECTORIES}
)

if (WIN32)

target_link_libraries(
    EffekseerMaterialEditor
    EffekseerMaterial
	effekseer # to use shader loader
	effekseer_renderer_gl # to use shader loader
	IPC
    debug glfw3d
    optimized glfw3
    debug libglew32d
    optimized libglew32
    AltseedRHI)

elseif(APPLE)

FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)

# For Mac
find_library(COCOA_FRAMEWORK Cocoa)
find_library(COCOA_FRAMEWORK Cocoa)
find_library(IOKIT_FRAMEWORK IOKit)
find_library(CORE_FOUNDATION_FRAMEWORK CoreFoundation)
find_library(CORE_VIDEO_FRAMEWORK CoreVideo)

target_link_libraries(
    EffekseerMaterialEditor
    EffekseerMaterial
	effekseer # to use shader loader
	effekseer_renderer_gl # to use shader loader
	IPC
    glfw3
    AltseedRHI
    png16
    z
    EffekseerMaterial
    ${CMAKE_THREAD_LIBS_INIT}
    ${COCOA_FRAMEWORK}
    ${OPENGL_gl_LIBRARY}
    ${OPENGL_glu_LIBRARY}
    ${IOKIT_FRAMEWORK}
    ${CORE_FOUNDATION_FRAMEWORK}
    ${CORE_VIDEO_FRAMEWORK})
endif()

set_target_properties(EffekseerMaterialEditor PROPERTIES LINKER_LANGUAGE CXX)

set(files ${hs} ${srcs} ${srcs_third_imgui} ${srcs_third_imgui_platform} ${srcs_third_node} ${srcs_third_nfd})

foreach(FILE ${files}) 
    # Get the directory of the source file
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)

    # Remove common directory prefix to make the group
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")

    # Make sure we are using windows slashes
    string(REPLACE "/" "\\" GROUP "${GROUP}")
        
    # Group into "Source Files" and "Header Files"
    if ("${FILE}" MATCHES ".*\\.cpp")
       set(GROUP "${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.c")
       set(GROUP "${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.cxx")
       set(GROUP "${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
       set(GROUP "${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.mm")
       set(GROUP "${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
endforeach()

set_target_properties( EffekseerMaterialEditor PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/Dev/release )
set_target_properties( EffekseerMaterialEditor PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG  ${CMAKE_SOURCE_DIR}/Dev/release )
set_target_properties( EffekseerMaterialEditor PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE  ${CMAKE_SOURCE_DIR}/Dev/release )

if (WIN32)
    add_custom_command(TARGET EffekseerMaterialEditor POST_BUILD        # Adds a post-build event to MyTest
        COMMAND ${CMAKE_COMMAND} -E copy  # which executes "cmake - E copy_if_different..."
        $<TARGET_FILE:EffekseerMaterialEditor>
        ${CMAKE_SOURCE_DIR}/Dev/release/EffekseerMaterialEditor.exe)                 # <--this is out-file path
elseif(APPLE)
    add_custom_command(TARGET EffekseerMaterialEditor POST_BUILD        # Adds a post-build event to MyTest
        COMMAND ${CMAKE_COMMAND} -E copy  # which executes "cmake - E copy_if_different..."
        $<TARGET_FILE:EffekseerMaterialEditor>
        ${CMAKE_SOURCE_DIR}/Dev/release/EffekseerMaterialEditor )                 # <--this is out-file path
else()
    add_custom_command(TARGET EffekseerMaterialEditor POST_BUILD        # Adds a post-build event to MyTest
        COMMAND ${CMAKE_COMMAND} -E copy  # which executes "cmake - E copy_if_different..."
        $<TARGET_FILE:EffekseerMaterialEditor>
        ${CMAKE_SOURCE_DIR}/Dev/release/EffekseerMaterialEditor )                 # <--this is out-file path
endif()