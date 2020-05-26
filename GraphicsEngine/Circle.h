#pragma once

#define _USE_MATH_DEFINES 

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cmath>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Renderer.h"

#include "Point.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "ViewObject.h"

namespace GraphicsEngine {
    class Circle : public ViewObject {
    public:
        Circle(GLfloat, GLfloat, GLfloat, GLfloat);
    };
}
