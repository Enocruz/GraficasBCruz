/*************************************************
/  Materia: Gr�ficas computacionales
/
/  Autor: Brandon Alain Cruz Ruiz  A01375640
/
/  Fecha: 21 de Agosto del 2017
/
/  Tarea: Introducci�n a la programaci�n
/
/*************************************************/



//OPEN GL

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
#include <iostream>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camera.h"



Mesh mesh;
ShaderProgram shProgram;
Transform _transform;
Camera _camera;

void Initialize() {
	//C�digo para crear el cubo

	//Creacin del atributo de posiciones de estos vertices. Lista de vec2.
	//Claramente en CPU y RAM
	std::vector<glm::vec3> positions;
	//Cara derecha
	positions.push_back(glm::vec3(3.0f, 0, 3.0f));  //Esquina inferior derecha trasera => 0
	positions.push_back(glm::vec3(3.0f, 0, -3.0f)); //Esquina superior derecha trasera => 1
	positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha delantera => 2
	positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina inferior derecha delantera => 3, conecta triangulo con 0 y 2
													  //Cara de enfrente
	positions.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 4
	positions.push_back(glm::vec3(3.0f, 0, 3.0f)); //Esquina inferior derecha delantera => 5
	positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina superior derecha delantera => 6
	positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 7, conecta triangulo con 4 y 6
													   //Cara izquierda
	positions.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 8
	positions.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 9
	positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 10
	positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 11, conecta triangulo con 8 y 10
														//Cara de atras
	positions.push_back(glm::vec3(3.0f, 0, -3.0f));  //Esquina inferior derecha trasera => 12
	positions.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 13
	positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 14
	positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha trasera => 15,conecta triangilo con 12 y 14
													   //Cara de abajo
	positions.push_back(glm::vec3(3.0f, 0, 3.0f)); //Esquina inferior derecha delantera => 16
	positions.push_back(glm::vec3(-3.0f, 0, 3.0f)); //Esquina inferior izquierda delantera => 17
	positions.push_back(glm::vec3(-3.0f, 0, -3.0f)); //Esquina inferior izquierda trasera => 18
	positions.push_back(glm::vec3(3.0f, 0, -3.0f));  //Esquina inferior derecha trasera => 19, conecta trangulo con 16 y 18
													 //Cara de arriba
	positions.push_back(glm::vec3(3.0f, 6.0f, 3.0f)); //Esquina superior derecha delantera => 20
	positions.push_back(glm::vec3(-3.0f, 6.0f, -3.0f)); //Esquina superior izquierda trasera => 21
	positions.push_back(glm::vec3(-3.0f, 6.0f, 3.0f)); //Esquina superior izquierda delantera => 22
	positions.push_back(glm::vec3(3.0f, 6.0f, -3.0f)); //Esquina superior derecha trasera => 23,conecta triangulo con 20 y 22


	std::vector<glm::vec3> colors;
	//Color cara 1
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Color cara 2
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Color cara 3
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Color cara 4
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	//Color cara 5
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Color cara 6
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	//Se crea el vector con los ndices de las posiciones
	std::vector<unsigned int> indices = {
		0, 1, 2, 0, 2, 3, //Cara 1
		4, 5, 6, 4, 6, 7, //Cara 2
		8, 9, 10, 8, 10, 11, //Cara 3
		12, 13, 14, 12, 14, 15, //Cara 4
		16, 17, 18, 16, 18, 19, //Cara 5
		20, 21, 22, 20, 23, 21 //Cara 6
	};

	



	mesh.CreateMesh(positions.size());
	mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	//mesh.SetIndices(indicesColores, GL_STATIC_DRAW);
	mesh.SetIndices(indices, GL_STATIC_DRAW);
	shProgram.CreateProgram();
	shProgram.SetAttribute(0, "VertexPosition");
	shProgram.SetAttribute(1, "VertexColor");
	shProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	shProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	shProgram.LinkProgram();

	//Se ajusta la c�mara para que se vea todo el cubo
	_camera.SetPosition(0.0f, 1.0f, 20.0f);








	/*
	********** PENTAGONO MOVIENDOSE Y CAMARA MOVIENDOSE **********


	double angulo = 18;

	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(glm::cos(glm::radians(90.0f)), glm::sin(glm::radians(90.0f))));
	
	for(double i = 0; i <= 4; i++) {
		positions.push_back(glm::vec2(0.5*glm::cos(glm::radians(angulo)), 0.5 * glm::sin(glm::radians(angulo))));
		positions.push_back(glm::vec2(glm::cos(glm::radians(angulo)), glm::sin(glm::radians(angulo))));
		angulo -= 72;
		if (angulo < 0) {
			angulo += 360;
		}
	}
	
	positions.push_back(glm::vec2(f5*glm::cos(glm::radians(18.0f)),0.5*glm::sin(glm::radians(18.0f))));

	

	std::vector<glm::vec3> colors;
	for (double i = 0; i <= 11; i++) {
		colors.push_back(glm::vec3(1.0f,0.0f,0.0f));
	}
	
	
	mesh.CreateMesh(12);
	mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	shProgram.CreateProgram();
	shProgram.SetAttribute(0, "VertexPosition");
	shProgram.SetAttribute(1, "VertexColor");
	shProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	shProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	shProgram.LinkProgram();

	_transform.SetRotation(0.0f, 0.0f, 90.0f);
	//_camera.SetOrthographic(1.0f, 1.0f);
	*/	
}

