#pragma once

#include <preprocessor.h>
#include <glm/gtc/type_ptr.hpp>
#include <kernel/context/buffer.h>
#include <vector>
#include <kernel/context/vertexBuffer.h>
#include <kernel/context/indexBuffer.h>
#include <kernel/context/componentBuffer.h>

namespace reboot_driver {
    class REBOOT_API Mesh {
    private:
        reboot_kernel::VertexBuffer  *VBO;
//        reboot_kernel::VertexBuffer *VAO;
        reboot_kernel::IndexBuffer *IBO;
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
        void create(unsigned vertexLocation, float *vertexData, int vertexCount, unsigned componentCount, unsigned *vertexIndex, int indexCount);
        void setBuffer(unsigned location, float *data, int count, unsigned componentCount);
    };
}