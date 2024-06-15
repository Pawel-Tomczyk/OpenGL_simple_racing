/*
Niniejszy program jest wolnym oprogramowaniem; możesz go
rozprowadzać dalej i / lub modyfikować na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundację Wolnego
Oprogramowania - według wersji 2 tej Licencji lub(według twojego
wyboru) którejś z późniejszych wersji.

Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on
użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej
gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH
ZASTOSOWAŃ.W celu uzyskania bliższych informacji sięgnij do
Powszechnej Licencji Publicznej GNU.

Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz
Powszechnej Licencji Publicznej GNU(GNU General Public License);
jeśli nie - napisz do Free Software Foundation, Inc., 59 Temple
Place, Fifth Floor, Boston, MA  02110 - 1301  USA
*/

#include "shaderprogram.h"


//Procedura wczytuje plik do tablicy znaków.
char* ShaderProgram::readFile(const char* fileName) {
	int filesize;
	FILE *plik;
	char* result;

	#pragma warning(suppress : 4996) //Wyłączenie błędu w Visual Studio wynikające z nietrzymania się standardów przez Microsoft.
	plik=fopen(fileName,"rb");
	if (plik != NULL) {
		fseek(plik, 0, SEEK_END);
		filesize = ftell(plik);
		fseek(plik, 0, SEEK_SET);
		result = new char[filesize + 1];
		#pragma warning(suppress : 6386) //Wyłączenie błędu w Visual Studio wynikającego z błędnej analizy statycznej kodu.
		int readsize=fread(result, 1, filesize, plik);
		result[filesize] = 0;
		fclose(plik);

		return result;
	}

	return NULL;

}

//Metoda wczytuje i kompiluje shader, a następnie zwraca jego uchwyt
GLuint ShaderProgram::loadShader(GLenum shaderType,const char* fileName) {
	//Wygeneruj uchwyt na shader
	GLuint shader=glCreateShader(shaderType);//shaderType to GL_VERTEX_SHADER, GL_GEOMETRY_SHADER lub GL_FRAGMENT_SHADER
	//Wczytaj plik ze źródłem shadera do tablicy znaków
	const GLchar* shaderSource=readFile(fileName);
	//Powiąż źródło z uchwytem shadera
	glShaderSource(shader,1,&shaderSource,NULL);
	//Skompiluj źródło
	glCompileShader(shader);
	//Usuń źródło shadera z pamięci (nie będzie już potrzebne)
	delete []shaderSource;

	//Pobierz log błędów kompilacji i wyświetl
	int infologLength = 0;
	int charsWritten  = 0;
	char *infoLog;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH,&infologLength);

	if (infologLength > 1) {
		infoLog = new char[infologLength];
		glGetShaderInfoLog(shader, infologLength, &charsWritten, infoLog);
		printf("%s\n",infoLog);
		delete []infoLog;
	}

	//Zwróć uchwyt wygenerowanego shadera
	return shader;
}

ShaderProgram::ShaderProgram(const char* vertexShaderFile,const char* geometryShaderFile,const char* fragmentShaderFile) {
	//Wczytaj vertex shader
	printf("Loading vertex shader...\n");
	vertexShader=loadShader(GL_VERTEX_SHADER,vertexShaderFile);

	//Wczytaj geometry shader
	if (geometryShaderFile!=NULL) {
		printf("Loading geometry shader...\n");
		geometryShader=loadShader(GL_GEOMETRY_SHADER,geometryShaderFile);
	} else {
		geometryShader=0;
	}

	//Wczytaj fragment shader
	printf("Loading fragment shader...\n");
	fragmentShader=loadShader(GL_FRAGMENT_SHADER,fragmentShaderFile);

	//Wygeneruj uchwyt programu cieniującego
	shaderProgram=glCreateProgram();

	//Podłącz do niego shadery i zlinkuj program
	glAttachShader(shaderProgram,vertexShader);
	glAttachShader(shaderProgram,fragmentShader);
	if (geometryShaderFile!=NULL) glAttachShader(shaderProgram,geometryShader);
	glLinkProgram(shaderProgram);

	//Pobierz log błędów linkowania i wyświetl
	int infologLength = 0;
	int charsWritten  = 0;
	char *infoLog;

	glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH,&infologLength);

	if (infologLength > 1)
	{
		infoLog = new char[infologLength];
		glGetProgramInfoLog(shaderProgram, infologLength, &charsWritten, infoLog);
		printf("%s\n",infoLog);
		delete []infoLog;
	}

	printf("Shader program created \n");
}

ShaderProgram::~ShaderProgram() {
	//Odłącz shadery od programu
	glDetachShader(shaderProgram, vertexShader);
	if (geometryShader!=0) glDetachShader(shaderProgram, geometryShader);
	glDetachShader(shaderProgram, fragmentShader);

	//Wykasuj shadery
	glDeleteShader(vertexShader);
	if (geometryShader!=0) glDeleteShader(geometryShader);
	glDeleteShader(fragmentShader);

	//Wykasuj program
	glDeleteProgram(shaderProgram);
}