void GameLoop() {

	//Limpiamos el buffer de color y el buffer de profundidad
	//Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_transform.Rotate(0.01f, 0.01f, 0.01f, false);
	//_camera.MoveForward(0.001f);

	shProgram.Activate();
	shProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);
	shProgram.Deactivate();

	//Cuando terminamos de renderear, cambiamos los buffers
	glutSwapBuffers();
}

void Idle() {
	//Cuando OpenGL entra en modo reposo (para ahorrar bateria, por ejemplo)
	//le decimos que vuelva a dibujar
	//Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height) {
	
	glViewport(0, 0, width, height);
	/*
	//Para configurar un uniform, tenemos que decirle a OpenGL, que vamos a utilizar el
	//shader program (manager)
	glUseProgram(shaderProgram);

	GLint uniformLocation = glGetUniformLocation(shaderProgram, "Resolution");

	glUniform2f(uniformLocation, width, height);

	glUseProgram(0);
	*/
}

int main(int argc, char * argv[]) {

	//Inicializar freeglut.
	//Freeglut se encarga de crear una ventana para dibujar.
	glutInit(&argc, argv);

	//Solicitando una versi�n espec�fica de OpenGL.
	glutInitContextVersion(4, 4);

	//Inicia el contexto de OpenGL. El contexto se refiere a las capacidades que va a tener
	//nuestra aplicaci�n gr�fica. En este caso estamos trabajando con el pipeline cl�sico.
	glutInitContextProfile(GLUT_CORE_PROFILE);

	//Freeglut nos permite configurar eventos que ocurren en la ventana. Un evento que nos
	//interesa es cuando alguien cierra la ventana. En este caso, simplemente dejamos de 
	//renderear la escena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//Configuramos el framebuffer. En este caso estamos solicitando un buffer true color RGBA,
	//un bugger de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	//Iniciar las dimensiones de la ventana (en pixeles).
	glutInitWindowSize(400, 400);

	//Se crea la ventana con un t�tulo
	glutCreateWindow("Hello World GL");

	//Asociamos una funci�n de render. Esta funci�n se mandar� a llamar para dibujar un 
	//frame
	glutDisplayFunc(GameLoop);

	//Asociamos una funci�n para el cambio de resoluci�n de la ventana. Freeglut 
	//la manda a llamar cuando alguien cambie el tama�o de la ventana.
	glutReshapeFunc(ReshapeWindow);

	//Asociamos la funci�n que se mandar� a llamar cuando OpenGL entre en modo de reposo
	glutIdleFunc(Idle);

	//Inicializamos GLEW. Esta librer�a se encarga de obtener el API de OpenGl de nuestra
	//tarjeta de video.
	glewInit();

	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	//std::cout << glGetString(GL_VERSION) << std::endl;

	//Adem�s de solicitar el buffer de profundidad, tenemos que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	//Activamos el borrado de caras traseras
	//Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	//No dibujar las caras traseras de la geometr�a
	glCullFace(GL_BACK);

	//Configuraci�n inicial de nuestro programa
	Initialize();

	//Iniciar la aplicaci�n. El main se pausar� en esta l�nea hasta que se cierre la ventana.
	glutMainLoop();

	std::cin.get();
	return 0;
}


