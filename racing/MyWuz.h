#ifndef MYWUZ_H_INCLUDED
#define MYWUZ_H_INCLUDED

int myWuzVertexCount = 138;

float myWuzVertices[] = {

	//front
	0.4f, 0.0f, 0.5f, 1.0f,//pS.d.F
	0.4f, 0.4f, 0.5f, 1.0f,//pS.dS.F
	-0.4f, 0.0f, 0.5f, 1.0f,//lS.d.F


	0.4f, 0.4f, 0.5f, 1.0f,//pS.dS.F
	-0.4f, 0.0f, 0.5f, 1.0f,//lS.d.F
	-0.4f,0.4f,0.5f,1.0f, //lS.dS.F


	//prawy przod front
	 0.4f, 0.0f, 0.5f, 1.0f,//pS.d.F
	 0.4f, 0.4f, 0.5f, 1.0f,//pS.dS.F
	 0.5f, 0.4f,0.4f,1.0f,  //P.dS.sF

	 0.4f, 0.0f, 0.5f, 1.0f,//pS.d.F
	 0.5f,0.4f,0.4f,1.0f,  //P.dS.sF
	 0.5f,0.0f,0.4f,1.0f,  //P.d.sF


	 //lewy przod front
	 -0.4f, 0.0f, 0.5f, 1.0f,//pS.d.F
	 -0.4f, 0.4f, 0.5f, 1.0f,//pS.dS.F
	 -0.5f,0.4f,0.4f,1.0f,  //P.dS.sF

	 -0.4f, 0.0f, 0.5f, 1.0f,//pS.d.F
	 -0.5f,0.4f,0.4f,1.0f,  //P.dS.sF
	 -0.5f,0.0f,0.4f,1.0f,  //P.d.sF

	 //lampa lewa prz�d

	 -0.4f, 0.4f, 0.5f, 1.0f,//pS.dS.F
	 -0.5f, 0.4f, 0.4f, 1.0f,  //P.dS.sF
	 -0.4f, 0.5f, 0.4f, 1.0f,

	 //lampa prawa prz�d
	 0.4f, 0.4f, 0.5f, 1.0f,//pS.dS.F
	 0.5f, 0.4f, 0.4f, 1.0f,  //P.dS.sF
	 0.4f, 0.5f, 0.4f, 1.0f,


	 //pochyl przed mask�
	 0.4f,0.4f,0.5f,1.0f,
	 -0.4f,0.4f,0.5f,1.0f,
	 0.4f,0.5f,0.4f,1.0f,

	 -0.4f,0.4f,0.5f,1.0f,
	 0.4f,0.5f,0.4f,1.0f,
	 -0.4f,0.5f,0.4f,1.0f,
	 //maska
	 0.4f,0.5f,0.4f,1.0f,
	 0.4f,0.5f,0.2f,1.0f,
	 -0.4f,0.5f,0.4f,1.0f,

	 0.4f,0.5f,0.2f,1.0f,
	 -0.4f,0.5f,0.4f,1.0f,
	 -0.4f,0.5f,0.2f,1.0f,
	 //fragment od drzwi prawy
	 0.4f,0.5f,0.4f,1.0f,
	 0.4f,0.5f,-0.4f,1.0f,
	 0.5f,0.4f,-0.4f,1.0f,


	 0.5f,0.4f,-0.4f,1.0f,
	 0.4f,0.5f,0.4f,1.0f,
	 0.5f,0.4f,0.4f,1.0f,

	 //fragment od drzwi lewy
	 -0.4f,0.5f,0.4f,1.0f,
	 -0.4f,0.5f,-0.4f,1.0f,
	 -0.5f,0.4f,-0.4f,1.0f,


	 -0.5f,0.4f,-0.4f,1.0f,
	 -0.4f,0.5f,0.4f,1.0f,
	 -0.5f,0.4f,0.4f,1.0f,
	 //przednia szyba

	 0.4f,0.5f,0.2f,1.0f,
	 -0.4f,0.5f,0.2f,1.0f,
	 0.4f,0.7f,0.0f,1.0f,

	 -0.4f,0.5f,0.2f,1.0f,
	 0.4f,0.7f,0.0f,1.0f,
	 -0.4f,0.7f,0.0f,1.0f,
	 //bok prawy
	 0.5f,0.4f,0.4f,1.0f,
	 0.5,0.4f,-0.4f,1.0f,
	 0.5,0.0f,0.4f,1.0f,

	 0.5f,0.4f,-0.4f,1.0f,
	 0.5f,0.0f,0.4f,1.0f,
	 0.5f,0.0f,-0.4f,1.0f,

	 //bok lewy
	 -0.5f,0.4f,0.4f,1.0f,
	 -0.5,0.4f,-0.4f,1.0f,
	 -0.5,0.0f,0.4f,1.0f,

	 -0.5f,0.4f,-0.4f,1.0f,
	 -0.5f,0.0f,0.4f,1.0f,
	 -0.5f,0.0f,-0.4f,1.0f,
	 //prawa szyba przednia
	 0.4f,0.5f,0.2f,1.0f,
	 0.4f,0.5f,0.0f,1.0f,
	 0.4f,0.7f,0.0f,1.0f,

	 //lewa szyba przednia
	 -0.4f, 0.5f, 0.2f, 1.0f,
	 -0.4f, 0.5f, 0.0f, 1.0f,
	 -0.4f, 0.7f, 0.0f, 1.0f,

	 //prawa szyba boczna
	 0.4f,0.7f,0.0f,1.0f,
	 0.4f,0.7f,-0.15f,1.0f,
	 0.4f,0.5f,-0.15f,1.0f,

	 0.4f,0.7f,0.0f,1.0f,
	 0.4f,0.5f,-0.15f,1.0f,
	 0.4f,0.5f,0.0f,1.0f,


	 //lewa szyba boczna
	 -0.4f,0.7f,0.0f,1.0f,
	 -0.4f,0.7f,-0.15f,1.0f,
	 -0.4f,0.5f,-0.15f,1.0f,

	 -0.4f,0.7f,0.0f,1.0f,
	 -0.4f,0.5f,-0.15f,1.0f,
	 -0.4f,0.5f,0.0f,1.0f,


	 //g�ra
	 -0.4f, 0.7f, 0.0f, 1.0f,
	 -0.4f, 0.7f, -0.15f, 1.0f,
	 0.4f, 0.7f, -0.15f, 1.0f,

	 0.4f, 0.7f, -0.15f, 1.0f,
	 -0.4f, 0.7f, 0.0f, 1.0f,
	 0.4f,0.7f,0.0f,1.0f,

	 //szyba prawa tylna
	 0.4f,0.7f,-0.15f,1.0f,
	 0.4f,0.5f,-0.15f,1.0f,
	 0.4f, 0.5f,-0.3f,1.0f,


	 //lewa prawa tylna
	 -0.4f, 0.7f, -0.15f, 1.0f,
	 -0.4f, 0.5f, -0.15f, 1.0f,
	 -0.4f, 0.5f, -0.3f, 1.0f,


	 //tylnia szyba
	 0.4f, 0.7f, -0.15f, 1.0f,
	 0.4f, 0.5f, -0.3f, 1.0f,
	 -0.4f, 0.7f, -0.15f, 1.0f,

	 0.4f, 0.5f, -0.3f, 1.0f,
	 -0.4f, 0.7f, -0.15f, 1.0f,
	 -0.4f,0.5f,-0.3f,1.0f,
	 //baga�nik
	 -0.4f, 0.5f, -0.3f, 1.0f,
	 0.4f, 0.5f, -0.3f, 1.0f,
	 0.4f, 0.5f, -0.4f, 1.0f,

	 0.4f, 0.5f, -0.4f, 1.0f,
	 -0.4f, 0.5f, -0.3f, 1.0f,
	 -0.4f,0.5f, -0.4f,1.0f,

	 //lampy tylnie
	 0.5f,0.4f,-0.4f,1.0f,
	 0.4f,0.5f,-0.4f,1.0f,
	 0.4f,0.4f,-0.5f,1.0f,

	 -0.5f, 0.4f, -0.4f, 1.0f,
	 -0.4f, 0.5f, -0.4f, 1.0f,
	 -0.4f, 0.4f, -0.5f, 1.0f,

	 //schy� baga�nika
	 0.4f, 0.4f, -0.5f, 1.0f,
	 -0.4f, 0.4f, -0.5f, 1.0f,
	 0.4f, 0.5f, -0.4f, 1.0f,

	 -0.4f, 0.4f,-0.5f, 1.0f,
	 0.4f, 0.5f, -0.4f, 1.0f,
	 -0.4f, 0.5f, -0.4f, 1.0f,

	 //back
  0.4f, 0.0f, -0.5f, 1.0f,//pS.d.F
  0.4f, 0.4f, -0.5f, 1.0f,//pS.dS.F
  -0.4f, 0.0f, -0.5f, 1.0f,//lS.d.F


  0.4f, 0.4f, -0.5f, 1.0f,//pS.dS.F
  -0.4f, 0.0f, -0.5f, 1.0f,//lS.d.F
  -0.4f, 0.4f, -0.5f, 1.0f, //lS.dS.F


  //prawy ty� back
  0.4f, 0.0f, -0.5f, 1.0f,//pS.d.F
  0.4f, 0.4f, -0.5f, 1.0f,//pS.dS.F
  0.5f, 0.4f, -0.4f, 1.0f,  //P.dS.sF

  0.4f, 0.0f, -0.5f, 1.0f,//pS.d.F
  0.5f, 0.4f, -0.4f, 1.0f,  //P.dS.sF
  0.5f, 0.0f, -0.4f, 1.0f,  //P.d.sF


  //lewy ty� back
  -0.4f, 0.0f, -0.5f, 1.0f,//pS.d.F
  -0.4f, 0.4f, -0.5f, 1.0f,//pS.dS.F
  -0.5f, 0.4f, -0.4f, 1.0f,  //P.dS.sF

  -0.4f, 0.0f, -0.5f, 1.0f,//pS.d.F
  -0.5f, 0.4f, -0.4f, 1.0f,  //P.dS.sF
  -0.5f, 0.0f, -0.4f, 1.0f,  //P.d.sF

};


