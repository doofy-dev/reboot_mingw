#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <reboot.h>

int main() {
    reboot::Engine a(CONTEXT_OPENGL4, CANVAS_GLFW);
    a.setFpsLimit(0);
//setup everything
    reboot::Scene *s;
    s = new reboot::Scene((char *) "main");
    a.setScene(s);
    glm::vec3(0, 0, 0);
    a.start();
    return 0;
}