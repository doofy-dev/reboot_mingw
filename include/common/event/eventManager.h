#pragma once

#include <vector>

#include "../../preprocessor.h"
#include "event.h"

namespace reboot
{
	struct REBOOT_API Subscription {
		const char* name;
		std::vector<void(*)(Event)> m_Events;
	};
	class REBOOT_API EventManager {
	private:
		EventManager();
		std::vector<Subscription*> m_Subscription;
	public:
		static EventManager* getInstance();
		void createEvent(const char* name);
		void fire(const char* name, Event &e);
		bool subscribe(const char* name, void(*callback)(Event));
		Subscription* getSubscription(const char* name);
	};
}