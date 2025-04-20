#pragma once

#include "libprod.h"

enum  type{center,east,west};

//определение класса
class Warehouse {
	private: //„лены класса доступны внутри самого класса, но не доступны извне
		char id[5];
		static int count; //один счЄтчик на все склады
		type type_wareh;
		double longitude;
		double latitude;
		int maxCapacity;
		int totalStock;
		int amount;
		Product* products; 
		void generate_id();

	public:
		//конструкторы
		Warehouse();
		Warehouse(type type_wareh, double lon, double lat, int maxCap, int totalStock, int amount);

		Warehouse(const Warehouse &w);
		~Warehouse();
		
		//геттеры
		const char *get_id();
		type get_type();
		double get_long();
		double get_lat();
		int get_maxCap();
		int get_stock();
		int get_amount();

		//сеттеры
		void set_type(type type_wareh);
		void set_long(double longitude);
		void set_lat(double latitude);
		void set_maxCap(int maxCap);
		void set_stock(int totalStock);
		void set_amount(int amount);
		

		double calc_d(double landLong, double landLat);
		void menu(int& op);
		void ins_product();
		void del_product();
		Product get_prod(int pos);
		void print_product();
		int find_prod();
		
	
};