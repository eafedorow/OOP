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

	//������������
	Engine();

	//����� ����������
	void PrintAllInformation() override;
	

	//������ � �������
	void readFromFile(char* path) override;

	void writeToFile(string path) override;
	
	 //����� � �������
	void enterFromKeyboard() override;
};