#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 Color;
uniform mat4 trans;
uniform mat4 projection;
uniform mat4 view;
void main()
{
  gl_Position = projection * view * trans * vec4(aPos, 1.0);
  Color = aColor;
}