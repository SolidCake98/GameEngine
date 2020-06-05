#include "Renderer.h"

namespace GraphicsEngine
{
    void Renderer::Draw(const VertexArray &_va, const IndexBuffer &_ib, const Shader &_shader) const
    {
        _va.Bind();
        _ib.Bind();
        glDrawElements(GL_TRIANGLES, _ib.GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}