@type vertex
#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texcoords;
layout (location = 2) in vec3 normal;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

out vec2 texCoords;
out vec3 Normal;

void main() {
	gl_Position = proj * view * model * vec4(pos, 1.0);
	texCoords = texcoords;
	Normal = normal;
}

@type fragment
#version 330 core

out vec4 FragColor;

in vec2 texCoords;
in vec3 Normal;

uniform sampler2D tex;

void main() {
	FragColor = texture(tex, texCoords);
	FragColor.rgb = pow(FragColor.rgb, vec3(1.0/2.2));
}