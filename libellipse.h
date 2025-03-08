#pragma once

class Ellipse {
	private:
		double h, k, a, b;

	public:
		Ellipse();

		Ellipse(double h, double k, double a, double b);

		Ellipse(const Ellipse& e); //конструктор копирования
		~Ellipse(); //деконструктор
		double calcC(); //функцию для вычисления гиперпараметра эллипсиса c,
		double focalChord(); //длина фокальной хорды 
		double calcE(); //эксцентриситет

		void calcV(double &v1x, double &v2x, double &v1y, double &v2y); //для вершин
		void calcF(double &f1x, double &f2x, double &f1y, double &f2y); //для фокусов

		//методы set get
		void set_h(double h);
		void set_k(double k);
		void set_a(double a);
		void set_b(double b);

		double get_h();
		double get_k();
		double get_a();
		double get_b();

		void printEll(); //процедуру для печати общего уравнения эллипса и их характерных точек

		int checkPoint(double x, double y); // функцию для проверки того, находится ли некоторая точка P(x, y) внутри, над или снаружи эллипса.

		double calcP(); //функци для вычисления периметра
		double calcS(); //функция для вычисления площади

		double calcY(double x); //вычисление второй координаты, когда дан X
		double calcX(double y); //вычисляем вторую координату когда дан Y



		
		
		



		
};