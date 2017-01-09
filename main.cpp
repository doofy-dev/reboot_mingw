#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <reboot.h>
#include <driver/io/fileLoader.h>
#include "sample.h"
#include <engine/component/renderer.h>
#include <engine/component/component.h>

#include <driver/scripting/luaHandler.h>
#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

void print_error(lua_State* state) {
    // The error message is on top of the stack.
    // Fetch it, print it and then pop it off the stack.
    const char* message = lua_tostring(state, -1);
    puts(message);
    lua_pop(state, 1);
}

void execute(const char* filename)
{
    lua_State *state = luaL_newstate();

    // Make standard libraries available in the Lua object
    luaL_openlibs(state);

//    register_engine(state);
    int result;

    // Load the program; this supports both source code and bytecode files.
    result = luaL_loadfile(state, filename);

    if ( result != LUA_OK ) {
        print_error(state);
        return;
    }

    // Finally, execute the program by calling into it.
    // Change the arguments if you're not running vanilla Lua code.

    result = lua_pcall(state, 0, LUA_MULTRET, 0);

    if ( result != LUA_OK ) {
        print_error(state);
        return;
    }
}


using namespace reboot;
int main() {

//execute("sample.lua");


//    lua_State *L = luaL_newstate();
    Engine a(CONTEXT_OPENGL4, CANVAS_GLFW);
    a.setFpsLimit(0);
    a.setResolution(1024,768);
//setup everything
    a.setRenderMode(RENDER_FORWARD);
    Scene *s;
    s = new Scene((char *) "main");
    reboot_driver::Mesh *m = new reboot_driver::Mesh();

    m->create(0,verticles, vertCount, 3, indices, indiceCount);
    m->setBuffer(1,verticles,vertCount,3);
    reboot_driver::Material *mat = new reboot_driver::Material();
    const char* frag=reboot_driver::FileLoader::readAll("shader/sample_frag.glsl");
    const char* vert=reboot_driver::FileLoader::readAll("shader/sample_vert.glsl");
        mat->loadShader(SHADER_FRAGMENT,frag);
        mat->loadShader(SHADER_VERTEX,vert);
    m->setMaterial(mat);
    GameObject *g = new GameObject();
    g->renderer=new Renderer(m);
    s->assignGameObject(g);
    g->addComponent(new Component());
    Camera *c = new Camera(1024,768);
    s->assignCamera(c,true);


    std::ofstream os("out.cereal");
    cereal::JSONOutputArchive archive(os);
    archive(*g);

    a.setScene(s);
    glm::vec3(0, 0, 0);
    a.start();
    return 0;
}