//Włącz używanie programu cieniującego reprezentowanego przez aktualny obiekt
void ShaderProgram::use() {
	glUseProgram(shaderProgram);
}

//Pobierz numer slotu odpowiadającego zmiennej jednorodnej o nazwie variableName
GLuint ShaderProgram::u(const char* variableName) {
	return glGetUniformLocation(shaderProgram,variableName);
}

//Pobierz numer slotu odpowiadającego atrybutowi o nazwie variableName
GLuint ShaderProgram::a(const char* variableName) {
	return glGetAttribLocation(shaderProgram,variableName);
}

//void ShaderProgram::useBasicLight(Light* light)
//{
//	light->useLight(u("light.color"), u("light.ambientIntensity"), u("light.diffuseIntensity"));
//
//}

void ShaderProgram::useDirectionalLight(DirectionalLight* light[], int lightCount)
{
	if(lightCount > maxDirectionalLightCount) 
	{
		printf("Zbyt dużo świateł kierunkowych, rozważ zmianę pliku constans\n");
		return;
	}
	
	glUniform1i(u("directionalLightCount"), lightCount);

	for (int i = 0; i < lightCount; i++) {
		std::string name = "directionalLights[" + std::to_string(i) + "].base.color";
		const char color = u(name.c_str());

		name = "directionalLights[" + std::to_string(i) + "].base.ambientIntensity";
		const char intensity = u(name.c_str());


		name = "directionalLights[" + std::to_string(i) + "].base.diffuseIntensity";
		const char diffuse = u(name.c_str());


		name = "directionalLights[" + std::to_string(i) + "].direction";
		const char direction = u(name.c_str());

		light[i]->useLight(color, intensity, diffuse, direction);
	}
}

void ShaderProgram::usePointLight(PointLight* light[], int lightCount)
{
	if (lightCount > maxPointLightCount)
	{
		printf("Zbyt dużo świateł kierunkowych, rozważ zmianę pliku constans\n");
		return;
	}

	glUniform1i(u("pointLightCount"), lightCount);

	for (int i = 0; i < lightCount; i++) {
		std::string name = "pointLights[" + std::to_string(i) + "].base.color";
		const char color = u(name.c_str());

		name = "pointLights[" + std::to_string(i) + "].base.ambientIntensity";
		const char intensity = u(name.c_str());


		name = "pointLights[" + std::to_string(i) + "].base.diffuseIntensity";
		const char diffuse = u(name.c_str());


		name = "pointLights[" + std::to_string(i) + "].position";
		const char posicion = u(name.c_str());

		name = "pointLights[" + std::to_string(i) + "].constant";
		const char constant = u(name.c_str());

		name = "pointLights[" + std::to_string(i) + "].linear";
		const char linear = u(name.c_str());

		name = "pointLights[" + std::to_string(i) + "].exponent";
		const char exponent = u(name.c_str());

		light[i]->useLight(color, intensity, diffuse, posicion, constant, linear, exponent);
	}
}

void ShaderProgram::useSpotLight(SpotLight* light[], int lightCount)
{
	if (lightCount > maxPointLightCount)
	{
		printf("Zbyt dużo reflektorów, rozważ zmianę pliku constans\n");
		return;
	}

	glUniform1i(u("spotLightCount"), lightCount);

	for (int i = 0; i < lightCount; i++) {
		std::string name = "spotLights[" + std::to_string(i) + "].base.base.color";
		const char color = u(name.c_str());

		name = "spotLights[" + std::to_string(i) + "].base.base.ambientIntensity";
		const char intensity = u(name.c_str());

		name = "spotLights[" + std::to_string(i) + "].base.base.diffuseIntensity";
		const char diffuse = u(name.c_str());

		name = "spotLights[" + std::to_string(i) + "].base.position";
		const char position = u(name.c_str());

		name = "spotLights[" + std::to_string(i) + "].base.constant";
		const char constant = u(name.c_str());

		name = "spotLights[" + std::to_string(i) + "].base.linear";
		const char linear = u(name.c_str());

		name = "spotLights[" + std::to_string(i) + "].base.exponent";
		const char exponent = u(name.c_str());

		name = "spotLights[" + std::to_string(i) + "].direction";
		const char direction = u(name.c_str());

		name = "spotLights[" + std::to_string(i) + "].edge";
		const char edge = u(name.c_str());

		light[i]->useLight(color, intensity, diffuse, position, constant, linear, exponent, direction, edge);
	}
}

void ShaderProgram::useMaterial(Material* material)
{
	material->useMaterial(u("material.specularIntensity"), u("material.shininess"));
}
