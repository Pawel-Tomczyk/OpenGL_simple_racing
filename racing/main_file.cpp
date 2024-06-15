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

#define GLM_FORCE_RADIANS
#define GLM_FORCE_SWIZZLE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"
#include "lodepng.h"
#include "shaderprogram.h"
#include "myCube.h"
#include "myTeapot.h"
#include "MyWuz.h"

#include "Object.h"
#include "Pojazd.h"
#include "Wrog.h"
#include "Colision.h"

#include "Camera.h"
#include "Light.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

#include "Material.h"

float aspectRatio=1;

ShaderProgram *sp;

Pojazd* pojazd;
Wrog* wrog[3];
Object* obj[20];

Camera camera(glm::vec3(0.0f, 0.0f, -4.0f), glm::vec3(0.0f, 1.0f, 0.0f), 90.0f, 0.0f, 5.0f, 1.0f);
bool keys[1024];

DirectionalLight* directionalLight[1];
PointLight* pointLight[12];
SpotLight* spotLight[4];

Material* material;

glm::vec2 points[20];

//Odkomentuj, żeby rysować kostkę
float* vertices = myCubeVertices;
float* normals = myCubeNormals;
float* texCoords = myCubeTexCoords;
float* colors = myCubeColors;
int vertexCount = myCubeVertexCount;

float verticesFloor[] = {
	-1000.0f, 0.0f, -1000.0f, 1.0f,
	1000.0f, 0.0f, -1000.0f, 1.0f,
	-1000.0f, 0.0f, 1000.0f, 1.0f,

	-1000.0f, 0.0f, 1000.0f, 1.0f,
	1000.0f, 0.0f, -1000.0f, 1.0f,
	1000.0f, 0.0f, 1000.0f, 1.0f,
};

float normalsFloor[] = {
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
};

float texCoordsFloor[] = {
	0.0f, 0.0f,
	100.0f, 0.0f,
	0.0f, 100.0f,

	0.0f, 100.0f,
	100.0f, 0.0f,
	100.0f, 100.0f
};

int vertexCountFloor = 6;

GLuint tex0;
GLuint tex1;
GLuint tex2;
GLuint tex3;

//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}


