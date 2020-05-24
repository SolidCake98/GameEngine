#shader vertex
#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 u_MVP;
uniform vec3 u_Tr;

void main()
{
   gl_Position = u_MVP * vec4(vertexPosition_modelspace, 1);
   gl_Position.xyz += u_Tr;
};

#shader fragment
#version 330 core

out vec4 color;

uniform vec4 u_Color;

void main()
{
   color = u_Color;
};