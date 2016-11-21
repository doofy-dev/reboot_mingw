cmake_minimum_required(VERSION 3.6)
project(Reboot)

set(TARGET "WIN32")
#add_definitions(-DTARGET=${TARGET})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
#set(TARGET_ARCHITECTURE "x64")
set(INCLUDE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include")

#GLEW
set(GLEW_INCLUDE "${LIB_DIR}/glew-2.0.0/include")
set(GLEW_STATIC)
if (${TARGET} EQUAL "WIN64")
    set(GLEW_LIB "${LIB_DIR}/glew-2.0.0/lib/Release/x64/glew32s.lib")
else()
    set(GLEW_LIB "${LIB_DIR}/glew-2.0.0/lib/Release/Win32/glew32s.lib")
endif ()

#GLFW
set(GLFW_INCLUDE "${LIB_DIR}/glfw-3.2.1/include")
if (${TARGET} EQUAL "WIN64")
    set(GLFW_DYNAMIC "${LIB_DIR}/glfw-3.2.1/lib-mingw-w64/glfw3.dll")
    set(GLFW_LIB "${LIB_DIR}/glfw-3.2.1/lib-mingw-w64")
else()
    set(GLFW_DYNAMIC "${LIB_DIR}/glfw-3.2.1/lib-mingw/glfw3.dll")
    set(GLFW_LIB "${LIB_DIR}/glfw-3.2.1/lib-mingw")
endif ()
configure_file(${GLFW_DYNAMIC} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/glfw3.dll COPYONLY)

#GLM
set(GLM_INCLUDE "${LIB_DIR}/glm")


include_directories(${INCLUDE_DIRECTORY} ${GLEW_INCLUDE} ${GLM_INCLUDE} ${GLFW_INCLUDE})
#link_libraries(${GLEW_LIB})
add_definitions(-DGLEW_STATIC)
add_library(glew_static STATIC IMPORTED)
set_target_properties(glew_static PROPERTIES
        IMPORTED_LOCATION ${GLEW_LIB})
link_directories(${GLFW_LIB})

set(REBOOT_SOURCE
        src/adapter/canvas/canvas.cpp src/adapter/canvas/window.cpp src/adapter/context/openGL/oglShader.cpp src/adapter/context/shaderProgram.cpp
        src/driver/contextManager.cpp
        src/engine/entity/gameObject.cpp src/engine/engine.cpp src/engine/scene.cpp src/engine/component/component.cpp
        )
set(REBOOT_INCLUDE
        include/adapter/canvas/canvas.h include/adapter/canvas/window.h include/adapter/context/openGL/oglShader.h include/adapter/context/shaderProgram.h
        include/driver/contextManager.h
        include/engine/entity/gameObject.h include/engine/engine.h include/engine/scene.h
        include/driver/mesh/mesh.h include/adapter/context/indexBuffer.h include/adapter/context/openGL/oglIndexBuffer.h include/adapter/opengl.h include/adapter/context/vertexArray.h include/adapter/context/openGL/oglVertexArray.h include/adapter/context/openGL/oglArrayBuffer.h include/adapter/context/arrayBuffer.h)

set(SOURCE_FILES main.cpp ${REBOOT_SOURCE} ${REBOOT_INCLUDE} src/adapter/context/openGL/oglIndexBuffer.cpp src/adapter/context/openGL/oglVertexArray.cpp)

#dll export
#add_library(reboot SHARED ${SOURCE_FILES})
#exe export
add_executable(reboot ${SOURCE_FILES})

target_link_libraries(reboot glfw3 glew_static -lOpengl32 -static-libstdc++ -static-libgcc -Wwrite-strings)