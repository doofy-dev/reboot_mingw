#include <engine/component/renderer.h>

namespace reboot {
    //RendeMode => forward or deferred
    void Renderer::render(BYTE rendermode){
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        m_Mesh->bind();
        glDrawElements(GL_TRIANGLES,
                       m_Mesh->IBO->m_Count, GL_UNSIGNED_INT, 0);
        m_Mesh->unbind();
    }
}