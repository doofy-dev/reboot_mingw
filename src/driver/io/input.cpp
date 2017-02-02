#include <driver/io/input.h>

namespace reboot_driver{
    Input::Input() {
        inputEvent=reboot::EventManager::getInstance().createEvent("INPUT");

        auto callback = [](reboot::Event *event) {
            reboot::KeyEvent* ev= static_cast<reboot::KeyEvent*>(event);
            if(inputMap.find(ev->key) == inputMap.end()){
                inputMap[ev->key]=ev->action;
            }
            std::cout<< ev->key<< " is "<<ev->action<<std::endl;
        };
        inputEvent->addEvent(callback);
    }
    bool Input::getKeyDown(unsigned key) {
        return getKey(key)==1;
    }
    bool Input::getKeyUp(unsigned key) {
        return getKey(key)==0;
    }
    bool Input::getKeyPress(unsigned key) {
        return getKey(key)==2;
    }

    int Input::getKey(unsigned key) {
        if(inputMap.find(key) == inputMap.end()){
            return inputMap[key];
        }
        return 0;
    }
}