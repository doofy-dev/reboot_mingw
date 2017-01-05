#pragma once
#include <lua.hpp>
//https://gist.github.com/Youka/2a6e69584672f7cb0331#file-lua_myobject-cpp-L37

#define ENGINE "Engine"

#define ENABLE_LUA

#ifdef ENABLE_LUA
#define L_Cast(L,type,tName)(*reinterpret_cast<type**>(luaL_checkudata(L, 1, tName)))
#define L_Create(L,type,tName,...) {*reinterpret_cast<type**>(lua_newuserdata(L, sizeof(type*)))=new type(__VA_ARGS__);luaL_setmetatable(L, tName);}
#define L_Register(L,name,method) {lua_register(L,name,method);luaL_newmetatable(L,name);}
#define L_PushFunction(L, method, name, index){lua_pushcfunction(L, method); lua_setfield(L, index, name);}
#define L_Delete(L,type) delete *reinterpret_cast<type**>(lua_touserdata(L, 1));
#define L_Value(L,value,name){lua_pushvalue(L, value); lua_setfield(L, -2, name);}
#define L_GlobalInt(L,value,name){lua_pushnumber(L, value); lua_setglobal(L, name);}
#else
#define L_Cast(L,type,tName)()
#define L_Create(L,type,tName,...) {}
#define L_Register(L,name,method){}
#define L_PushFunction(L, method, name,index){}
#define L_Delete(L,type){}
#define L_Value(L,value,name){}
#endif


#include <engine/engine.h>
static int create(lua_State *L){
    L_Cast(L,reboot::Engine,ENGINE)->start();
    return 0;
}
static int resolution(lua_State *L){
    unsigned w =(unsigned) lua_tonumber(L, 2);
    unsigned h = (unsigned) lua_tonumber(L, 3);
    L_Cast(L,reboot::Engine,ENGINE)->setResolution(w,h);
    return 0;
}
static int engine_new(lua_State *L){
    int canvas = (int)luaL_checknumber(L, 1);
    int context= (int)luaL_checknumber(L, 2);
    L_Create(L,reboot::Engine,ENGINE,canvas,context);
    return 1;
}
static int del_engine(lua_State *L){
    L_Delete(L,reboot::Engine);
}
static void register_engine(lua_State *L){
    L_GlobalInt(L,0,"OPENGL");
    L_GlobalInt(L,0,"GLFW");
    L_Register(L,ENGINE, engine_new);
    L_Value(L,-1,"__index");
    L_PushFunction(L,del_engine,"__gc",-2);
    L_PushFunction(L,create,"start",-2);
    L_PushFunction(L,resolution,"resolution",-2);

    lua_pop(L, 1);
}