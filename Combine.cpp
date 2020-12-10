#include "Combine.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

Combine::Combine() {
	capacity = 0;
}

void Combine::PrintAllInformation() {
	Engine::PrintAllInformation();
	cout << "Ёмкость: " << capacity << endl;
	for (int i = 0; i < 45; i++) {
		cout << "_";
	}
	cout << endl;
}



void Combine::enterFromKeyboard() {
	Engine::enterFromKeyboard();
	cout << "Ёмкость - ";
	cin >> capacity;
}

void Combine::readFromFile(char *path) {
	ifstream file(path);
	file >> name;
	file >> brand;
	file >> price;
	file >> engine_name;
	file >> gears_count;
	file >> max_speed;
	file >> capacity;
	file.close();
}

void Combine::writeToFile(string path) {
	ofstream file(path);
	file << name << endl;
	file << brand << endl;
	file << price << endl;
	file << engine_name << endl;
	file << gears_count << endl;
	file << max_speed << endl;
	file << capacity << endl;
	file.close();
}
