#include "Triangle.h"

namespace GraphicsEngine {
    Triangle::Triangle(float x, float y, GLfloat _vp[]) {
        m_Type = T_Triangle;

        m_Dem = 3;
        m_CountVert = 3;
        m_CountInd = 3;

        m_Indeces = new unsigned int[3]{0, 1, 2};

        m_Position = glm::vec3(x, y, 0.f);
        m_VertexBufferData = _vp;
    }
}