#pragma once

#include <GL/glew.h>

#include <vector>

namespace GraphicsEngine {
    struct VertexBufferElement {
        unsigned int type;
        unsigned int count;
        unsigned char normilized;

        static unsigned int GetSizeOfType(unsigned int type) {
            switch (type) {
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

    class VertexBufferLayout {
    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;

    public:
        VertexBufferLayout()
                : m_Stride(0) {};

        void Push(unsigned int type, unsigned int count) {
            switch (type) {
                case GL_FLOAT:
                    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
                    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
                    break;
                case GL_UNSIGNED_INT:
                    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
                    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
                    break;
                case GL_UNSIGNED_BYTE:
                    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
                    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
                    break;
                default:
                    break;
            }
        }

        inline const std::vector<VertexBufferElement> &GetElements() const { return m_Elements; }

        inline unsigned int GetStride() const { return m_Stride; }
    };
}