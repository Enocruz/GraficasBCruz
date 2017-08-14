#pragma once

#include <string>

class Circle {
public:
	Circle();
	Circle(double r);
	Circle(double r, std::string c);

	double getArea();
	double getRadius();
	std::string getColor();

	void setRadius(double r);
	void setColor(std::string c);



private:
	double _radius;
	std::string _color;

};