#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Renderer.h"

#include "ViewObject.h"

#include "Point.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace GraphicsEngine {
    class Rectangle : public ViewObject {
    public:
        Rectangle(float, float, GLfloat[]);
    };
}

