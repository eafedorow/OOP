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
	//������������
	Combine();


	//����� ����������
	void PrintAllInformation() override;


	//������ � �������.
	void readFromFile(char* path) override;
	void writeToFile(string) override;

	//����� ���������� � �������
	void enterFromKeyboard() override;

};