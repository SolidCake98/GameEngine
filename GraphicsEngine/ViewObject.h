#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Renderer.h"
#include "Point.h"

#include "Types.h"

namespace GraphicsEngine {
    class ViewObject {
    protected:
        int m_ID;

        Types m_Type;
        glm::vec3 m_Position;
        glm::vec3 m_Scale;
        float m_Angle;

        unsigned int m_Dem;
        unsigned int m_CountVert;
        unsigned int m_CountInd;


        GLfloat *m_VertexBufferData;
        unsigned int *m_Indeces;

        VertexArray *m_VA;
        VertexBuffer *m_VB;
        IndexBuffer *m_IB;
        VertexBufferLayout *m_Layout;

        Shader *m_Shader;
        float *m_Color;

        glm::mat4 m_MVP;

        void zip();

    public:
        ViewObject();
        ~ViewObject();

        int getID();

        void setID(int);

        void setColor(float[]);

        void setShader(Shader &);

        void setMVP(glm::mat4);

        void setScreenPosition(int, int);

        void setRotation(float, glm::vec3);

        void setPosition(glm::vec3);

        void setScale(glm::vec3);

        void draw();

    };
}