float myWuzNormals[] = {
	//front
	0.0f,0.0f,1.0f,0.0f,
	0.0f,0.0f,1.0f,0.0f,
	0.0f,0.0f,1.0f,0.0f,

	0.0f,0.0f,1.0f,0.0f,
	0.0f,0.0f,1.0f,0.0f,
	0.0f,0.0f,1.0f,0.0f,


	//prawy prz�d front

	0.5f,0.0f,0.5f,0.0f,
	0.5f,0.0f,0.5f,0.0f,
	0.5f,0.0f,0.5f,0.0f,

	0.5f,0.0f,0.5f,0.0f,
	0.5f,0.0f,0.5f,0.0f,
	0.5f,0.0f,0.5f,0.0f,


	//lewy prz�d front

	-0.5f,0.0f,0.5f,0.0f,
	-0.5f,0.0f,0.5f,0.0f,
	-0.5f,0.0f,0.5f,0.0f,

	-0.5f,0.0f,0.5f,0.0f,
	-0.5f,0.0f,0.5f,0.0f,
	-0.5f,0.0f,0.5f,0.0f,


	//lampa lewa prz�d
	-1.0f,1.0f,1.0f,0.0f,
	-1.0f,1.0f,1.0f,0.0f,
	-1.0f,1.0f,1.0f,0.0f,

	//lampa prawa prz�d
	1.0f,1.0f,1.0f,0.0f,
	1.0f,1.0f,1.0f,0.0f,
	1.0f,1.0f,1.0f,0.0f,


	//pochyl przed mask�
	0.0f,1.0f,1.0f,0.0f,
	0.0f,1.0f,1.0f,0.0f,
	0.0f,1.0f,1.0f,0.0f,

	0.0f,1.0f,1.0f,0.0f,
	0.0f,1.0f,1.0f,0.0f,
	0.0f,1.0f,1.0f,0.0f,

	//maska
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,

	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,

	//fragment od drzwi prawy
	1.0f,1.0f,0.0f,0.0f,
	1.0f,1.0f,0.0f,0.0f,
	1.0f,1.0f,0.0f,0.0f,

	1.0f,1.0f,0.0f,0.0f,
	1.0f,1.0f,0.0f,0.0f,
	1.0f,1.0f,0.0f,0.0f,
	//fragment od drzwi lewy
	-1.0f,1.0f,0.0f,0.0f,
	-1.0f,1.0f,0.0f,0.0f,
	-1.0f,1.0f,0.0f,0.0f,

	-1.0f,1.0f,0.0f,0.0f,
	-1.0f,1.0f,0.0f,0.0f,
	-1.0f,1.0f,0.0f,0.0f,

	//przednia szyba
	0.0f,1.0f,1.0f,0.0f,
	0.0f,1.0f,1.0f,0.0f,
	0.0f,1.0f,1.0f,0.0f,

	0.0f,1.0f,1.0f,0.0f,
	0.0f,1.0f,1.0f,0.0f,
	0.0f,1.0f,1.0f,0.0f,
	//bok prawy
	1.0f,0.0f,0.0f,0.0f,
	1.0f,0.0f,0.0f,0.0f,
	1.0f,0.0f,0.0f,0.0f,

	1.0f,0.0f,0.0f,0.0f,
	1.0f,0.0f,0.0f,0.0f,
	1.0f,0.0f,0.0f,0.0f,
	//bok lewy
	-1.0f,0.0f,0.0f,0.0f,
	-1.0f,0.0f,0.0f,0.0f,
	-1.0f,0.0f,0.0f,0.0f,

	-1.0f,0.0f,0.0f,0.0f,
	-1.0f,0.0f,0.0f,0.0f,
	-1.0f,0.0f,0.0f,0.0f,
	//prawa szyba przednia
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,

	//lewa szyba przednia
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,
	//prawa szyba boczna
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,
	//lewa szyba boczna
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,


	//g�ra
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,

	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,

	//szyba prawa tylna
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f, 0.0f,
	//lewa prawa tylna
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f, 0.0f,

	//tylnia szyba

	0.0f,3.0f,-4.0f,0.0f,
	0.0f, 0.3f, -0.4f, 0.0f,
	0.0f, 0.3f, -0.4f, 0.0f,

	0.0f, 0.3f, -0.4f, 0.0f,
	0.0f, 0.3f, -0.4f, 0.0f,
	0.0f, 0.3f, -0.4f, 0.0f,
	//baga�nik
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,

	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,
	0.0f,1.0f,0.0f,0.0f,


	//lampy tylnie
	// prawa
	1.0f, 1.0f, -1.0f, 0.0f,
	1.0f, 1.0f, -1.0f, 0.0f,
	1.0f, 1.0f, -1.0f, 0.0f,
	// lewa
	-1.0f, 1.0f, -1.0f, 0.0f,
	-1.0f, 1.0f, -1.0f, 0.0f,
	-1.0f, 1.0f, -1.0f, 0.0f,
	//schy� baga�nika
	0.0f,1.0f,-1.0f,0.0f,
	0.0f, 1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, -1.0f, 0.0f,

	0.0f, 1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, -1.0f, 0.0f,
	//back
	0.0f,0.0f,-1.0f,0.0f,
	0.0f, 0.0f, -1.0f, 0.0f,
	0.0f, 0.0f, -1.0f, 0.0f,

	0.0f, 0.0f, -1.0f, 0.0f,
	0.0f, 0.0f, -1.0f, 0.0f,
	0.0f, 0.0f, -1.0f, 0.0f,
	//prawy ty� back
	1.0f,0.0f,-1.0f, 0.0f,
	1.0f, 0.0f, -1.0f, 0.0f,
	1.0f, 0.0f, -1.0f, 0.0f,

	1.0f, 0.0f, -1.0f, 0.0f,
	1.0f, 0.0f, -1.0f, 0.0f,
	1.0f, 0.0f, -1.0f, 0.0f,
	//lewy ty� back
	-1.0f, 0.0f, -1.0f, 0.0f,
	-1.0f, 0.0f, -1.0f, 0.0f,
	-1.0f, 0.0f, -1.0f, 0.0f,

	-1.0f, 0.0f, -1.0f, 0.0f,
	-1.0f, 0.0f, -1.0f, 0.0f,
	-1.0f, 0.0f, -1.0f, 0.0f,



};


