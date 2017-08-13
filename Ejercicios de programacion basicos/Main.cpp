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


