#pragma once

#include <preprocessor.h>
#include <glm/gtc/type_ptr.hpp>
#include <kernel/context/buffer.h>
#include <vector>

namespace reboot_driver {
    class REBOOT_API Mesh {
    private:
        reboot_kernel::Buffer *VAO, *VBO, *IBO;
    public:
        Mesh();
        ~Mesh();
        void bind();
        void unbind();
        void load(unsigned vertexLocation, float *vertexData, int vertexCount, unsigned componentCount, unsigned *vertexIndex, int indexCount);
        void addBuffer(unsigned location, float *data, int count, unsigned componentCount);
    };
}