#include "Removable.h"


void Removable::writeToFile(string path) {
	ofstream file(path);
	file << name << endl;
	file << brand<< endl;
	file << price << endl;
	file << perfomance << endl;
	file << reach << endl;
	file.close();
}

void Removable::readFromFile(char* path) {
	ifstream file(path);
	file >> name;
	file >> brand;
	file >> price;
	file >> perfomance;
	file >> reach;
	file.close();
}

Removable::Removable() {
	perfomance = 0;
	reach = 0;
}

void Removable::PrintAllInformation() {
	Vehicle::PrintAllInformation();
	cout << "������������������: " << perfomance << endl;
	cout << "�����: " << reach << endl;
}

void Removable::enterFromKeyboard() {
	Vehicle::enterFromKeyboard();
	cout << "������������������ - ";
	cin >> perfomance;
	cout << "����� - ";
	cin >> reach;
}