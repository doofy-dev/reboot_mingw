#pragma once

#include <preprocessor.h>
#include <glm/gtc/type_ptr.hpp>
#include <kernel/context/buffer.h>
#include <vector>

namespace reboot_driver {
    class REBOOT_API Mesh {
    private:
        reboot_kernel::Buffer  *VAO, *VBO, *IBO;
        /*
         * A Vertex Array Object (VAO) is an object which contains one or more Vertex Buffer
         * Objects and is designed to store the information for a complete rendered object.
         *
         * A Vertex Buffer Object (VBO) is a memory buffer in the high speed memory of your
         * video card designed to hold information about vertices. In our example we have two VBOs,
         * one that describes the coordinates of our vertices and another that describes the
         * color associated with each vertex. VBOs can also store information such as normals, texcoords, indicies, etc.
         */
    public:
        Mesh();
        ~Mesh();
        void bind();
        void unbind();
        void load(unsigned vertexLocation, float *vertexData, int vertexCount, unsigned componentCount, unsigned *vertexIndex, int indexCount);
        void addBuffer(unsigned location, float *data, int count, unsigned componentCount);
    };
}