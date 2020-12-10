#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "IVehicle.h"

using namespace std;

class Vehicle : public IVehicle {
protected:
	int price;
	string name;
	string brand;
public:

	//Конструктор
	Vehicle();

	
	//Вывод информации в консоль
	void PrintAllInformation() override;

	//Геттеры
	int GetPrice() const override;

	string GetName() const override;

	string GetBrand() const override;


	//Сеттеры
	void SetPrice(int Price) override;

	void SetName(string Name) override;

	void SetBrand(string Brand) override;


	
	//Работа с файлами
	void readFromFile(char* path) override;

	void writeToFile(string path) override;


	//Ввод с клавиатуры
	void enterFromKeyboard() override;
};

