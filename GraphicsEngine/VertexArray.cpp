#include "VertexArray.h"
#include "VertexBufferLayout.h"

namespace GraphicsEngine
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_RendererID);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void VertexArray::AddBuffer(const VertexBuffer &_vb, const VertexBufferLayout &_layout)
    {
        Bind();
        _vb.Bind();
        const auto &elements = _layout.GetElements();
        unsigned int offset = 0;
        for (unsigned int i = 0; i < elements.size(); i++)
        {
            const auto &element = elements[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, element.count, element.type, element.normilized, _layout.GetStride(),
                                  (const void *) offset);
            offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
        }
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
}