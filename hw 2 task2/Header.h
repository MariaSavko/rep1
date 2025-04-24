#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
	vector<double> coef;
	vector<int> expon;

public:
	Polynomial(int degree, double* A);
	Polynomial(int degree);
	Polynomial(const Polynomial& p);
	~Polynomial();

	double get_degree() const { return expon.size(); };
	double get_coef(int index) const;
	void set_coef(int index, double new_coef);
	void reset(int degree, double* coef);
	void print();
	double calculate(double x);
};
Polynomial addition(const Polynomial& p1, const Polynomial& p2);
Polynomial substraction(const Polynomial& p1, const Polynomial& p2);

class VectPolynomial {
private:
	vector<Polynomial> polynoms;

public:
	VectPolynomial(Polynomial& p);
	VectPolynomial(const VectPolynomial& vp);
	~VectPolynomial();

	int Get_number_of_polynomials() { return polynoms.size(); };

	Polynomial& Polynomial_at(int index);
	void Add_polynomial(Polynomial& p) { polynoms.push_back(p); };
	void Remove_polynomial_at(int index);

	void Print();
};
