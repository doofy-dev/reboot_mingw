#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <reboot.h>
#include <driver/io/fileLoader.h>
#include "sample.h"
#include <engine/component/renderer.h>

using namespace reboot;
int main() {
    Engine a(CONTEXT_OPENGL4, CANVAS_GLFW);
    a.setFpsLimit(0);
    a.setResolution(1024,768);
//setup everything
    a.setRenderMode(RENDER_FORWARD);
    Scene *s;
    s = new Scene((char *) "main");
    reboot_driver::Mesh *m = new reboot_driver::Mesh();

    m->create(0,verticles, 4*3, 3, indices, 6);
    m->setBuffer(1,colors,4*4,4);
    reboot_driver::Material *mat = new reboot_driver::Material();
    const char* frag=reboot_driver::FileLoader::readAll("shader/sample_frag.glsl");
    const char* vert=reboot_driver::FileLoader::readAll("shader/sample_vert.glsl");
        mat->loadShader(SHADER_FRAGMENT,frag);
        mat->loadShader(SHADER_VERTEX,vert);
    m->setMaterial(mat);
    GameObject *g = new GameObject();
    g->renderer=new Renderer(m);
    s->assignGameObject(g);

    Camera *c = new Camera(1024,768);
    s->assignCamera(c,true);


    a.setScene(s);
    glm::vec3(0, 0, 0);
    a.start();
    return 0;
}