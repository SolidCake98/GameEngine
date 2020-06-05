#pragma once

#include <GL/glew.h>

#include <vector>

namespace GraphicsEngine
{
    struct VertexBufferElement
    {
        unsigned int type;
        unsigned int count;
        unsigned char normilized;

        static unsigned int GetSizeOfType(unsigned int _type)
        {
            switch (_type)
            {
                case GL_FLOAT:
                    return 4;
                case GL_UNSIGNED_INT:
                    return 4;
                case GL_UNSIGNED_BYTE:
                    return 1;
            }

            return 0;
        }
    };

    class VertexBufferLayout
    {
    public:
        VertexBufferLayout()
                : m_Stride(0) {};

        void Push(unsigned int _type, unsigned int _count)
        {
            switch (_type)
            {
                case GL_FLOAT:
                    m_Elements.push_back({GL_FLOAT, _count, GL_FALSE});
                    m_Stride += _count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
                    break;
                case GL_UNSIGNED_INT:
                    m_Elements.push_back({GL_UNSIGNED_INT, _count, GL_FALSE});
                    m_Stride += _count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
                    break;
                case GL_UNSIGNED_BYTE:
                    m_Elements.push_back({GL_UNSIGNED_BYTE, _count, GL_TRUE});
                    m_Stride += _count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
                    break;
                default:
                    break;
            }
        }

        inline const std::vector<VertexBufferElement> &GetElements() const { return m_Elements; }
        inline unsigned int GetStride() const { return m_Stride; }

    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;
    };
}