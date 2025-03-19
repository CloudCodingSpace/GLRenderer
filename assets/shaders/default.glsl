@type vertex
#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

out vec2 oTexCoord;

void main() {
	gl_Position = proj * view * model * vec4(pos, 1.0);
	oTexCoord = texCoord;
}

@type fragment
#version 330 core

out vec4 FragColor;

in vec2 oTexCoord;

uniform sampler2D tex;

void main() {
	FragColor = texture(tex, oTexCoord);
}