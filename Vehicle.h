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

	//�����������
	Vehicle();

	
	//����� ���������� � �������
	void PrintAllInformation() override;

	//�������
	int GetPrice() const override;

	string GetName() const override;

	string GetBrand() const override;


	//�������
	void SetPrice(int Price) override;

	void SetName(string Name) override;

	void SetBrand(string Brand) override;


	
	//������ � �������
	void readFromFile(char* path) override;

	void writeToFile(string path) override;


	//���� � ����������
	void enterFromKeyboard() override;
};

