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



//Вывод информации в консоль.
void Engine::PrintAllInformation() {
	Vehicle::PrintAllInformation();
	cout << "Двигатель: " << engine_name << endl;
	cout << "Количество передач: " << gears_count << endl;
	cout << "Максимальная скорость: " << max_speed << endl;
}

//работа с файлами.
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
	cout << "Двигатель - ";
	cin >> engine_name;
	cout << "Количество передач - ";
	cin >> gears_count;
	cout << "Максимальная скорость - ";
	cin >> max_speed;
}

