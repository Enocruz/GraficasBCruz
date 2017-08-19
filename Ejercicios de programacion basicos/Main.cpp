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

#include <iostream>
#include "InputFile.h"

int main() {
	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();
	std::cout << "Contents: " << contents << std::endl;
	std::cin.get();
	return 0;
}




/*
OPEN GL

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

void GameLoop() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Warning!! Esto es OpenGL antiguo. Sólo para efectos demostrativos.
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, -1.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);

	glEnd();

	glutSwapBuffers();
}

int main(int argc, char * argv[]) {

	//Inicializar freeglut.
	//Freeglut se encarga de crear una ventana para dibujar.
	glutInit(&argc, argv);

	//Inicia el contexto de OpenGL. El contexto se refiere a las capacidades que va a tener
	//nuestra aplicación gráfica. En este caso estamos trabajando con el pipeline clásico.
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

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

	//Inicializamos GLEW. Esta librería se encarga de obtener el API de OpenGl de nuestra
	//tarjeta de video.
	glewInit();

	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	//Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre la ventana.
	glutMainLoop();

	std::cin.get();
	return 0;
}

/*************************************************
/  Materia: Gráficas computacionales			
/
/  Autor: Brandon Alain Cruz Ruiz  A01375640
/
/  Fecha: 14 de Agosto del 2017
/
/  Tarea: Ejercicios de programación básicos.pdf
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
