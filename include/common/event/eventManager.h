#pragma once

#include <vector>
#include <functional>
#include "../../preprocessor.h"
#include "event.h"

namespace reboot
{
    typedef void (* EventFun)(reboot::Event*);
	struct REBOOT_API Subscription {
		const char* name;
		std::vector<EventFun> m_Events;
        const void fire(Event *e){
            for(EventFun callback: m_Events)
                callback(e);
        }
        void addEvent(EventFun callback){
            m_Events.push_back(callback);
        }
	};
	class REBOOT_API EventManager {
	private:
		std::vector<Subscription*> m_Subscription;
    private:
        EventManager(){}
	public:
        Subscription* getSubscription(const char* name);
		static EventManager& getInstance();
        Subscription* createEvent(const char* name);
		void fire(const char* name, Event *e);
		bool subscribe(const char* name, EventFun callback);
	};
}