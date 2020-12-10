#include "Seeder.h"

Seeder::Seeder() {
	seeds_type = "Empty";
}

void Seeder::PrintAllInformation() {
	Removable::PrintAllInformation();
	cout << "Тип семян: " << seeds_type << endl;

	for (int i = 0; i < 45; i++) {
		cout << "_";
	}
	cout << endl;
}

void Seeder::enterFromKeyboard() {
	Removable::enterFromKeyboard();
	cout << "Тип семян - ";
	cin >> seeds_type;
}

void Seeder::writeToFile(string path) {
	ofstream file(path);
	file << name << endl;
	file << brand << endl;
	file << price << endl;
	file << perfomance << endl;
	file << reach << endl;
	file << seeds_type << endl;
	file.close();
}

void Seeder::readFromFile(char* path) {
	ifstream file(path);
	file >> name;
	file >> brand;
	file >> price;
	file >> perfomance;
	file >> reach;
	file >> seeds_type;
	file.close();
}