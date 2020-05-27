#include "ViewObject.h"
#include <iostream>

#include <unistd.h>

namespace GraphicsEngine {
    ViewObject::ViewObject() {
        m_Shader = new Shader("../GraphicsEngine/Basic.shader");

        m_Color = new float[3]{1.0, 1.0, 1.0};

	m_MVP = glm::mat4(1.0f);
	m_MVP = glm::ortho(0.f, 640.f, 0.f, 480.f, 0.f, 100.f);
	m_Position = glm::vec3(1.f, 1.f, 1.f);
	m_Scale = glm::vec3(1.f, 1.f, 1.f);
	m_Angle = 0;
    }

    int ViewObject::getID() {
        return m_ID;
    }

    void ViewObject::setID(int _id) {
        m_ID = _id;
    }

    void ViewObject::setColor(float _c[]) {
        delete m_Color;
        m_Color = _c;
    }

    void ViewObject::setShader(Shader &_shader) {
        m_Shader = &_shader;
        m_Shader->Unbind();
    }

    void ViewObject::setMVP(glm::mat4 mat) {
        m_MVP = mat;
    }

    void ViewObject::setRotation(float angle, glm::vec3 vec) {
        m_Angle = angle;
        m_MVP = glm::mat4(1.0f);
        m_MVP = glm::ortho(0.f, 640.f, 0.f, 480.f, 0.f, 100.f);
        m_MVP = glm::translate(m_MVP, m_Position);
        m_MVP = glm::scale(m_MVP, m_Scale);
        m_MVP = glm::rotate(m_MVP, glm::radians(angle), vec);
    }

    void ViewObject::setPosition(glm::vec3 vec)
    {
        m_Position = vec;
        m_MVP = glm::mat4(1.0f);
        m_MVP = glm::ortho(0.f, 640.f, 0.f, 480.f, 0.f, 100.f);
        m_MVP = glm::translate(m_MVP, vec);
        m_MVP = glm::scale(m_MVP, m_Scale);
        m_MVP = glm::rotate(m_MVP, glm::radians(m_Angle), glm::vec3(0.f, 0.f, 1.f));
    }

    void ViewObject::setScale(glm::vec3 vec)
    {
        m_Scale = vec;
        m_MVP = glm::mat4(1.0f);
        m_MVP = glm::ortho(0.f, 640.f, 0.f, 480.f, 0.f, 100.f);
        m_MVP = glm::translate(m_MVP, m_Position);
        m_MVP = glm::scale(m_MVP, vec);
        m_MVP = glm::rotate(m_MVP, glm::radians(m_Angle), glm::vec3(0.f, 0.f, 1.f));
    }
    

    bool ViewObject::zip() {
        m_VA = new VertexArray;
        m_VB = new VertexBuffer(m_VertexBufferData, sizeof(float) * m_CountVert * m_Dem);

        m_Layout = new VertexBufferLayout();
        m_Layout->Push(GL_FLOAT, m_Dem);
        m_VA->AddBuffer(*m_VB, *m_Layout);

        //m_IB = new IndexBuffer(m_Indeces, (m_CountVert - 1) * 3);
        m_IB = new IndexBuffer(m_Indeces, m_CountInd);

        return true;
    }

    void ViewObject::draw() {
        if (!zip())
            return;

        Renderer renderer;

        m_Shader->Bind();

        m_Shader->SetUniformMat4f("u_MVP", m_MVP);
        m_Shader->SetUniform4f("u_Color", m_Color[0], m_Color[1], m_Color[2], 1.0f);
        renderer.Draw(*m_VA, *m_IB, *m_Shader);
        m_Shader->Unbind();
    }
}
