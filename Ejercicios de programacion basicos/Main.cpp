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
#include "Texture2D.h"
#include <IL/il.h>

Mesh mesh;
ShaderProgram shProgram,shProgramPuerco;
Transform geometria, geometria2;
Camera _camera;
Texture2D myTexture, myTexture2,myTexture3;
float escala = 0.5f;
float radians = 0.0f, inc = 0.0001;
glm::vec3 LightColor = glm::vec3(1.0f, 1.0f, 1.0f);
float t = 0.01f;

void Initialize() {
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


	std::vector<glm::vec3> normals;
	//Normales cara derecha
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara de enfrente 
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara izquierda
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	//Cara de atrás
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	//Cara de abajo
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	//Cara de arriba
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	std::vector<glm::vec2> textures;
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));

	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));

	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));

	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));

	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));

	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));

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
	mesh.SetNormalAttibute(normals, GL_STATIC_DRAW, 2);
	mesh.SetTextureAttribute(textures, GL_STATIC_DRAW, 3);
	mesh.SetIndices(indices, GL_STATIC_DRAW);

	//Textura Puerco
	shProgramPuerco.CreateProgram();
	shProgramPuerco.SetAttribute(0, "VertexPosition");
	shProgramPuerco.SetAttribute(1, "VertexColor");
	shProgramPuerco.SetAttribute(2, "VertexNormal");
	shProgramPuerco.SetAttribute(3, "VertexTexCoord");
	shProgramPuerco.AttachShader("TexturePuerco.vert", GL_VERTEX_SHADER);
	shProgramPuerco.AttachShader("TexturePuerco.frag", GL_FRAGMENT_SHADER);
	shProgramPuerco.LinkProgram();

	shProgramPuerco.Activate();
	shProgramPuerco.SetUniformf("LightColor", LightColor.x, LightColor.y, LightColor.z);
	shProgramPuerco.SetUniformf("LightPosition", 0.0f, 1.0f, 10.0f);
	shProgramPuerco.SetUniformi("DiffuseTexture0", 0);
	shProgramPuerco.SetUniformi("DiffuseTexturePuerco", 1);
	shProgramPuerco.Deactivate();

	shProgram.CreateProgram();
	shProgram.SetAttribute(0, "VertexPosition");
	shProgram.SetAttribute(1, "VertexColor");
	shProgram.SetAttribute(2, "VertexNormal");
	shProgram.SetAttribute(3, "VertexTexCoord");
	shProgram.AttachShader("Texture.vert", GL_VERTEX_SHADER);
	shProgram.AttachShader("Texture.frag", GL_FRAGMENT_SHADER);
	shProgram.LinkProgram();

	//Se ajusta la cmara para que se vea todo el cubo
	_camera.SetPosition(0.0f, 15.0f, 35.0f);
	_camera.Rotate(-30.0f, 0.0f, 0.0f,false);
	geometria2.SetScale(15.0f, 15.0f, 15.0f);
	geometria2.SetPosition(0.0f, -100.0f, 0.0f);

	myTexture.LoadTexture("box.jpg");
	myTexture2.LoadTexture("floor.jpg");
	myTexture3.LoadTexture("puerco.png");

	//myTexture.LoadTexture("puerco.jpg");

	shProgram.Activate();
	shProgram.SetUniformf("LightColor", LightColor.x, LightColor.y, LightColor.z);
	shProgram.SetUniformf("LightPosition", 0.0f, 1.0f, 10.0f);
	shProgram.SetUniformi("DiffuseTexture", 0);
	shProgram.Deactivate();
}

void GameLoop() {

	//Limpiamos el buffer de color y el buffer de profundidad
	//Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Gira en 3D
	//std::cout << geometria.GetPosition().x + geometria.GetPosition().y + geometria.GetPosition().z;
	geometria.Rotate(0, 0.01f, 0,false);
	
	shProgramPuerco.Activate();
	shProgramPuerco.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * geometria.GetModelMatrix());
	shProgramPuerco.SetUniformf("CameraPosition", _camera.GetPosition().x, _camera.GetPosition().y, _camera.GetPosition().z);
	shProgramPuerco.SetUniformMatrix("modelMatrix", geometria.GetModelMatrix());
	
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Bind();
	mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture3.Unbind();
	shProgramPuerco.Deactivate();

	shProgram.Activate();
	shProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * geometria2.GetModelMatrix());
	shProgram.SetUniformMatrix("modelMatrix", geometria2.GetModelMatrix());
	glActiveTexture(GL_TEXTURE0);
	myTexture2.Bind();
	mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture2.Unbind();
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
	
	//Para configurar un uniform, tenemos que decirle a OpenGL, que vamos a utilizar el
	//shader program (manager)

}

int main(int argc, char * argv[]) {

	//Inicializar freeglut.
	//Freeglut se encarga de crear una ventana para dibujar.
	glutInit(&argc, argv);

	// Inicializar DevIL. Esto se debe hacer sólo una vez.
	ilInit();
	// Cambiar el punto de origen de las texturas. Por default, DevIL
	// pone un punto de origen en la esquina superior izquierda.
	// Esto es compatible con el sistema operativo, pero no con el
	// funcionamiento de OpenGL.
	ilEnable(IL_ORIGIN_SET);
	// Configurar el punto de origen de las texturas en la esquina
	// inferior izquierda
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

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
	glClearColor(0.8f, 0.8f, 0.5f, 1.0f);

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