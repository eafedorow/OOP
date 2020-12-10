#include "Mower.h"

Mower::Mower() {
	turnovers = 0;
}

void Mower::PrintAllInformation() {
	Removable::PrintAllInformation();
	cout << "Количество оборотов: " << turnovers << endl;
}

void Mower::enterFromKeyboard() {
	Removable::enterFromKeyboard();
	cout << "Количество оборотов - ";
	cin >> turnovers;
}

void Mower::writeToFile(string path) {
	ofstream file(path);
	file << name << endl;
	file << brand << endl;
	file << price << endl;
	file << perfomance << endl;
	file << reach << endl;
	file << turnovers << endl;
	file.close();
};

void Mower::readFromFile(char* path) {
	ifstream file(path);
	file >> name;
	file >> brand;
	file >> price;
	file >> perfomance;
	file >> reach;
	file >> turnovers;
	file.close();
}