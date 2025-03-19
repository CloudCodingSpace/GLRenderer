@type vertex
#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;

uniform mat4 proj;
uniform mat4 model;
uniform mat4 view;

out vec3 oColor;

void main() {
	gl_Position = proj * view * model * vec4(pos, 1.0);
	oColor = color;
}

@type fragment
#version 330 core

out vec4 FragColor;

in vec3 oColor;

uniform sampler2D tex;

void main() {
	FragColor = vec4(oColor, 1.0);

	FragColor.rgb = pow(FragColor.rgb, vec3(1.0/2.0)); // Gamma correction (To sRGB space)
}