/*
//Identificador del manager al que vamos a asociar todos los VBOs
GLuint vao;
GLuint shaderProgram;

void Initialize() {
	//Creando toda la memoria (s�lo una vez)

	//Creaci�n del atributo de posiciones de los v�rtices
	//Lista de vec2
	//Claramente en el CPU
	std::vector<glm::vec2> positions;
	

	positions.push_back(glm::vec2(0.5f, -0.5f));
	positions.push_back(glm::vec2(0.5f, 0.5f));
	positions.push_back(glm::vec2(-0.5f, -0.5f));
	positions.push_back(glm::vec2(-0.5f, 0.5f));

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));

	//Generamos un manager
	glGenVertexArrays(1, &vao);
	//Utilizar el vao. A partir de este momento, todos los VBOs creados y 
	//configurados se van a asociar a este manager
	glBindVertexArray(vao);


	//Identificador del VBO de posiciones
	GLuint positionsVBO;
	//Creaci�n del VBO posiciones
	glGenBuffers(1, &positionsVBO);
	//Activamos el buffer de posiciones para poder utilizarlo
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//Creamos la memoria y la inicializamos con los datos del atributo de posiciones
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);
	//Activamos el atributo en la tarjeta de video
	glEnableVertexAttribArray(0); //Posici�n
	//Configuraos los datos del atributo en la tarjeta de video
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//Ya no se utiliza este VBO, as� que lo removemos
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Identificador del VBO de colores
	GLuint colorsVBO;
	//Creaci�n del VBO de colores
	glGenBuffers(1, &colorsVBO);
	//Activamos para poder utilizar
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);//Colores
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//Desactivamos el manager
	glBindVertexArray(0);

	//Creamos un objeto para leer archivos
	InputFile ifile;

	//VERTEX SHADER
	ifile.Read("Default.vert");
	std::cout << ifile.GetContents();
	std::string vertexSource = ifile.GetContents();
	//Creamos un shader de tipo vertex shader
	GLuint vertexShaderHandler = glCreateShader(GL_VERTEX_SHADER);
	//Obtener los datos en el formato correcto
	const GLchar * vertexSource_c = (const GLchar *)vertexSource.c_str();
	//Le estamos dando el c�digo fuente a OpenGL para que se lo asigne a shader
	glShaderSource(vertexShaderHandler, 1, &vertexSource_c, nullptr);
	//Compilamos el shader en busca de errores
	//Asumimos que no hay errores
	glCompileShader(vertexShaderHandler); 

	InputFile ifile2;
	ifile2.Read("Default.frag");
	std::cout << ifile2.GetContents() << "\n";
	std::string fragmentSource = ifile2.GetContents();
	GLuint fragmentShaderHandler = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar *fragmentSource_c = (const GLchar*)fragmentSource.c_str();
	glShaderSource(fragmentShaderHandler, 1, &fragmentSource_c, nullptr);
	glCompileShader(fragmentShaderHandler);


	//Creamos el identificador para el manager de los shaders
	shaderProgram = glCreateProgram();
	//Adjuntamos el vertex shader al manager
	glAttachShader(shaderProgram, vertexShaderHandler);
	//Adjuntamos el fragment shader al manager
	glAttachShader(shaderProgram, fragmentShaderHandler);
	//Asociamos un buffer con �ndice 0 (posiciones) a la variable VertexPosition
	glBindAttribLocation(shaderProgram, 0, "VertexPosition");
	//Asociamos un buffer con �ndice 1 (Colores) a la variable VertexColor
	glBindAttribLocation(shaderProgram, 1, "VertexColor");
	//Ejecutamos el proceso de linker (aseguramos que el vertex y fragment son compatibles)
	glLinkProgram(shaderProgram);

}

*/
/*
void GameLoop() {

	//Limpiamos el buffer de color y el buffer de profundidad
	//Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Activamos el vertex shader y el fragment shader utilizando el manager
	glUseProgram(shaderProgram);
	//Activamos el manager, en este momento se activan todos los VBO
	//asociados autom�ticamente
	glBindVertexArray(vao);
	//Funci�n de dibujado sin �ndices
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//Terminamos de utilizar el manager
	glBindVertexArray(0);
	//Desactivamos el manager
	glUseProgram(0);
	
	//Cuando terminamos de renderear, cambiamos los buffers
	glutSwapBuffers();
}

int main(int argc, char * argv[]) {

	//Inicializar freeglut.
	//Freeglut se encarga de crear una ventana para dibujar.
	glutInit(&argc, argv);

	//Solicitando una versi�n espec�fica de OpenGL.
	glutInitContextVersion(4, 4);
	
	//Inicia el contexto de OpenGL. El contexto se refiere a las capacidades que va a tener
	//nuestra aplicaci�n gr�fica. En este caso estamos trabajando con el pipeline cl�sico.
	glutInitContextProfile(GLUT_CORE_PROFILE);

	//Freeglut nos permite configurar eventos que ocurren en la ventana. Un evento que nos
	//interesa es cuando alguien cierra la ventana. En este caso, simplemente dejamos de 
	//renderear la escena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//Configuramos el framebuffer. En este caso estamos solicitando un buffer true color RGBA,
	//un bugger de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	//Iniciar las dimensiones de la ventana (en pixeles).
	glutInitWindowSize(400, 400);

	//Se crea la ventana con un t�tulo
	glutCreateWindow("Hello World GL");

	//Asociamos una funci�n de render. Esta funci�n se mandar� a llamar para dibujar un 
	//frame
	glutDisplayFunc(GameLoop);

	//Inicializamos GLEW. Esta librer�a se encarga de obtener el API de OpenGl de nuestra
	//tarjeta de video.
	glewInit();

	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	//std::cout << glGetString(GL_VERSION) << std::endl;

	//Configuraci�n inicial de nuestro programa
	Initialize();

	//Iniciar la aplicaci�n. El main se pausar� en esta l�nea hasta que se cierre la ventana.
	glutMainLoop();

	std::cin.get();
	return 0;
}

*/
/*
int main() {
std::string filename = "Prueba.txt";
InputFile myFile;
myFile.Read(filename);
std::string contents = myFile.GetContents();
std::cout << "Contents: " << contents << std::endl;
std::cin.get();
return 0;
}*/


