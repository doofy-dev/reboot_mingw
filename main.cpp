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


void print_error(lua_State *state) {
    // The error message is on top of the stack.
    // Fetch it, print it and then pop it off the stack.
    const char *message = lua_tostring(state, -1);
    puts(message);
    lua_pop(state, 1);
}

void execute(const char *filename) {
    lua_State *state = luaL_newstate();

    // Make standard libraries available in the Lua object
    luaL_openlibs(state);

    register_engine(state);
    int result;

    // Load the program; this supports both source code and bytecode files.
    result = luaL_loadfile(state, filename);

    if (result != LUA_OK) {
        print_error(state);
        return;
    }

    // Finally, execute the program by calling into it.
    // Change the arguments if you're not running vanilla Lua code.

    result = lua_pcall(state, 0, LUA_MULTRET, 0);

    if (result != LUA_OK) {
        print_error(state);
        return;
    }
}


#define X .525731112119133606
#define Z .850650808352039932
std::vector<float> vdata = {
        -X, 0.0, Z, X, 0.0, Z, -X, 0.0, -Z, X, 0.0, -Z,
        0.0, Z, X, 0.0, Z, -X, 0.0, -Z, X, 0.0, -Z, -X,
        Z, X, 0.0, -Z, X, 0.0, Z, -X, 0.0, -Z, -X, 0.0
};
std::vector<float> iNorm;
std::vector<unsigned> tindices = {
        0, 4, 1, 0, 9, 4, 9, 5, 4, 4, 5, 8, 4, 8, 1,
        8, 10, 1, 8, 3, 10, 5, 3, 8, 5, 2, 3, 2, 7, 3,
        7, 10, 3, 7, 6, 10, 7, 11, 6, 11, 0, 6, 0, 1, 6,
        6, 1, 10, 9, 0, 11, 9, 11, 2, 9, 2, 5, 7, 2, 11
};

void calcNormals() {
    for (int i = 0; i < tindices.size(); i++) {
        glm::vec3 v1(vdata[tindices[i]*3], vdata[tindices[i]*3+1], vdata[tindices[i]*3+2]);
        i++;
        glm::vec3 v2(vdata[tindices[i]*3], vdata[tindices[i]*3+1], vdata[tindices[i]*3+2]);
        i++;
        glm::vec3 v3(vdata[tindices[i]*3], vdata[tindices[i]*3+1], vdata[tindices[i]*3+2]);

        glm::vec3 U = v2-v1;
        glm::vec3 V = v3-v1;
        iNorm.push_back(U.y*V.z - U.z-V.y);
        iNorm.push_back(U.z*V.x - U.x*V.z);
        iNorm.push_back(U.x*V.y - U.y*V.x);
    }
}


using namespace reboot;

int main() {

//execute("sample.lua");


//    lua_State *L = luaL_newstate();
    Engine a(CONTEXT_OPENGL4, CANVAS_GLFW);
    a.setFpsLimit(0);
    a.setResolution(1024, 768);
//setup everything
    a.setRenderMode(RENDER_FORWARD);
    Scene *s;
    s = new Scene((char *) "main");
    reboot_driver::Mesh *m = new reboot_driver::Mesh();

    m->create(0,verticles, vertCount, 3, indices, indiceCount);
    m->setBuffer(1,verticles,vertCount,3);
    m->setBuffer(2,normals,vertCount,3);
//calcNormals();
//    m->create(0, &vdata[0], (int) vdata.size(), 3, &tindices[0], (int) tindices.size());
//    m->setBuffer(1, &vdata[0], (int)vdata.size(), 3);
    m->setBuffer(2, &iNorm[0], (int)vdata.size(), 3);
    reboot_driver::Material *mat = new reboot_driver::Material();
    const char *frag = reboot_driver::FileLoader::readAll("shader/sample_frag.glsl");
    const char *vert = reboot_driver::FileLoader::readAll("shader/sample_vert.glsl");
    mat->loadShader(SHADER_FRAGMENT, frag);
    mat->loadShader(SHADER_VERTEX, vert);
    m->setMaterial(mat);
    GameObject *g = new GameObject();
    g->renderer = new Renderer(m);
    s->assignGameObject(g);
    g->addComponent(new Component());
    Camera *c = new Camera(1024, 768);
    s->assignCamera(c, true);


    std::ofstream os("out.cereal");
    cereal::JSONOutputArchive archive(os);
    archive(CEREAL_NVP(*g));

    a.setScene(s);
    glm::vec3(0, 0, 0);
    a.start();
    return 0;
}