float myWuzColors[] = {
	//�ciana 1
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,

	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,

	//�ciana 2
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,

	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,

	//�ciana 3
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	//�ciana 4
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,

	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,

	//�ciana 5
	0.0f,1.0f,1.0f,1.0f,
	0.0f,1.0f,1.0f,1.0f,
	0.0f,1.0f,1.0f,1.0f,

	0.0f,1.0f,1.0f,1.0f,
	0.0f,1.0f,1.0f,1.0f,
	0.0f,1.0f,1.0f,1.0f,

	//�ciana 6
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,

	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,

	//�ciana 2
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,

	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,

	//�ciana 3
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	//�ciana 4
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,

	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,
	1.0f,1.0f,0.0f,1.0f,

	//�ciana 5
	0.0f,1.0f,1.0f,1.0f,
	0.0f,1.0f,1.0f,1.0f,
	0.0f,1.0f,1.0f,1.0f,

	0.0f,1.0f,1.0f,1.0f,
	0.0f,1.0f,1.0f,1.0f,
	0.0f,1.0f,1.0f,1.0f,

	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,

	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	//�ciana 2
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,

	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,
	//�ciana 3
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	//�ciana 4
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,

1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,


1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
//�ciana 6
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

//�ciana 3
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,

0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,

//�ciana 2
0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,

0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,
//�ciana 2
0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,

0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,
//g�ra
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,

0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,

//�ciana 3
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,

0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,
0.0f, 0.0f, 1.0f, 1.0f,

//�ciana 1
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,


//�ciana 4
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,

1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,
//�ciana 5
0.0f, 1.0f, 1.0f, 1.0f,
0.0f, 1.0f, 1.0f, 1.0f,
0.0f, 1.0f, 1.0f, 1.0f,

0.0f, 1.0f, 1.0f, 1.0f,
0.0f, 1.0f, 1.0f, 1.0f,
0.0f, 1.0f, 1.0f, 1.0f,

//�ciana 4
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,

1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f, 1.0f,


//�ciana 1
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

//�ciana 1
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

//�ciana 1
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,

1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,
};


