#include <iostream>
#include <cmath>
#include "libq.h"

using namespace std;
Quaternion::Quaternion() {
	a = 1;
	b = 0;
	c = 0;
	d = 0;
}
Quaternion::Quaternion(double a, double b, double c, double d) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
};
Quaternion::Quaternion(const Quaternion &q)
{
	a = q.a;
	b = q.b;
	c = q.c;
	d = q.d;
}
Quaternion::~Quaternion(){}

void Quaternion::Getter(double &a, double &b, double &c, double &d ) {
	a = this->a;
	b = this->b;
	c = this->c;
	d = this->d;
}

void Quaternion::Setter(double a, double b, double c, double d) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

void Quaternion::Print_q() {
	cout << "q = " << a << " + " << b << "i" << " + " << c << "j" << " + " << d << " k ";
}

double Quaternion::Count_q() {
	double q1 = sqrt(a * a + b * b + c * c + d*d);
	return q1;
}

void Quaternion::Print_q1() {
	cout << "q = " << a << " - " << b << "i" << " - " << c << "j" << " - " << d << " k ";
}

double Quaternion::Norm() {
	double qm = sqrt(a * a + b * b + c * c + d * d);
	double q2 = a / qm + b / qm + c / qm + d / qm;
	return q2;
}

double Quaternion::Count_unq() {
	double qm2 = a * a + b * b + c * c + d * d;
	double q3 = a / qm2 - b / qm2 - c / qm2 - d / qm2;
	return q3;
}

Quaternion Quaternion::Sumq(Quaternion(q4), Quaternion(q5)) {
	return Quaternion(q4.a + q5.a, q4.b + q5.b, q4.c + q5.c, q4.d + q5.d);
}

double Quaternion::minus(Quaternion(q4), Quaternion(q5)) {
	double mina = q4.a - q5.a;
	double minb = q4.b - q5.b;
	double minc = q4.c - q5.c;
	double mind = q4.d - q5.d;
	return mina, minb, minc, mind;
}

double Quaternion::mul(Quaternion(q4), Quaternion(q5)) {
	double mula = ((q4.a * q5.a - q4.b * q5.b - q4.c * q5.c - q4.d * q5.d, q4.a * q5.b + q4.b * q5.a + q4.c * q5.d - q4.d * q5.c, q4.a * q5.c + q4.c * q5.a + q4.d * q5.b - q4.b * q5.d, q4.a * q5.d + q4.d * q5.a + q4.b * q5.c - q4.c * q5.b));
	return mula;
}

/*double Quaternion::del(Quaternion(q4), Quaternion(q5)) {
	double del1 = 
}
*/

double Quaternion::evkl(Quaternion(q4), Quaternion(q5)) {
	return sqrt(pow(q4.a - q5.a, 2) + pow(q4.b - q5.b, 2) + pow(q4.c - q5.c, 2) + pow(q4.d - q5.d, 2));
}

double Quaternion::norm_of_chebush(Quaternion(q4), Quaternion(q5)) {
	double max1 = -1;
	double arr[4] = { abs(q4.a - q5.a), abs(q4.b - q5.b), abs(q4.c - q5.c) , abs(q4.d - q5.d) };
	for (int i = 0; i < 4; i++) {
		if (arr[i] > max1) {
			max1 = arr[i];
		}
	}
	return max1;
}