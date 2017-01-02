#pragma once

#include "../../preprocessor.h"

namespace reboot {
    class REBOOT_API Event {
    public:
        Event() {}
    };

    class REBOOT_API KeyEvent : public Event {
    public:
        const int key;
        const int scanCode;
        const int action; //up, press, down
        const int mods; //shift, ctrl, alt

        KeyEvent(int key, int scanCode, int action, int mods)
                : Event(), key(key), scanCode(scanCode), action(action), mods(mods) {}
    };

    class REBOOT_API MoveEvent : public Event {
    public:
        const double posX, posY;

        MoveEvent(double posX, double posY) : Event(), posX(posX), posY(posY) {}
    };
}