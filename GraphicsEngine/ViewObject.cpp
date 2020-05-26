#include "ViewObject.h"
#include <filesystem>
#include <iostream>

#include <unistd.h>

namespace GraphicsEngine {
    ViewObject::ViewObject() {
        m_Shader = new Shader("../GraphicsEngine/Basic.shader");

        m_Color = new float[3]{1.0, 1.0, 1.0};

        m_MVP = glm::mat4(1.0f);
        m_Position = glm::vec3(1.f, 1.f, 1.f);
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

    void ViewObject::setCurrentPosition(glm::vec3 vec) {
        setTranslation(-m_Position);
        m_Position = vec;
        setTranslation(m_Position);
    }

    void ViewObject::setCurrentRotation(float angle, glm::vec3 vec) {
        setRotation(-m_CurAngle, m_CurRot);
        m_CurAngle = angle;
        m_CurRot = vec;
        setRotation(m_CurAngle, m_CurRot);
    }

    void ViewObject::setRotation(float angle, glm::vec3 vec) {
        m_MVP = glm::rotate(m_MVP, glm::radians(angle), vec);
        // m_MVP = glm::rotate(m_MVP, glm::radians(angle), vec_2);
    }

    void ViewObject::setRotation(float angle, glm::vec3 vec_1, glm::vec3 vec_2) {
        m_MVP = glm::rotate(m_MVP, glm::radians(angle), vec_2 - vec_1);
        // m_MVP = glm::rotate(m_MVP, glm::radians(angle), vec_2);
    }

    void ViewObject::setTranslation(glm::vec3 vec) {
        m_MVP = glm::translate(m_MVP, vec);
    }

    void ViewObject::setScale(glm::vec3 vec) {
        m_MVP = glm::scale(m_MVP, vec);
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
        //m_Shader->SetUniformVec3f("u_Tr", glm::vec3(0.2f, 0.3f, 0.0f));
        renderer.Draw(*m_VA, *m_IB, *m_Shader);
        m_Shader->Unbind();
    }
}