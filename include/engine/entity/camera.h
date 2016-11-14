#pragma once

#include "../../preprocessor.h"
#include "gameObject.h"

namespace reboot
{
	class Camera : public GameObject
	{
	public:
		int target;
	public:
		Camera();
		~Camera();
		
	};
}