/*
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
vec2 p = fragCoord /iResolution.xy;

vec2 q = p - vec2(0.35f,0.7f);

vec3 color = mix(vec3(1.0f,0.4f,0.1f),
vec3(1.0f,0.8f,0.3f),
sqrt(p.y));

float r = 0.2f +0.1f * cos(atan(q.y,q.x)*10.0f +20.0f*q.x +1.0f);

color *= smoothstep(r,r+0.01f, length(q));

r = 0.015f;

r += 0.002 * cos (120.0f * q.y);

r += exp(-40.0f * p.y);

color *= 1.0f -
(1.0f - smoothstep(r,r+0.002, abs(q.x -0.25f * sin(2.0f * q.y)))) *
(1.0f - smoothstep(0.0f, 0.01f, q.y));

fragColor = vec4(color,1.0f);
}
*/

/*************************************************
/  Materia: Gr�ficas computacionales			
/
/  Autor: Brandon Alain Cruz Ruiz  A01375640
/
/  Fecha: 14 de Agosto del 2017
/
/  Tarea: Ejercicios de programaci�n b�sicos.pdf
/
/*************************************************/

/*
#include <iostream>

void FilaEstrellas(int n) {
	for (int i = 0; i < n; i++)
		std::cout << "*";
}

int PerimetroRectangulo(int base, int altura) {
	return 2 * base + 2 * altura;
}

float AreaTriangulo(float base, float altura) {
	return (base*altura) / 2;
}

int Mayor(int numero1, int numero2, int numero3) {
	if (numero1 > numero2 && numero1 > numero3)
		return numero1;
	else if (numero2 > numero1 && numero2 > numero3)
		return numero2;
	else
		return numero3;
}

int Menor(int numero1, int numero2, int numero3) {
	if (numero1 < numero2 && numero1 < numero3)
		return numero1;
	else if (numero2 < numero1 && numero2 < numero3)
		return numero2;
	else
		return numero3;
}

void MatrizEstrellas(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

void PiramideEstrellas(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

void FlechaEstrellas(int n) {
	for (int i = 1; i <= n; i++ ) {
		for (int j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	for (int i = n - 1; i != 0; i--) {
		for (int j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

void Fibonacci(int n) {
	int f0 = 0;
	int f1 = 1;
	std::cout << f0 << " ";
	if (n == 0)
		return;
	else {
		std::cout << f1 << " ";
		for (int i = 1; i < n; i++) {
			int sum = f0 + f1;
			std::cout << sum << " ";
			f0 = f1;
			f1 = sum;
		}
	}
}

bool EsPrimo(int numero) {
	if (numero == 0 || numero == 1)
		return false;
	for (int i = 2; i < numero; i++) {
		if (numero%i == 0)
			return false;
		else
			continue;
	}
	return true;
}

int main() {
	//Problema 1
	int p = PerimetroRectangulo(5, 3);
	std::cout << "El valor de p es " << p;
	std::cout << "\n";
	//Problema 2
	float a = AreaTriangulo(5.0f, 3.0f);
	std::cout << "El valor de a es " << a;
	std::cout << "\n";
	//Problema 3
	int mayor = Mayor(5, 9, 1);
	std::cout << "El mayor es " << mayor;
	std::cout << "\n";
	//Problema 4
	int menor = Menor(5, 9, 1);
	std::cout << "El menor es " << menor;
	std::cout << "\n";
	//Problema 5
	FilaEstrellas(5);
	std::cout << "\n";
	//Problema 6
	MatrizEstrellas(4);
	std::cout << "\n";
	//Problema 7
	PiramideEstrellas(6);
	std::cout << "\n";
	//Problema 8
	FlechaEstrellas(3);
	std::cout << "\n";
	//Problema 9
	Fibonacci(9);
	std::cout << "\n";
	//Problema 10
	bool primo = EsPrimo(79);
	primo == 1 ? std::cout << "True" : std::cout << "False";
	std::cout << "\n";
	primo = EsPrimo(52);
	primo == 1 ? std::cout << "True" : std::cout << "False";
	std::cin.get();
	return 0;
}
*/

/*
#include <iostream>
#include "Rectangle.h"
#include "Employee.h"

int main() {
	Rectangle r1;
	std::cout << r1.GetWidth() << " " << r1.GetPerimeter() << "\n";
	
	Employee e1(1, "Brandon", "Alain", 100);
	std::cout << e1.Print();

	std::cin.get();
	return 0;

}
*/
