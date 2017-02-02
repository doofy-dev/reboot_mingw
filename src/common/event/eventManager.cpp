
#include <common/event/eventManager.h>
#include <cstring>

namespace reboot{
    EventManager& EventManager::getInstance() {
        static EventManager inst;
        return inst;
    }

    Subscription* EventManager::createEvent(const char *name) {
        auto s = new Subscription();
        s->name=name;
        m_Subscription.push_back(s);
        return s;
    }

    bool EventManager::subscribe(const char *name, EventFun callback) {
        auto s = getSubscription(name);
        if(s!= nullptr) {
            s->addEvent(callback);
            return true;
        }
        return false;
    }
    void EventManager::fire(const char *name, Event *e) {
        auto s = getSubscription(name);
        if(s!= nullptr){
            s->fire(e);
        }
    }
    Subscription* EventManager::getSubscription(const char *name) {
        for (auto s : m_Subscription) {
            if (std::strcmp(s->name, name) == 0) {
                return s;
            }
        }
        return nullptr;
    }
}