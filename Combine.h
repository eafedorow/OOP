#pragma once
#include "Engine.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
class Combine : public Engine {
protected:
	int capacity;
public:
	//Конструкторы
	Combine();


	//Вывод информации
	void PrintAllInformation() override;


	//Работа с файлами.
	void readFromFile(char* path) override;
	void writeToFile(string) override;

	//Вывод информации в консоль
	void enterFromKeyboard() override;

};