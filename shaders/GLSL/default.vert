#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

layout (location = 0) out vec3 frag_color;

layout(push_constant) uniform Push 
{
    mat4 mat;
    mat4 transform;
} push_constant_data;

void main()
{
    gl_Position = push_constant_data.mat * push_constant_data.transform * vec4(position, 1.0);
    frag_color = color;
}