#include "Header.h"
#include <cmath>


Polynomial::Polynomial(int degree, double* coef) {
	for (int i = 0; i < degree + 1; i++) {
		this->expon.push_back(i);
		this->coef.push_back(*(coef + i));
	}
}
Polynomial::Polynomial(int degree) {
	for (int i = 0; i < degree + 1; i++) {
		this->expon.push_back(i);
		this->coef.push_back(0);
	}
}
Polynomial::Polynomial(const Polynomial& p) {
	for (int i = 0; i < p.expon.size(); i++) {
		this->expon.push_back(i);
		this->coef.push_back(p.coef.at(i));
	}
}
Polynomial::~Polynomial() {

}

double Polynomial::get_coef(int index) const {
	if (index >= get_degree() || index < 0)
		return 0;
	return coef.at(index);
}
void Polynomial::set_coef(int index, double new_coef) {
	if (index < 0)
		return;

	while (index >= get_degree()) {
		expon.push_back(get_degree());
		coef.push_back(0);
	}

	coef.at(index) = new_coef;
}
void Polynomial::reset(int degree, double* coef) {
	this->expon.clear();
	this->coef.clear();

	for (int i = 0; i < degree + 1; i++) {
		this->expon.push_back(i);
		this->coef.push_back(*(coef + i));
	}
}
void Polynomial::print() {
	int n = expon.size();
	bool is_first_A_printed = false;

	for (int i = 0; i < n; i++) {
		double Ai = coef.at(i);

		if (Ai == 0)
			continue;

		if (is_first_A_printed) {
			if (Ai > 0) {
				cout << " + ";
			}
			if (Ai < 0) {
				cout << " - ";
				Ai *= -1;
			}
		}

		if (Ai != 1 || i == 0) {
			cout << Ai;
		}


		is_first_A_printed = true;

		if (i != 0)
			cout << "x";
		if (i > 1)
			cout << "^" << expon.at(i);
	}
	cout << endl;
}
double Polynomial::calculate(double x) {
	double output = get_coef(0);
	int n = get_degree() + 1;
	for (int i = 1; i < n; i++) {
		output += get_coef(i) * pow(x, i);
	}
	return output;
}

Polynomial addition(const Polynomial& p1, const Polynomial& p2) {
	int maxE = p1.get_degree() >= p2.get_degree() ? p2.get_degree() : p1.get_degree();
	Polynomial output(maxE);

	for (int i = 0; i < maxE + 1; i++) {
		output.set_coef(i, p1.get_coef(i) + p2.get_coef(i));
	}
	return output;
}
Polynomial substraction(const Polynomial& p1, const Polynomial& p2) {
	int maxE = p1.get_degree() >= p2.get_degree() ? p1.get_degree() : p2.get_degree();
	Polynomial output(maxE);

	for (int i = 0; i < maxE + 1; i++) {
		output.set_coef(i, p1.get_coef(i) - p2.get_coef(i));
	}
	return output;
}

VectPolynomial::VectPolynomial(Polynomial& p) {
	polynoms.push_back(p);
}
VectPolynomial::VectPolynomial(const VectPolynomial& vp) {
	for (int i = 0; i < polynoms.size(); i++) {
		polynoms.push_back(vp.polynoms.at(i));
	}
}
VectPolynomial::~VectPolynomial() {

}

Polynomial& VectPolynomial::Polynomial_at(int index) {
	if (index > Get_number_of_polynomials() - 1) {
		Polynomial PolynomialZero(0);
		return PolynomialZero;
	}
	return polynoms.at(index);
}
void VectPolynomial::Remove_polynomial_at(int index) {
	if (index < 0 || index > Get_number_of_polynomials() - 1)
		return;
	polynoms.erase(polynoms.begin() + index);
}

void VectPolynomial::Print() {
	for (int i = 0; i < Get_number_of_polynomials(); i++) {
		polynoms.at(i).print();
	}
}