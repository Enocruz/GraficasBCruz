/*************************************************
/  Materia: Gráficas computacionales
/
/  Autor: Brandon Alain Cruz Ruiz  A01375640
/
/  Fecha: 21 de Agosto del 2017
/
/  Tarea: Introducción a la programación
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
Transform geometria, geometria2;
Camera _camera;
float escala = 0.5f;
float radians = 0.0f, inc = 0.0001;

void Initialize() {
	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> colors;

	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
	positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
	positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	std::vector<unsigned int> indices = {
		0,4,1,
		1,4,2,
		2,4,3,
		3,4,0,
		0,1,2,
		0,2,3
	};

	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));

	mesh.CreateMesh(positions.size());
	mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	mesh.SetIndices(indices, GL_STATIC_DRAW);
	shProgram.CreateProgram();
	shProgram.SetAttribute(0, "VertexPosition");
	shProgram.SetAttribute(1, "VertexColor");
	shProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	shProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	shProgram.LinkProgram();

	geometria.SetScale(3.0f, 3.0f, 3.0f);
	geometria.SetPosition(0.0f, 1.0f, 0.0f);
	
	geometria2.SetScale(0.5f,0.5f, 0.5f);
	_camera.SetPosition(0.0f, 0.0f, 25.0f);

}

void GameLoop() {

	//Limpiamos el buffer de color y el buffer de profundidad
	//Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	geometria.Rotate(0.004f, 0.004f, 0.004f,false);
	geometria.SetPosition(5.0f*glm::cos(glm::radians(radians)), 5.0f*glm::sin(glm::radians(radians)), 0.0f);
	radians += 0.005f;

	if (escala >= 1.0f)
		inc *= -1;
	else if (escala <= 0.25f)
		inc *= -1;
	escala += inc;
	geometria2.SetScale(escala, escala, escala);
	geometria2.Rotate(-0.004f, -0.004f, -0.004f, false);

	shProgram.Activate();

	shProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * geometria.GetModelMatrix());
	mesh.Draw(GL_TRIANGLES);

	shProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * geometria2.GetModelMatrix());
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

	//Solicitando una versión específica de OpenGL.
	glutInitContextVersion(4, 4);

	//Inicia el contexto de OpenGL. El contexto se refiere a las capacidades que va a tener
	//nuestra aplicación gráfica. En este caso estamos trabajando con el pipeline clásico.
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

	//Se crea la ventana con un título
	glutCreateWindow("Hello World GL");

	//Asociamos una función de render. Esta función se mandará a llamar para dibujar un 
	//frame
	glutDisplayFunc(GameLoop);

	//Asociamos una función para el cambio de resolución de la ventana. Freeglut 
	//la manda a llamar cuando alguien cambie el tamaño de la ventana.
	glutReshapeFunc(ReshapeWindow);

	//Asociamos la función que se mandará a llamar cuando OpenGL entre en modo de reposo
	glutIdleFunc(Idle);

	//Inicializamos GLEW. Esta librería se encarga de obtener el API de OpenGl de nuestra
	//tarjeta de video.
	glewInit();

	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//std::cout << glGetString(GL_VERSION) << std::endl;

	//Además de solicitar el buffer de profundidad, tenemos que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	//Activamos el borrado de caras traseras
	//Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	//No dibujar las caras traseras de la geometría
	glCullFace(GL_BACK);

	//Configuración inicial de nuestro programa
	Initialize();

	//Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre la ventana.
	glutMainLoop();

	std::cin.get();
	return 0;
}
