#pragma once
#include "Vehicle.h"

class Removable : public Vehicle {
protected:
	double perfomance;
	int reach;
public:
	Removable();

	void PrintAllInformation() override;

	void enterFromKeyboard() override;

	void readFromFile(char* path) override;
	void writeToFile(string) override;
};