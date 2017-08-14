/*************************************************
/  Materia: Gráficas computacionales
/
/  Autor: Brandon Alain Cruz Ruiz  A01375640
/
/  Fecha: 14 de Agosto del 2017
/
/  Actividad 4 - Employee.h
/
/*************************************************/

#pragma once
#include <string>

class Employee {
public:
	Employee(int _id, std::string firstName, std::string lastName, int salary);
	int GetID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetName();
	int GetSalary();
	void SetSalary(int salary);
	int GetAnnualSalary();
	int RaiseSalary(int percent);
	std::string Print();
private:
	int _id;
	std::string _firstName;
	std::string _lastName;
	int _salary;
};