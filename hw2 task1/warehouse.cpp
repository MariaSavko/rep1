#include <iostream>
#include "libware.h"
#include <cstring>
#include <cmath>

using namespace std;

//идентификатор - строка из 4 символов
int Warehouse::count = 100;

void Warehouse::generate_id() {
	sprintf_s(this->id, "W%03d", count);
	count++;
}




//конструктор по умолчанию
Warehouse::Warehouse() {
	generate_id();
	this->type_wareh = center;
	this->longitude = 0;
	this->latitude = 0;
	this->maxCapacity = 0;
	this->totalStock = 0;
	this->amount = 0;
	this->products = nullptr;
}
//конструктор по парметрам
Warehouse::Warehouse(type type_wareh, double longitude, double latitude, int maxCapacity, int totalStock, int amount) {
	generate_id();
	this->type_wareh = type_wareh;
	this->longitude = longitude;
	this->latitude = latitude;
	this->maxCapacity = maxCapacity;
	this->totalStock = totalStock;
	this->amount = amount;
	this->products = new Product[maxCapacity];
}

//конструктор по копии
Warehouse::Warehouse(const Warehouse& w) {
	generate_id();
	this->type_wareh = w.type_wareh;
	this->longitude = w.longitude;
	this->latitude = w.latitude;
	this->maxCapacity = w.maxCapacity;
	this->totalStock = w.totalStock;
	this->amount = w.amount;
	this->products = new Product[w.maxCapacity];//выделяет новый динамический массив для товаров (Product) размером w.amount (количество товаров в исходном складе).

	for (int i = 0; i < w.amount; i++) {
		this->products[i] = w.products[i]; //копирует каждый товар из исходного склада (w.products[i]) в новый массив (this->products[i]).
	
	}

}

//деструктор
Warehouse::~Warehouse() {
	delete[] this->products;
	
}


//сеттеры
void Warehouse::set_type(type type_wareh) {
	this->type_wareh = type_wareh; 
}

void Warehouse::set_lat(double lat) {
	this->latitude = lat;
}
void Warehouse::set_long(double lon) {
	this->longitude = lon;
}
void Warehouse::set_maxCap(int maxCapacity) { 
	this->maxCapacity = maxCapacity; 
}
void Warehouse::set_stock(int totalStock) { 
	this->totalStock = totalStock; 
}
void Warehouse::set_amount(int amount) { 
	this->amount = amount; 
}


//геттеры
const char *Warehouse::get_id() { return this->id; }
type Warehouse::get_type() { return this->type_wareh; }
double Warehouse::get_long() { return this->longitude; }
double Warehouse::get_lat() { return this->latitude; }
int Warehouse::get_maxCap() { return this->maxCapacity; }
int Warehouse::get_stock() { return this->totalStock; }
//const Product* Warehouse::get_prod(int pos) { return this->products[pos]; } //Возвращает товар из списка склада по позиции pos.pos — индекс товара в списке products.
Product Warehouse::get_prod(int pos) { 
        return this->products[pos];
 }
int Warehouse::get_amount() {
	return this->amount;
}
//расстояние до манхеттена
double Warehouse::calc_d(double landlong, double landlat) {
	cout << "Manhatten distance: ";
	return (abs(this->longitude - landlong) + abs(this->latitude - landlat));
}

//menu
void Warehouse::menu(int& op) {
	cout << left; //выравниваниe текста по левому краю
	cout << "-----------------" << endl;
	cout << "MENU" << endl;
	cout << "-----------------" << endl;
	cout << "1. Добавить продукт" << endl;
	cout << "2. Поиск по названию" << endl;
	cout << "3. Удалить продукт" << endl;
	cout << "4. Распечать" << endl;
	cout << "5. Выйти" << endl;
	cout << "-----------------" << endl;
	cout << "Выберите опцию: ";
	cin >> op;
}

void Warehouse::ins_product() {
	if (amount >= maxCapacity) {
		cout << "Нет места на складе" << endl;
		return;
	}
	cout << "Insert new product..." << endl;
	cout << "Name: ";
	char name[50];
	cin >> name;
	this->products[this->amount].set_descript(name);
	//имя продукта
	//штрихкод
	this->products[this->amount].generate_barcode();

	do {
		cout << "Price: ";
		double price;
		cin >> price;
		this->products[this->amount].set_price(price);
	} while (this->products[this->amount].get_quantity() <= 0);
	//количество
	do {
		int quantity;
		cout << "Quantity: ";
		cin >> quantity;
		this->products[this->amount].set_quantity(quantity);
	} while (this->products[this->amount].get_quantity() < 0);
	do {
		double longi;
		cout << "Longitude: ";
		cin >> longi;
		this->products[this->amount].set_landLong(longi);
	} while ((this->products[this->amount].get_landLong() < 19) || (this->products[this->amount].get_landLong() > 169));
	do {
		double lat;
		cout << "Latitude: ";
		cin >> lat;
		this->products[this->amount].set_landLat(lat);
	} while ((this->products[this->amount].get_landLat() < 41) || (this->products[this->amount].get_landLat() > 82));

	this->totalStock += this->products[this->amount].get_quantity();
	this->set_stock(this->totalStock);
	//увеличиваем количество продуктов на складе
	this->amount++;
	this->set_amount(this->amount);

	cout << "Продукт добавлен на склад" << endl;
}


int Warehouse::find_prod() {
	int pos;
	cout << "Поиск по названию: ";
	char name[50];
	cin >> name;
	for (int i = 0; i < this->get_amount(); i++) {
		//сравниваем названия
		if (strcmp(this->products[i].get_descript(), name)==0) {
			pos = i;
			return pos;
		}
	}
	return -1; //продукт не найден
}

void Warehouse::del_product() {
	int pos = this->find_prod();
	if (pos != -1) {
		
		for (int i = pos; i < get_amount() - 1; i++)
			products[i] = products[i + 1];
		this->amount--;
		this->set_amount(this->amount);
		cout << "Продукт удален" << endl;
	
	}
	else {
		cout << "Продукт не найден" << endl;
	}
}



//вывод информации о всех продуктах на склдае
void Warehouse::print_product() {
	for (int i = 0; i < get_amount(); i++) {
		this->products[i].print();
	}
}

