
#include <common/event/eventManager.h>
#include <cstring>

namespace reboot{
    EventManager* EventManager::getInstance() {
        static EventManager* inst = new EventManager();
        return inst;
    }

    void EventManager::createEvent(const char *name) {
        auto s = new Subscription();
        s->name=name;
        m_Subscription.push_back(s);
    }

    bool EventManager::subscribe(const char *name, void (*callback)(Event)) {
        auto s = getSubscription(name);
        if(s!= nullptr) {
            s->m_Events.push_back(callback);
            return true;
        }
        return false;
    }
    void EventManager::fire(const char *name, Event &e) {
        auto s = getSubscription(name);
        if(s!= nullptr){
            for (void(*callback)(Event) : s->m_Events) {
                callback(e);
            }
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