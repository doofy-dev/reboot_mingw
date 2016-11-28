#pragma once

#include <vector>
#include <common/tree.h>

#include "../../preprocessor.h"

namespace reboot {
    class Component;

    class Transform;

    class Renderer;

    class REBOOT_API GameObject {
    public:
        const char *m_Name;
        const Transform *transform;
        const Renderer *renderer;

    private:
        Tree<GameObject*> *node;
        bool m_IsActive;
        std::vector<Component *> components;
        int layer;
        unsigned int tag;

    public:
        GameObject(const char *name);

        GameObject() : GameObject("GameObject") {}

        ~GameObject();

        template<typename T>
        T *getComponent();

        GameObject *getChildAt(unsigned ID) {
            return node->getItem(ID);
        }

        void addChild(GameObject *g) {
            node->addChild(g);
            g->node = node->children[node->children.size()-1];
        }

        GameObject *parent() {
            return node->parent->item;
        }

        void removeChildAt(unsigned ID) {
            node->removeItem(ID);
        }

        Component *getComponentAt(unsigned int index);

        void addComponent(Component *component);

        bool isActive() { return m_IsActive; }


        void Update();
    };
}