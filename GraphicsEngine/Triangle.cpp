#include "Triangle.h"

#include <iostream>

namespace GraphicsEngine
{
    Triangle::Triangle(float _x, float _y, GLfloat _vp[])
    {
        m_Type = T_Triangle;

        m_Dem = 3;
        m_CountVert = 3;
        m_CountInd = 3;

        m_Indeces = new unsigned int[3]{0, 1, 2};

        m_Position = glm::vec3(_x, _y, 0.f);
        m_VertexBufferData = _vp;

        for(int i = 0; i < 9; i++)
        {
            std::cout << m_VertexBufferData[i] << " ";
        }
        
        m_MVP = glm::translate(m_MVP, m_Position);
    }
}
