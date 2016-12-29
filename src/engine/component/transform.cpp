#include <engine/component/transform.h>

namespace reboot{
    Transform::Transform() {
        position=new glm::vec3(0,0,1);
        rotation=new glm::vec3(0);
        scale=new glm::vec3(0);
    }
}