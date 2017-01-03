#include <engine/component/component.h>
#include <engine/entity/gameObject.h>
#include <glm/gtc/type_ptr.hpp>
#include <engine/component/transform.h>

namespace reboot{
    Component::Component() {

    }
    Component::~Component() {}
    void Component::update() {
        gameObject->transform->position=glm::vec3(0,0,-1);
        gameObject->transform->rotation = glm::vec3(gameObject->transform->rotation.x+0.01f,gameObject->transform->rotation.y+0.01f,gameObject->transform->rotation.z+0.01f);
    }
}