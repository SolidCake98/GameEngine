#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Renderer.h"
#include "Point.h"

#include "Types.h"

class ViewObject
{
protected:
	int m_ID;

	Types m_Type;
	glm::vec3 m_Position;

	unsigned int m_Dem;
	unsigned int m_CountVert;
	unsigned int m_CountInd;


	GLfloat* m_VertexBufferData;
	unsigned int* m_Indeces;

	VertexArray* m_VA;
	VertexBuffer* m_VB;
	IndexBuffer* m_IB;
	VertexBufferLayout* m_Layout;

	Shader* m_Shader;
	float* m_Color;

	glm::mat4 m_MVP;

	bool zip();

public:
	ViewObject();

	int getID();
	void setID(int);

	void setColor(float[]);
	void setShader(Shader&);

	void setMVP(glm::mat4);

	void setCurrentPosition(glm::vec3);
	void setRotation(float, glm::vec3, glm::vec3);
	void setTranslation(glm::vec3);
	void setScale(glm::vec3);
	
	void draw();

};

