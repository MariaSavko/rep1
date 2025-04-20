#pragma once

#include "libprod.h"

enum  type{center,east,west};

//����������� ������
class Warehouse {
	private: //����� ������ �������� ������ ������ ������, �� �� �������� �����
		char id[5];
		static int count; //���� ������� �� ��� ������
		type type_wareh;
		double longitude;
		double latitude;
		int maxCapacity;
		int totalStock;
		int amount;
		Product* products; 
		void generate_id();

	public:
		//������������
		Warehouse();
		Warehouse(type type_wareh, double lon, double lat, int maxCap, int totalStock, int amount);

		Warehouse(const Warehouse &w);
		~Warehouse();
		
		//�������
		const char *get_id();
		type get_type();
		double get_long();
		double get_lat();
		int get_maxCap();
		int get_stock();
		int get_amount();

		//�������
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