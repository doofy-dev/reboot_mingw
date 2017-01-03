#pragma once

#include "../../preprocessor.h"

namespace reboot {
    class GameObject;

    class REBOOT_API Component {
    private:
        bool m_Enabled;
    public:
        GameObject *gameObject;
    public:
        Component();

        ~Component();

        virtual void update();

        virtual void begin() {}

        virtual void end() {}

        inline bool active() const { return m_Enabled; }

        void setActive(bool active) { m_Enabled = active; }

    };
}