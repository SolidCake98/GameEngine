#include "Rectangle.h"

namespace GraphicsEngine {
    Rectangle::Rectangle(float x, float y, GLfloat _vp[]) {
        m_Type = T_Rectangle;

        m_Position = glm::vec3(x, y, 0);

        m_Dem = 3;

        m_VertexBufferData = _vp;
        m_CountVert = 4;
        m_CountInd = 6;

        m_Indeces = new unsigned int[m_CountInd]{0, 1, 3,
                                                 1, 3, 2};
    }
}