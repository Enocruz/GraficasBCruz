/*************************************************
/  Materia: Gr�ficas computacionales
/
/  Autor: Brandon Alain Cruz Ruiz  A01375640
/
/  Fecha: 21 de Agosto del 2017
/
/  Tarea: Introducci�n a la programaci�n - InputFile.cpp
/
/*************************************************/

#include <iostream>
#include "InputFile.h"
#include <string>
#include <fstream>
#include <sstream>

//Variable controladora, mientras sea false GetContents regresar� una cadena vac�a
bool isFileOpened = false;

bool InputFile::Read(std::string filename) {
	//Declaramos la variable de tipo string que almacenar� cada l�nea del documento
	std::string line;
	//Declaramos la variable de tipo fstream
	std::fstream file;
	//Abrimos el archivo en modo lectura
	file.open(filename, std::ios::in);
	//Preguntamos si el archivo se abri� correctamente
	if (file.is_open()) {
		//La variable se vuelve true por lo que podemos utilizar GetContents
		isFileOpened = true;
		//Se lee cada l�nea del archivo
		while (std::getline(file, line))
		{	
			//Se concatena a la variable _contents
			InputFile::_contents += line+"\n";
		}
		//Se cierra el archivo
		file.close();
		return true;
	}
	return false;
}

std::string InputFile::GetContents() {
	if (isFileOpened == false) {
		InputFile::_contents = "";
	}
	return _contents;
}
/*
REFERENCIAS ACTIVIDAD 2
Para la lectura de archivos se visitaron los sitios web proporcionados en el documento pdf
Ejemplos:
http://www.cplusplus.com/doc/tutorial/files/
Clase fstream
http://www.cplusplus.com/reference/fstream/fstream/
Clase streamstring
http://www.cplusplus.com/reference/sstream/stringstream/
*/