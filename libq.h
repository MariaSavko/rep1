#pragma once

class Quaternion
{
private:
	double a, b, c,d;

public:
	Quaternion();
	Quaternion(const Quaternion& q);
	Quaternion(double a, double b, double c, double d);
	~Quaternion();
	void Getter(double& a, double& b, double& c, double& d);
	void Setter(double a, double b, double c, double d);
	void Print_q();
	double Count_q();
	void Print_q1();
	double Norm();
	double Count_unq();
	Quaternion Sumq(Quaternion(q4), Quaternion(q5));
	double minus(Quaternion(q4), Quaternion(q5));
	double mul(Quaternion(q4), Quaternion(q5));
	/*double del(Quaternion(q4), Quaternion(q5));*/
	double evkl(Quaternion(q4), Quaternion(q5));
	double norm_of_chebush(Quaternion(q4), Quaternion(q5));



};