float myWuzTexCoords[] = {
	//front
		0.348f, 0.438f,	  0.348f, 0.319f,    0.0f, 0.438f,
		0.348f, 0.319f,   0.0f, 0.438f,    0.0f, 0.319f,

		//prawy prz�d front
			0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
			0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,

			//lewy prz�d front
				0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
				0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
				//lampa lewa prz�d
					0.368f, 0.433f,	  0.488f, 0.428f,    0.47f, 0.398f,
					//lampa prawa prz�d
						0.472f, 0.476f,   0.365f, 0.485f,    0.405f, 0.450f,


						//pochyl przed mask�
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							//maska

							0.357f, 0.795f, 0.357f, 0.441f, 0.0f, 0.796f,
							0.357f, 0.441f, 0.0f, 0.796f, 0.0f, 0.441f,

							//fragment od drzwi prawy

							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							//fagment od drzwi lewy
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							//przednia szyba
							0.375f, 1.0f,	  0.006f, 1.0f,    0.342f, 0.929f,
							0.006f, 1.0f,   0.342f, 0.929f,    0.041f, 0.929f,
							//prawy bok
							0.5f, 0.801f,	  0.0f, 0.801f,    0.5f, 0.913f,
							0.0f, 0.801f,   0.5f, 0.913f,    0.0f, 0.913f,
							//lewy bok
							0.5f, 0.801f,	  0.0f, 0.801f,    0.5f, 0.913f,
							0.0f, 0.801f,   0.5f, 0.913f,    0.0f, 0.913f,
							//prawa szyba przednia
							0.388f, 0.685f,	  0.378f, 0.650f,    0.450f, 0.684f,
							//lewa szyba przednia
							0.388f, 0.685f,	  0.378f, 0.650f,    0.450f, 0.684f,
							//szyba boczna prawa
							0.401f, 0.684f,	  0.449f, 0.684f,    0.422f, 0.660f,
							0.401f, 0.684f,   0.422f, 0.660f,    0.449f, 0.684f,
							//szyba boczna lewa
							0.401f, 0.684f,	  0.449f, 0.684f,    0.422f, 0.660f,
							0.401f, 0.684f,   0.422f, 0.660f,    0.449f, 0.684f,

							//g�ra
							0.494f, 0.504f,	  0.494f, 0.631f,    0.360f, 0.627f,
							0.360f, 0.627f,   0.494f, 0.504f,    0.360f, 0.504f,
							//tylnie szyby
							0.394f, 0.685f,	  0.422f, 0.655f,    0.448f, 0.685f,
							0.394f, 0.685f,	  0.422f, 0.655f,    0.448f, 0.685f,
							//tylnia szyba
							0.362f, 0.633f,	  0.479f, 0.639f,    0.363f, 0.794f,
							0.479f, 0.639f,    0.363f, 0.794f,    0.479f, 0.794f,
							//baga�nik
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,

							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,

							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							//ty�
							0.961f, 0.337f,	  0.943f, 0.251f,    0.66f, 0.419f,
							0.943f, 0.251f,    0.66f, 0.419f,    0.627f, 0.330f,

							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,

							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,
							0.9f, 0.9f,	  0.8f, 0.7f,    0.7f, 0.7f,

};



#endif