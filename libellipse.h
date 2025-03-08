#pragma once

class Ellipse {
	private:
		double h, k, a, b;

	public:
		Ellipse();

		Ellipse(double h, double k, double a, double b);

		Ellipse(const Ellipse& e); //����������� �����������
		~Ellipse(); //�������������
		double calcC(); //������� ��� ���������� �������������� ��������� c,
		double focalChord(); //����� ��������� ����� 
		double calcE(); //��������������

		void calcV(double &v1x, double &v2x, double &v1y, double &v2y); //��� ������
		void calcF(double &f1x, double &f2x, double &f1y, double &f2y); //��� �������

		//������ set get
		void set_h(double h);
		void set_k(double k);
		void set_a(double a);
		void set_b(double b);

		double get_h();
		double get_k();
		double get_a();
		double get_b();

		void printEll(); //��������� ��� ������ ������ ��������� ������� � �� ����������� �����

		int checkPoint(double x, double y); // ������� ��� �������� ����, ��������� �� ��������� ����� P(x, y) ������, ��� ��� ������� �������.

		double calcP(); //������ ��� ���������� ���������
		double calcS(); //������� ��� ���������� �������

		double calcY(double x); //���������� ������ ����������, ����� ��� X
		double calcX(double y); //��������� ������ ���������� ����� ��� Y



		
		
		



		
};