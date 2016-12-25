#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <reboot.h>
#include <driver/material/material.h>
#include "sample.h"


int main() {
    reboot::Engine a(CONTEXT_OPENGL4, CANVAS_GLFW);
    a.setFpsLimit(0);
    a.setResolution(1024,768);
//setup everything
    a.setRenderMode(RENDER_FORWARD);
    reboot::Scene *s;
    s = new reboot::Scene((char *) "main");
    reboot_driver::Mesh *m = new reboot_driver::Mesh();
    m->create(0,verticles, 72, 3, indices, 36);

    a.setScene(s);
    glm::vec3(0, 0, 0);
    a.start();
    return 0;
}