#pragma once

#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <iostream>

#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"


class Renderer
{
public:
	void Draw(const VertexArray&, const IndexBuffer&, const Shader&) const;
};