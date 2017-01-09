#pragma once

#include "../../preprocessor.h"
#include <driver/mesh/mesh.h>

namespace reboot
{
	class REBOOT_API Renderer
	{
    public:
        reboot_driver::Mesh *m_Mesh;
	public:
		Renderer(reboot_driver::Mesh*mesh):m_Mesh(mesh){}
        void render(BYTE rendermode);

    };
}
