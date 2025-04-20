// homework2 task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//диграмма
/*
---------
Warehouse
---------
Атрибуты

id: string -----идентификатора
type: enum -----тип для определния категорий склада
longitude: double ------- долгота
latitude: double ------широта
maxCapacity: int ------- максимальное количество продуктов,
которые может хранить склад
totalStock: int ------- текущее общее количество продуктов, доступных на складе
products: vector<Product> -------вектор продуктов, хранящихся на складе.

Методы
Warehouse()
Warehouse(id, type, longitude, latitude, maxCapacity)
Warehouse(const Warehouse &w)
~Warehouse()
ins_product(Product) --------- вставка продуктов
del_product(Product) ---------  удаление продуктов
update_stock(int) ---------- обновить общий запас склада
find_product(string) -------  поиск продукта по описанию
calc_distance(double landLong, double landLat) ------- вычисляет расстояние между
координатами положения склада и координатами положения
транспортировки продукта



--------
Product
--------
Атрибуты

barcode: string
desription: string
price: double
quanity: int
landLong: double
landLat: double

Методы

Product() --- Конструктор по умолчанию
Product(barcode, description, price, quantity, landLong, landLat) ---- Конструктор с параметрами
Product(const Product &p) ------ Конструктор копирования
set_barcode(string) ------- установка значения поля штрих-кода
set_descript(string)
set_price(double)
set_quanity(int)
set_landLong(double)
set_landLat(double)
get_barcode() --------- для получения значения штрих-кода
get_descript()
get_price()
get_quanity()
get_landLong()
get_landLat()
print() --------для печати данных о продукте

*/
#include <iostream>
#include "libprod.h"
#include "libware.h"
#include <cstring>


using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Product apple;
    apple.set_descript("apple");
    apple.set_price(10);
    apple.set_quantity(389);
    apple.set_landLong(56.4);
    apple.set_landLat(64.3);


    apple.print();
    int opc;
    Warehouse w;
    w.set_type(center);
    w.set_lat(57);
    w.set_lat(64);
    w.set_amount(389);
    w.set_maxCap(900);
    w.set_stock(1);

    cout << "Расстояние до Манхеттена" << endl;
    cout << w.calc_d(apple.get_landLong(), apple.get_landLat()) << endl;


    do {
        w.menu(opc);
        switch (opc) {
        case 1:
            w.ins_product();
            break;
        case 2:
            int pos;
            pos = w.find_prod();
            if (pos != -1) {
                w.get_prod(pos).print();
            }
            else {
                cout << "Продукт не найден" << endl;
            }
            break;
        case 3:
            w.del_product();
            break;
        case 4:
            w.print_product();
            break;
        case 5:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Error" << endl;
        }

    } while (opc != 5);
return 0;

}


