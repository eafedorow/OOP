#include "Engine.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

Engine::Engine() {
	engine_name = "Empty";
	gears_count = 0;
	max_speed = 0;
}



//����� ���������� � �������.
void Engine::PrintAllInformation() {
	Vehicle::PrintAllInformation();
	cout << "���������: " << engine_name << endl;
	cout << "���������� �������: " << gears_count << endl;
	cout << "������������ ��������: " << max_speed << endl;
}

//������ � �������.
void Engine::readFromFile(char* path)
{
	ifstream file(path);
	file >> name;
	file >> brand;
	file >> price;
	file >> engine_name;
	file >> gears_count;
	file >> max_speed;
	file.close();
}
void Engine::writeToFile(string path)
{
	ofstream file(path);
	file << name << endl;
	file << brand << endl;
	file << price << endl;
	file << engine_name << endl;
	file << gears_count << endl;
	file << max_speed << endl;
	file.close();
}

void Engine::enterFromKeyboard() {
	Vehicle::enterFromKeyboard();
	cout << "��������� - ";
	cin >> engine_name;
	cout << "���������� ������� - ";
	cin >> gears_count;
	cout << "������������ �������� - ";
	cin >> max_speed;
}

