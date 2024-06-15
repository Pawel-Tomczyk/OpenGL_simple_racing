#version 330

in vec4 vertex;
in vec2 texCoord;
in vec4 normal;

out vec4 vCol;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 M;
uniform mat4 P;
uniform mat4 V;

void main()
{
	Normal = mat3(transpose(inverse(M))) * normal.xyz; // zmiany na macierzy s� �eby oboj�tnie jak si� obr�ci/zeskaluje obiekt, ca�y czas noralne mia�y sens
	
	TexCoord = texCoord;
	
	gl_Position = P * V * M * vertex;
	
	vCol = clamp(vertex, 0.0f, 1.0f);
	
	FragPos = (M * vertex).xyz;
}