void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mods) {
	if (action == GLFW_PRESS) {
		keys[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		keys[key] = false;
	}
}




void windowResizeCallback(GLFWwindow* window,int width,int height) {
    if (height==0) return;
    aspectRatio=(float)width/(float)height;
    glViewport(0,0,width,height);
}


GLuint readTexture(const char* filename) {
    GLuint tex;
    glActiveTexture(GL_TEXTURE0);

    //Wczytanie do pamięci komputera
    std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
    unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
    //Wczytaj obrazek
    unsigned error = lodepng::decode(image, width, height, filename);

    //Import do pamięci karty graficznej
    glGenTextures(1, &tex); //Zainicjuj jeden uchwyt
    glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
    //Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return tex;
}

int ilos = 0;
void map() {
	// punkt 200, 0
	glm::mat4 M = glm::mat4(1.0f);
	//a
	M = glm::translate(M, glm::vec3(10.f, 0.f, 0.f));
	obj[0] = new Object(glm::scale(M, glm::vec3(1.0f, 1.0f, 200.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(1.0f, 200.0f));
	ilos++;

	//b
	M = glm::translate(M, glm::vec3(-20.f, 0.f, 0.f));
	obj[1] = new Object(glm::scale(M, glm::vec3(1.0f, 1.0f, 180.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(1.0f, 180.0f));
	ilos++;
	//c
	M = glm::translate(M, glm::vec3(-20.f, 0.f, 180.f));
	obj[2] = new Object(glm::scale(M, glm::vec3(20.0f, 1.0f, 1.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(20.0f, 1.0f));
	ilos++;
	//d
	M = glm::translate(M, glm::vec3(0.f, 0.f, 20.f));
	obj[3] = new Object(glm::scale(M, glm::vec3(40.0f, 1.0f, 1.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(40.0f, 1.0f));
	ilos++;


	//e
	M = glm::translate(M, glm::vec3(-40.f, 0.f, -30.f));
	obj[4] = new Object(glm::scale(M, glm::vec3(1.0f, 1.0f, 30.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(1.0f, 30.0f));
	ilos++;


	//f
	M = glm::translate(M, glm::vec3(20.f, 0.f, -20.f));
	obj[5] = new Object(glm::scale(M, glm::vec3(1.0f, 1.0f, 30.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(1.0f, 30.0f));
	ilos++;
	//g
	M = glm::translate(M, glm::vec3(-40.f, 0.f, -10.f));
	obj[6] = new Object(glm::scale(M, glm::vec3(20.0f, 1.0f, 1.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(20.0f, 1.0f));
	ilos++;
	//h
	M = glm::translate(M, glm::vec3(0.f, 0.f, -20.f));
	obj[7] = new Object(glm::scale(M, glm::vec3(40.0f, 1.0f, 1.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(40.0f, 1.0f));
	ilos++;
	//i
	M = glm::translate(M, glm::vec3(-20.f, 0.f, 35.f));
	obj[8] = new Object(glm::scale(M, glm::vec3(1.0f, 1.0f, 15.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(1.0f, 15.0f));
	ilos++;
	//j
	M = glm::translate(M, glm::vec3(-20.f, 0.f, -20.f));
	obj[9] = new Object(glm::scale(M, glm::vec3(1.0f, 1.0f, 25.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(1.0f, 25.0f));
	ilos++;
	//k
	M = glm::translate(M, glm::vec3(0.f, 0.f, 35.f));
	obj[10] = new Object(glm::scale(M, glm::vec3(20.0f, 1.0f, 1.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(20.0f, 1.0f));
	ilos++;
	//l
	M = glm::translate(M, glm::vec3(-20.f, 0.f, -35.f));
	obj[11] = new Object(glm::scale(M, glm::vec3(1.0f, 1.0f, 35.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(1.0f, 35.0f));
	ilos++;
	//m
	M = glm::translate(M, glm::vec3(60.f, 0.f, -35.f));
	obj[12] = new Object(glm::scale(M, glm::vec3(60.0f, 1.0f, 1.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(60.0f, 1.0f));
	ilos++;
	//n
	M = glm::translate(M, glm::vec3(20.f, 0.f, 10.f));
	obj[13] = new Object(glm::scale(M, glm::vec3(60.0f, 1.0f, 1.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(60.0f, 1.0f));
	ilos++;
	//o
	M = glm::translate(M, glm::vec3(40.f, 0.f, -160.f));
	obj[14] = new Object(glm::scale(M, glm::vec3(1.0f, 1.0f, 150.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(1.0f, 150.0f));
	ilos++;
	//p
	M = glm::translate(M, glm::vec3(20.f, 0.f, -150.f));
	obj[15] = new Object(glm::scale(M, glm::vec3(20.0f, 1.0f, 1.0f)), vertices, vertexCount, normals, texCoords, glm::vec2(20.0f, 1.0f));
	ilos++;

}

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
	//************Tutaj umieszczaj kod, który należy wykonać raz, na początku programu************
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glfwSetWindowSizeCallback(window,windowResizeCallback);
	glfwSetKeyCallback(window,keyCallback);

	sp=new ShaderProgram("v_simplest.glsl",NULL,"f_simplest.glsl");
	tex0 = readTexture("metal.png");
	tex1 = readTexture("metal_spec.png");
	tex2 = readTexture("mcqueen.png");
	tex3 = readTexture("marucha.png");

	for(int i = 0;i<1024;i++) keys[i]=false;

	directionalLight[0] = new DirectionalLight(glm::vec3(1.0f, 1.0f, 0.6f), 0.1f, 0.2f, glm::vec3(0.0f, 0.4f, 0.8f));

	
	// UWAGA, nie ma jeszcze cieniowania, więc na ziemie też leci światło przez kostke

	material = new Material(1.0f, 16.0f); 	

	map();
	glm::mat4 M = glm::mat4(1.0f);
	M = glm::translate(M, glm::vec3(0.0f, -1.f, -10.0f));
	pojazd = new Pojazd(glm::scale(M, glm::vec3(2.0f, 2.0f, 2.0f)), myWuzVertices, myWuzVertexCount, myWuzNormals, myWuzTexCoords, glm::vec2(1.0f, 1.0f));
	spotLight[0] = new SpotLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, 1.0f, glm::vec3(M[3][0] + 1.0, 1.0f, M[3][2]), 0.01f, 0.01f, 0.005f, glm::vec3(0.0f, 0.0f, 1.0f), 20.0f);
	spotLight[1] = new SpotLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, 1.0f, glm::vec3(M[3][0] + 1.0, 1.0f, M[3][2]), 0.01f, 0.01f, 0.005f, glm::vec3(0.0f, 0.0f, 1.0f), 20.0f);
	spotLight[2] = new SpotLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, 1.0f, glm::vec3(M[3][0] - 1.0, 1.0f, M[3][2]), 0.01f, 0.01f, 0.005f, glm::vec3(0.0f, 0.0f, 1.0f), 20.0f);
	spotLight[3] = new SpotLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, 1.0f, glm::vec3(M[3][0] - 1.0, 1.0f, M[3][2]), 0.01f, 0.01f, 0.005f, glm::vec3(0.0f, 0.0f, 1.0f), 20.0f);

	M = glm::mat4(1.0f);
	M = glm::translate(M, glm::vec3(0.0f, -1.f, 0.0f));
	wrog[0] = new Wrog(M, myWuzVertices, myWuzVertexCount, myWuzNormals, myWuzTexCoords, glm::vec2(1.0f, 1.0f));
	M = glm::translate(M, glm::vec3(0.0f, 0.f, -10.0f));
	wrog[1] = new Wrog(M, myWuzVertices, myWuzVertexCount, myWuzNormals, myWuzTexCoords, glm::vec2(1.0f, 1.0f));
	M = glm::translate(M, glm::vec3(0.0f, 0.f, -10.0f));
	wrog[2] = new Wrog(M, myWuzVertices, myWuzVertexCount, myWuzNormals, myWuzTexCoords, glm::vec2(1.0f, 1.0f));

	points[0] = glm::vec2(0.0f, 0.0f);
	points[1] = glm::vec2(0.0f, 100.0f);
	points[2] = glm::vec2(0.0f, 190.f);
	points[3] = glm::vec2(-60.f, 190.f);
	points[4] = glm::vec2(-60.f, 135.f);
	points[5] = glm::vec2(-120.f, 135.f);
	points[6] = glm::vec2(-120.f, 165.f);
	points[7] = glm::vec2(-140.f, 165.f);
	points[8] = glm::vec2(-140.f, 105.f);
	points[9] = glm::vec2(-20.f, 105.f);
	points[10] = glm::vec2(-20.f, -195.f);
	points[11] = glm::vec2(0.0f, -195.0f);

 	pointLight[0] = new PointLight(glm::vec3(1.0f, 0.0f, 0.1f), 0.0f, 0.7f, glm::vec3(points[0].x, 8.0f, points[0].y), 0.1f, 0.1f, 0.01f);
	pointLight[1] = new PointLight(glm::vec3(1.0f, 0.0f, 0.2f), 0.0f, 0.7f, glm::vec3(points[1].x, 8.0f, points[1].y), 0.1f, 0.1f, 0.01f);
	pointLight[2] = new PointLight(glm::vec3(1.0f, 0.0f, 0.1f), 0.0f, 0.7f, glm::vec3(points[2].x, 8.0f, points[2].y), 0.1f, 0.1f, 0.01f);
	pointLight[3] = new PointLight(glm::vec3(1.0f, 0.0f, 0.2f), 0.0f, 0.7f, glm::vec3(points[3].x, 8.0f, points[3].y), 0.1f, 0.1f, 0.01f);
	pointLight[4] = new PointLight(glm::vec3(1.0f, 0.0f, 0.1f), 0.0f, 0.7f, glm::vec3(points[4].x, 8.0f, points[4].y), 0.1f, 0.1f, 0.01f);
	pointLight[5] = new PointLight(glm::vec3(1.0f, 0.0f, 0.2f), 0.0f, 0.7f, glm::vec3(points[5].x, 8.0f, points[5].y), 0.1f, 0.1f, 0.01f);
	pointLight[6] = new PointLight(glm::vec3(1.0f, 0.0f, 0.1f), 0.0f, 0.7f, glm::vec3(points[6].x, 8.0f, points[6].y), 0.1f, 0.1f, 0.01f);
	pointLight[7] = new PointLight(glm::vec3(1.0f, 0.0f, 0.2f), 0.0f, 0.7f, glm::vec3(points[7].x, 8.0f, points[7].y), 0.1f, 0.1f, 0.01f);
	pointLight[8] = new PointLight(glm::vec3(1.0f, 0.0f, 0.1f), 0.0f, 0.7f, glm::vec3(points[8].x, 8.0f, points[8].y), 0.1f, 0.1f, 0.01f);
	pointLight[9] = new PointLight(glm::vec3(1.0f, 0.0f, 0.2f), 0.0f, 0.7f, glm::vec3(points[9].x, 8.0f, points[9].y), 0.1f, 0.1f, 0.01f);
	pointLight[10] = new PointLight(glm::vec3(1.0f, 0.0f, 0.1f), 0.0f, 0.7f, glm::vec3(points[10].x, 8.0f, points[10].y), 0.1f, 0.1f, 0.01f);
	pointLight[11] = new PointLight(glm::vec3(1.0f, 0.0f, 0.2f), 0.0f, 0.7f, glm::vec3(points[11].x, 8.0f, points[11].y), 0.1f, 0.1f, 0.01f);
}


//Zwolnienie zasobów zajętych przez program
void freeOpenGLProgram(GLFWwindow* window) {
    //************Tutaj umieszczaj kod, który należy wykonać po zakończeniu pętli głównej************
	delete sp;
}

//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glm::mat4 P=glm::perspective(50.0f*PI/180.0f, aspectRatio, 0.01f, 500.0f);

    glm::mat4 M = pojazd->getM();

    sp->use();

	sp->useDirectionalLight(directionalLight, 1);
	sp->usePointLight(pointLight, 12);

	spotLight[0]->calculateSpotLightFromMatrix(pojazd->getM());
	spotLight[1]->calculateSpotLightFromMatrix(wrog[0]->getM());
	spotLight[2]->calculateSpotLightFromMatrix(wrog[1]->getM());
	spotLight[3]->calculateSpotLightFromMatrix(wrog[2]->getM());

	sp->useSpotLight(spotLight, 3);
	sp->useMaterial(material);

	glUniform3f(sp->u("cameraPosition"), camera.position.x, camera.position.y, camera.position.z); //!!!
	

    glUniformMatrix4fv(sp->u("P"),1,false,glm::value_ptr(P));
    //glUniformMatrix4fv(sp->u("M"),1,false,glm::value_ptr(M));


	glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices); //Wskaż tablicę z danymi dla atrybutu vertex

	glEnableVertexAttribArray(sp->a("normal"));  //Włącz przesyłanie danych do atrybutu normal
	glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals); //Wskaż tablicę z danymi dla atrybutu normal

	glEnableVertexAttribArray(sp->a("texCoord"));  //Włącz przesyłanie danych do atrybutu texCoord
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, texCoords); //Wskaż tablicę z danymi dla atrybutu texCoord

	glUniform1i(sp->u("theTexture"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex1);

	glm::mat4 V = camera.calculateViewMatrixFromObject(M);
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));

	pojazd->draw(sp, tex2);
	for (int i = 0; i < 3; i++)
	{
		wrog[i]->drawScale(sp, tex3, glm::vec3(2.0f, 2.0f, 2.0f));
		wrog[i]->control(points, 12);
		sprawdzKolizjeSAT(pojazd, wrog[i]);
	}


	for (int i = 0; i < ilos; i++)
	{
		obj[i]->draw(sp, tex0);
	}
	for (int i = 0; i < ilos; i++)
	{
		sprawdzKolizjeSAT(pojazd, obj[i]);
	}

	M = glm::mat4(1.0f);

	glUniform1i(sp->u("theTexture"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex0);

	M = glm::translate(M, glm::vec3(0.0f, -1.0f, 0.0f));
	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, verticesFloor); //Wskaż tablicę z danymi dla atrybutu vertex
	glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normalsFloor); //Wskaż tablicę z danymi dla atrybutu normal
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, texCoordsFloor); //Wskaż tablicę z danymi dla atrybutu texCoord
	glDrawArrays(GL_TRIANGLES, 0, vertexCountFloor);

	if (keys[GLFW_KEY_G]) {
		printf("%f %f\n", pojazd->getM()[3][0], pojazd->getM()[3][2]);
	}


    glDisableVertexAttribArray(sp->a("vertex"));
	glDisableVertexAttribArray(sp->a("normal"));
	glDisableVertexAttribArray(sp->a("texCoord"));

    glfwSwapBuffers(window); //Przerzuć tylny bufor na przedni
}


int main(void)
{
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		fprintf(stderr, "Nie można utworzyć okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Operacje inicjujące

	//Główna pętla
	float lastTime = glfwGetTime();
	float nowTime;

	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
		nowTime = glfwGetTime();
		//camera.keyControl(keys, nowTime - lastTime);
		pojazd->keyControl(keys, nowTime - lastTime);
		lastTime = nowTime;
     
		drawScene(window); //Wykonaj procedurę rysującą
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}

	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}
