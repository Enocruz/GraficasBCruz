/*************************************************
/  Materia: Gráficas computacionales
/
/  Autor: Brandon Alain Cruz Ruiz  A01375640
/
/  Fecha: 21 de Agosto del 2017
/
/  Tarea: Introducción a la programación - InputFile.h
/
/*************************************************/
#pragma once
#include <string>

class InputFile {
public:
	bool Read(std::string filename);
	std::string GetContents();
private:
	std::string _contents;
};
