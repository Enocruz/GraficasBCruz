/*************************************************
/  Materia: Gr�ficas computacionales
/
/  Autor: Brandon Alain Cruz Ruiz  A01375640
/
/  Fecha: 21 de Agosto del 2017
/
/  Tarea: Introducci�n a la programaci�n - InputFile.h
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
