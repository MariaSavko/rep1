#include <iostream>
#include "libprod.h"
#include <cstring>

using namespace std;

void Product::validate(double price, int quantity, double landLat, double landLong) {
	if (price < 0) {
		this->price = 0;
	}
	if (quantity < 0) {
		this->quantity= 0;
	}
	if (landLat < 41 || landLong>82) {
		this->landLat = 0;
	}
	if (landLong < 19 || landLong > 169) {
		this->landLong = 0;
	}
}

void Product::generate_barcode() {
	const char *part1 = "460";
	int part2 = (rand() % 9 + 1) * 1000;
	int part3 = rand() % 1000000;
	sprintf_s(this->barcode, "%s%04d%06d", part1, part2, part3);
}

Product::Product() {
	generate_barcode();
	strcpy_s(this->description, "");
	this->price = 0;
	this->quantity = 0;
	this->landLong = 0;
	this->landLat = 0;
	validate(this->price, this->quantity, this->landLat, this->landLong);

}

Product::Product(char description[50], double price, int quantity, double landLong, double landLat) {
	generate_barcode();
	strcpy_s(this->description, description);
	this->price = price;
	this->quantity = quantity;
	this->landLong = landLong;
	this->landLat = landLat;
	validate(this->price, this->quantity, this->landLat, this->landLong);
}

Product::Product(const Product &p) {
	generate_barcode();
	strcpy_s(this->description, p.description);
	this->price = p.price;
	this->quantity = p.quantity;
	this->landLong = p.landLong;
	this->landLat = p.landLat;
	validate(this->price, this->quantity, this->landLat, this->landLong);
}

Product::~Product() {}

void Product::set_descript(const char *description) {
	strcpy_s(this->description, description);
}

void Product::set_price(double price) {
	this->price = price;
}

void Product::set_quantity(int quan) {
	this->quantity = quan;
}

void Product::set_landLong(double landLong) {
	this->landLong = landLong;
}
void Product::set_landLat(double landLat) {
	this->landLat = landLat;
}

const char *Product::get_barcode() {
	return this->barcode;
}
const char *Product::get_descript() {
	return this->description;
}
double Product::get_price() {
	return this->price;
}
int Product::get_quantity() {
	return this->quantity;
}
double Product::get_landLong() {
	return this->landLong;
}
double Product::get_landLat() {
	return this->landLat;
}

void Product::print() {
	cout << "--- Информация о продукте ---" << endl;
	cout << "Штрих-код: " << this->barcode << endl;
	cout << "Название: " << this->description << endl;
	cout << "Цена: " << this->price << " руб." << endl;
	cout << "Количество: " << this->quantity << " шт." << endl;
	cout << "Координаты доставки: " << endl;
	cout << "  Долгота: " << this->landLong << endl;
	cout << "  Широта: " << this->landLat << endl;
	cout << "-----------------------------" << endl;
}
