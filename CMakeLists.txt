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
set(GLEW_INCLUDE "${LIB_DIR}/glew/include")
set(GLEW_STATIC)

set(GLEW_LIB "${LIB_DIR}/glew/lib/libglew32.a")

#GLFW
#set(GLFW_INCLUDE "${LIB_DIR}/glfw-3.2.1/include")
#if (${TARGET} EQUAL "WIN64")
#    set(GLFW_DYNAMIC "${LIB_DIR}/glfw-3.2.1/lib-mingw-w64/glfw3.dll")
#    set(GLFW_LIB "${LIB_DIR}/glfw-3.2.1/lib-mingw-w64")
#else ()
#    set(GLFW_DYNAMIC "${LIB_DIR}/glfw-3.2.1/lib-mingw/glfw3.dll")
#    set(GLFW_LIB "${LIB_DIR}/glfw-3.2.1/lib-mingw")
#endif ()
#configure_file(${GLFW_DYNAMIC} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/glfw3.dll COPYONLY)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("${LIB_DIR}/glfw-3.2.1")
set(GLFW_INCLUDE "${LIB_DIR}/glfw-3.2.1/include")

#GLM
set(GLM_INCLUDE "${LIB_DIR}/glm")

#LUA
set(LUA_INCLUDE "${LIB_DIR}/lua/include")

#CEREAL
set(CEREAL_INCLUDE "${LIB_DIR}/cereal-1.2.1/include")


include_directories(${INCLUDE_DIRECTORY} ${GLEW_INCLUDE} ${GLM_INCLUDE} ${GLFW_INCLUDE} ${LUA_INCLUDE} ${CEREAL_INCLUDE})
#link_libraries(${GLEW_LIB})


add_library(lua_static STATIC IMPORTED)
set_target_properties(lua_static PROPERTIES
        IMPORTED_LOCATION ${LIB_DIR}/lua/liblua.a)


add_definitions(-DGLEW_STATIC)
add_library(glew_static STATIC IMPORTED)
set_target_properties(glew_static PROPERTIES
        IMPORTED_LOCATION ${GLEW_LIB})


link_directories(${GLFW_LIB})

set(REBOOT_SOURCE
        src/kernel/canvas/canvas.cpp src/kernel/canvas/window.cpp src/kernel/context/openGL/shaderProgram.cpp src/kernel/context/shaderProgram.cpp
        src/driver/context.cpp
        src/engine/entity/gameObject.cpp src/engine/engine.cpp src/engine/scene.cpp src/engine/component/component.cpp
        src/driver/mesh/mesh.cpp src/engine/component/renderer.cpp src/kernel/context/openGL/buffer.cpp src/kernel/context/openGL/indexBuffer.cpp src/kernel/context/openGL/vertexArray.cpp src/engine/entity/camera.cpp src/engine/component/transform.cpp src/common/event/eventManager.cpp include/common/simplexNoise.h src/common/simplexNoise.cpp src/driver/io/input.cpp)

set(REBOOT_INCLUDE
        include/kernel/canvas/canvas.h include/kernel/canvas/window.h include/kernel/context/openGL/shaderProgram.h include/kernel/context/shaderProgram.h
        include/driver/context.h
        include/engine/entity/gameObject.h include/engine/engine.h include/engine/scene.h
        include/driver/mesh/mesh.h include/kernel/opengl.h include/common/tree.h sample.h
        include/kernel/context/buffer.h include/kernel/context/indexBuffer.h include/kernel/context/vertexArray.h
        include/kernel/context/openGL/vertexArray.h include/kernel/context/openGL/indexBuffer.h include/kernel/context/openGL/buffer.h include/driver/scripting/luaHandler.h include/engine/component/script.h include/driver/io/input.h)

set(SOURCE_FILES main.cpp ${REBOOT_SOURCE} ${REBOOT_INCLUDE})

#dll export
#add_library(reboot SHARED ${SOURCE_FILES})
#exe export
add_executable(reboot ${SOURCE_FILES})

target_link_libraries(reboot glfw lua_static glew_static -lOpengl32 -static-libstdc++ -static-libgcc -Wwrite-strings)