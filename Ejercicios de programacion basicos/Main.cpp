//Brandon Alain Cruz Ruiz
//A01375640
//Tarea - Ejercicios de programación básicos.pdf

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
	
	FlechaEstrellas(3);
	std::cin.get();
	return 0;
}


