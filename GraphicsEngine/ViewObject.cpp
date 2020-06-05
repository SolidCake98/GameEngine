#include "ViewObject.h"
#include <iostream>

#include <unistd.h>

namespace GraphicsEngine
{
    ViewObject::ViewObject()
    {
        m_Shader = new Shader("../GraphicsEngine/Basic.shader");

        m_Color = new float[3]{1.0, 1.0, 1.0};

        m_MVP = glm::mat4(1.0f);
        m_Position = glm::vec3(1.f, 1.f, 1.f);
        m_Scale = glm::vec3(1.f, 1.f, 1.f);
        m_VecRot = glm::vec3(0.f,0.f,1.f);
        m_Angle = 0;
    }

    void ViewObject::setColor(float _c[])
    {
        delete m_Color;
        m_Color = _c;
    }

    void ViewObject::setShader(Shader &_shader)
    {
        m_Shader = &_shader;
        m_Shader->Unbind();
    }

    void ViewObject::setMVP(glm::mat4 _mat)
    {
        m_MVP = _mat;
    }

    void ViewObject::setScreenPosition(int _w, int _h)
    {
        m_MVP = glm::mat4(1.0f);
        m_MVP = glm::ortho(0.f, (float)_w, (float)_h, 0.f, 0.f, 100.f);
        m_MVP = glm::translate(m_MVP, m_Position);
        m_MVP = glm::scale(m_MVP, m_Scale);
        m_MVP = glm::rotate(m_MVP, glm::radians(m_Angle), m_VecRot);
    }

    void ViewObject::setRotation(float _angle, glm::vec3 _vec)
    {
        m_Angle = _angle;
        m_VecRot = _vec;
    }

    void ViewObject::setPosition(glm::vec3 _vec)
    {
        m_Position = _vec;
    }

    void ViewObject::setScale(glm::vec3 _vec)
    {
        m_Scale = _vec;
    }

    void ViewObject::zip()
    {
        m_VA = new VertexArray;
        m_VB = new VertexBuffer(m_VertexBufferData, sizeof(float) * m_CountVert * m_Dem);

        m_Layout = new VertexBufferLayout();
        m_Layout->Push(GL_FLOAT, m_Dem);
        m_VA->AddBuffer(*m_VB, *m_Layout);

        m_IB = new IndexBuffer(m_Indeces, m_CountInd);
    }

    void ViewObject::draw()
    {
        zip();

        Renderer renderer;

        m_Shader->Bind();

        m_Shader->SetUniformMat4f("u_MVP", m_MVP);
        m_Shader->SetUniform4f("u_Color", m_Color[0], m_Color[1], m_Color[2], 1.0f);
        renderer.Draw(*m_VA, *m_IB, *m_Shader);
        m_Shader->Unbind();
    }

    ViewObject::~ViewObject()
    {
        delete m_VertexBufferData;
        delete m_Indeces;
        delete m_Color;
        delete m_VA;
        delete m_VB;
        delete m_IB;
        delete m_Layout;
    }
}
