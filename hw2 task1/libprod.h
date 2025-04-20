#pragma once


class Product {
	private:
		char barcode[14];
		char description[50];
		double price;
		int quantity;
		double landLong;
		double landLat;

	public:
		Product();
		Product(char description[50], double price, int quantity, double landLong, double landLat);
		Product(const Product &p);
		~Product();

		void generate_barcode();
		void validate(double price, int amount, double latitude, double longitude);

		//сеттеры
		void set_descript(const char *descript);
		void set_price(double price);
		void set_quantity(int amount);
		void set_landLong(double landLong);
		void set_landLat(double landLat);

		//геттеры
		const char *get_barcode();
		const char *get_descript();
		double get_price();
		int get_quantity();
		double get_landLong();
		double get_landLat();
	
		void print();

};