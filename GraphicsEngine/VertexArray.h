#pragma once

#include "VertexBuffer.h"

namespace GraphicsEngine
{
    class VertexBufferLayout;

    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBuffer &, const VertexBufferLayout &);

        void Bind() const;
        void Unbind() const;

    private:
        unsigned int m_RendererID;
    };
}
