#include "Circle.h"
namespace GraphicsEngine {
    Circle::Circle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius) {
        m_Type = T_Circle;

        m_Dem = 3;

        unsigned int numberOfSides = 128;

        m_CountVert = numberOfSides + 1;
        GLint fNumVer = m_CountVert + 1;

        GLfloat doublePi = 2.0f * M_PI;

        GLfloat *circleVerticesX = new GLfloat[fNumVer];
        GLfloat *circleVerticesY = new GLfloat[fNumVer];
        GLfloat *circleVerticesZ = new GLfloat[fNumVer];

        circleVerticesX[0] = x;
        circleVerticesY[0] = y;
        circleVerticesZ[0] = 0;

        for (int i = 1; i < fNumVer - 1; i++) {
            circleVerticesX[i] = x + (radius * cos((i + 1) * doublePi / numberOfSides));
            circleVerticesY[i] = y + (radius * sin((i + 1) * doublePi / numberOfSides));
            circleVerticesZ[i] = 0;
        }

        m_VertexBufferData = new GLfloat[fNumVer * 3];

        for (int i = 0; i < fNumVer; i++) {
            m_VertexBufferData[i * 3] = circleVerticesX[i];
            m_VertexBufferData[(i * 3) + 1] = circleVerticesY[i];
            m_VertexBufferData[(i * 3) + 2] = circleVerticesZ[i];
        }

        m_Indeces = new GLuint[numberOfSides * 3]{0};

        for (int i = 1; i < numberOfSides; i++) {
            m_Indeces[i * 3 - 3] = 0;
            m_Indeces[i * 3 + 1 - 3] = i;
            m_Indeces[i * 3 + 2 - 3] = i + 1;
        }

        m_Indeces[(numberOfSides - 1) * 3] = 0;
        m_Indeces[(numberOfSides - 1) * 3 + 1] = numberOfSides;
        m_Indeces[(numberOfSides - 1) * 3 + 2] = 1;

        m_CountInd = numberOfSides * 3;
    }
}