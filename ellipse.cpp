#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "libellipse.h"



using namespace std;

//конструктор по умолчанию
Ellipse::Ellipse() {
	this->h = 0;
	this->k = 0;
	this->a = 2;
	this->b = 1;
}

//конструктор с параметрами
Ellipse::Ellipse(double h, double k, double a, double b) {
	set_h(h);
	set_k(k);
	set_a(a);
	set_b(b);
	if (a <= b) {
		cout << "Ошибка. Малая полуось не должна быть больше большой. Введите другие числа" << endl;
		cin >> a >> b;

		set_a(a);
		set_b(b);

	}
}
//constsuct by object copy with reference
Ellipse::Ellipse(const Ellipse &e) {
	this->h = e.h;
	this->k = e.k;
	this->a = e.a;
	this->b = e.b;
}
//destructor
Ellipse::~Ellipse() {}

//setter for attribite h
void Ellipse::set_h(double h) {
	this->h = h;
}
//getter for attribute h
double Ellipse::get_h() {
	return this->h;
}

//setter for attribute k
void Ellipse::set_k(double k) {
	this->k = k;
}

//getter for attribute k
double Ellipse::get_k() {
	return this->k;
}

//setter for attribite a
void Ellipse::set_a(double a) {
	this->a = a;
}
//getter for attribute a
double Ellipse::get_a() {
	return this->a;
}

//setter for attribite b
void Ellipse::set_b(double b) {
	this->b = b;
}
//getter for attribute b
double Ellipse::get_b() {
	return this->b;
}
void Ellipse::calcV(double &v1x, double &v1y, double &v2x, double &v2y) {
	if (a >= b) { //для большой оси по X
		v1x = h - a;
		v1y = k;
		v2x = h + a;
		v2y = k;
	}
	else {
		v1x = h;
		v1y = k - a;
		v2x = h;
		v2y = k + a;
	}
}

void Ellipse::calcF(double &f1x, double &f1y, double &f2x, double &f2y) {
	double c = sqrt(a * a - b * b);
	if (a >= b) {
		f1x = h - c;
		f1y = k;
		f2x = h + c;
		f2y = k;
	}
	else {
		f1x = h;
		f1y = k - c;
		f2x = h;
		f2x = k + c;
	}

}

double Ellipse::calcC() {
	return sqrt(a * a - b * b);
}

double Ellipse::focalChord() {
	return (2 * b * b) / a;
}

double Ellipse::calcE() {
	return sqrt(a * a - b * b) / a;
}

double Ellipse::calcP() {
	return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

double Ellipse::calcS() {
	return M_PI * a * b;
}

int Ellipse::checkPoint(double x, double y) {
	double value = (x - h)*(x-h)/a*a + (y - k)*(y-k)/ b*b;
	if (value < 1) {
		return 0; //внутри эллипса 
	}
	else if (value == 1) {
		return 1; //на элипсе 
	}
	else return 2; //вне эллипса
}

double Ellipse::calcY(double x) {
	return k + b * sqrt(1 - pow((x - h), 2) / (a * a)); //выразила из какнонического уравнения эллипса
}
double Ellipse::calcX(double y) {
	return h + a * sqrt(1 - pow((y - k), 2) / (b * b));
}
void Ellipse::printEll() {
	cout << "Уравнение эллипса ( (x - " << h << ")^2/" << a * a << ") + (( y - " << k << ")^2/" << b * b << ")=1" << endl;
	cout << "Центр С (" << h << "," << k << ")" << endl;
	double v1x, v1y, v2x, v2y;
	calcV(v1x, v1y, v2x, v2y);
	cout << "Вершины V: (" << v1x << "," << v1y << "), (" << v2x << ", " << v2y << ")" << endl;

	double f1x, f1y, f2x, f2y;
	calcF(f1x, f1y, f2x, f2y);
	cout << "Фокусы (" << f1x << ", " << f1y << "), (" << f2x << ", " << f2y << ")" << endl;

}

