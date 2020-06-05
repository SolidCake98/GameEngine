#pragma once

namespace GraphicsEngine
{
    class VertexBuffer
    {
    public:
        VertexBuffer(const void *, unsigned int);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

    private:
        unsigned int m_RendererID;
    };
}
