#pragma once
#include "Vehicle.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

class Engine : public Vehicle {
protected:
	string engine_name;
	int gears_count;
	int max_speed;
public:

	//Конструкторы
	Engine();

	//Вывод информации
	void PrintAllInformation() override;
	

	//Работа с файлами
	void readFromFile(char* path) override;

	void writeToFile(string path) override;
	
	 //Вывод в консоль
	void enterFromKeyboard() override;
};