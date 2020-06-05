#pragma once

namespace GraphicsEngine
{
    class IndexBuffer
    {
    public:
        IndexBuffer(const unsigned int *, unsigned int);

        ~IndexBuffer();

        void Bind() const;

        void Unbind() const;

        inline unsigned int GetCount() const { return m_Count; }

    private:
        unsigned int m_RendererID;
        unsigned int m_Count;
    };
}
