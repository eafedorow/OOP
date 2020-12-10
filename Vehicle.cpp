#include "Vehicle.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;


//Конструкторы

Vehicle::Vehicle() {
	this->name = "Empty";
	this->brand = "Empty";
	this->price = 0;
}



void Vehicle::PrintAllInformation() {
	for (int i = 0; i < 45; i++) {
		cout << "_";
	}
	cout << endl;
	cout << "Название: " << name << endl;
	cout << "Производитель: " << brand << endl;
	cout << "Цена: " << price << endl;
}

//Геттеры

int Vehicle::GetPrice() const
{
	return price;
}

string Vehicle::GetName() const
{
	return name;
}

string Vehicle::GetBrand() const
{
	return brand;
}



//Сеттеры.

void Vehicle::SetPrice(int Price)
{
	price = Price;
}

void Vehicle::SetName(string Name)
{
	name = Name;
}

void Vehicle::SetBrand(string Brand) {
	brand = Brand;
}


//работа с файлами.
void Vehicle::readFromFile(char* path)
{
	ifstream file(path);
	string tmp;
	getline(file, tmp);
	name = tmp;
	getline(file, tmp);
	brand = tmp;
	file >> price;
	file.close();
}
void Vehicle::writeToFile(string path)
{
	ofstream file(path, std::ios::app);
	file << "Название: ";
	file << name << endl;
	file << "Производитель: ";
	file << brand << endl;
	file << "Цена: ";
	file << price << endl;
	file.close();
}


//Ввод с клавиатуры.
void Vehicle::enterFromKeyboard() {
	cout << "Введите название - ";
	cin >> name;
	cout << "Производитель - ";
	cin >> brand;
	cout << "Цена- ";
	cin >> price;
}