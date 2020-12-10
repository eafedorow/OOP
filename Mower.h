#pragma once
#include "Removable.h"


class Mower : public Removable {
protected:
	int turnovers;
public:
	Mower();

	void PrintAllInformation() override;

	void writeToFile(string path) override;
	void readFromFile(char* path) override;

	void enterFromKeyboard() override;
};