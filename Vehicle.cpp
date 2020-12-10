#include "Vehicle.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;


//������������

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
	cout << "��������: " << name << endl;
	cout << "�������������: " << brand << endl;
	cout << "����: " << price << endl;
}

//�������

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



//�������.

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


//������ � �������.
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
	file << "��������: ";
	file << name << endl;
	file << "�������������: ";
	file << brand << endl;
	file << "����: ";
	file << price << endl;
	file.close();
}


//���� � ����������.
void Vehicle::enterFromKeyboard() {
	cout << "������� �������� - ";
	cin >> name;
	cout << "������������� - ";
	cin >> brand;
	cout << "����- ";
	cin >> price;
}