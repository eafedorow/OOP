#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

class IVehicle
{
public:
	//Вывод информации.
	virtual void PrintAllInformation() = 0;

	//Геттеры.
	virtual int GetPrice() const = 0;
	virtual string GetName() const = 0;
	virtual string GetBrand() const = 0;

	//Сеттеры.
	virtual void SetPrice(int Price) = 0;
	virtual void SetName(string Name) = 0;
	virtual void SetBrand(string Brand) = 0;

	//Работа с файлами.
	virtual void readFromFile(char*) = 0;
	virtual void writeToFile(string) = 0;

	//Ввод с клавиатуры.
	virtual void enterFromKeyboard() = 0;

};