#pragma once

#include <preprocessor.h>
#include <common/event/eventManager.h>
#include <map>


namespace reboot_driver{
    class REBOOT_API Input{
        reboot::Subscription* inputEvent;

        std::map<int, int> inputMap;
    public:
        Input();
        bool getKeyDown(unsigned key);
        bool getKeyUp(unsigned key);
        bool getKeyPress(unsigned key);

    private:
        int getKey(unsigned key);
    };
}