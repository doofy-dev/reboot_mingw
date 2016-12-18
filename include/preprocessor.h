#pragma once

#ifdef REBOOT_LIB
    #ifdef REBOOT_DYNAMIC
        #define REBOOT_API __declspec(dllexport)
    #else
        #define REBOOT_API __declspec(dllimport)
    #endif
#else
#define REBOOT_API
#endif

typedef unsigned char BYTE;

//RENDERING CANVAS
#define CANVAS_GLFW 0
#define CANVAS_FRAME 0x00000010

//RENDERING CONTEXT
#define CONTEXT_OPENGL4 0
#define CONTEXT_VULKAN 0x00000020

//PIPELINE
#define RENDER_FORWARD 0
#define RENDER_DEFERRED 0x00000030

//DEBUGGING, VISUAL HELPERS
#define DEBUG_DISABLED false
#define DEBUG_ENABLED true

//THREADED LOADING
#define THREADING_DISABLED false
#define THREADING_ENABLED true

//WINDOW TYPE
#define WINDOW_TYPE_WINDOW 0
#define WINDOW_TYPE_BORDERLESS 0x00000001
#define WINDOW_TYPE_FULLSCREEN 0x00000002

//SHADER TYPE
#define SHADER_VERTEX 0
#define SHADER_FRAGMENT 0x00000041
#define SHADER_GEOMETRY 0x00000042

//BUFFER TYPE
#define BUFFER_TYPE_INDEX 0
#define BUFFER_TYPE_VERTEX 0x00000051
#define BUFFER_TYPE_FRAME 0x00000052
#define BUFFER_TYPE_INSTANCE 0x00000053


//Camera type
#define CAMERA_PERSPECTIVE 0
#define CAMERA_ORTHOGRAPHIC 0x00000061

#define MAX_LAYERS 12	//required?

//ERRORS
#define REBOOT_UNAVAILABLE 0x00001000
#define REBOOT_CONTEXT_ERROR 0x00010001
#define REBOOT_SHADER_FAILED 0x00010002

