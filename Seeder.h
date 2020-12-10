#pragma once
#include "Removable.h"

class Seeder : public Removable {
protected:
	string seeds_type;
public:
	Seeder();

	void PrintAllInformation() override;

	void readFromFile(char* path) override;
	void writeToFile(string path) override;

	void enterFromKeyboard() override;
};