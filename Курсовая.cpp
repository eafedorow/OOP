// Курсовая.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "IVehicle.h"
#include "Vehicle.h"
#include "Exception.h"
#include "Vector.h"
#include "Engine.h"
#include "Combine.h"
#include "Tractor.h"
#include "Seeder.h"
#include "Mower.h"

using namespace std;

template <class T>
bool FinderByName(string Name, const T& obj) {
	if (Name ==	obj->GetName()) return true;
	return false;
}

template <class T>
bool FinderByBrand(string Brand, const T& obj) {
	if (Brand == obj->GetBrand()) return true;
	return false;
}

template <class T>
bool FinderByPriceBorder(int min, int max, const T& obj) {
	if (obj->GetPrice() >= min && obj->GetPrice() <= max) return true;
	return false;
}

template <class T>
bool SortByPrice(const T& obj1, const T& obj2) {
	if (obj1->GetPrice() > obj2->GetPrice()) return true;
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector<IVehicle*> vec;

	string searchname;
	int choose =-1;
	int choose_type = -1;
	int index = 0;
	int min, max;
	string temp;
	int tmp;
	while (choose != 0) {
		for (int i = 0; i < 45; i++) {
			cout << "_";
		}
		cout << endl;
		cout << "Выберите вариант действий:" << endl;
		cout << "1 - Добавить новый объект вручную." << endl;
		cout << "2 - Редактировать уже существующий объект." << endl;
		cout << "3 - Поиск объекта по определённым характеристикам." << endl;
		cout << "4 - Отобразить информацию об объектах." << endl;
		cout << "5 - Удалить объект." << endl;
		cout << "6 - Сортировка вектора по цене." << endl;
		cout << "7 - Работа с файлами." << endl;
		cout << "0 - Выход из программы" << endl;

		for (int i = 0; i < 45; i++) {
			cout << "_";
		}
		cout << endl;
		cout << "Ваш выбор - ";
		cin >> choose;
		try {
			switch (choose) {
			case 0:
				return 0;
			case 1:
				cout << "Выбор типа сельскохозяйственной техники:" << endl;
				cout << "С двигателем:" << endl;
				cout << "1 - Трактор" << endl;
				cout << "2 - Комбайн" << endl;
				cout << "Стационарные:" << endl;
				cout << "3 - Сеялка" << endl;
				cout << "4 - Косилка" << endl;
				cout << endl;
				cout << "Ваш выбор - ";

				cin >> choose_type;
				switch (choose_type) {
				case 1:
					vec.PushBack(new Tractor());
					cout << "Элемент #" << index << endl;
					vec[index]->enterFromKeyboard();
					index++;
					break;
				case 2:
					vec.PushBack(new Combine());
					cout << "Элемент #" << index << endl;
					vec[index]->enterFromKeyboard();
					index++;
					break;
				case 3:
					vec.PushBack(new Seeder());
					cout << "Элемент #" << index << endl;
					vec[index]->enterFromKeyboard();
					index++;
					break;
				case 4:
					vec.PushBack(new Mower());
					cout << "Элемент #" << index << endl;
					vec[index]->enterFromKeyboard();
					index++;
					break;
				}
				break;
			case 2:

				cout << "Введите индекс вектора для изменения - ";
				cin >> index;
				cout << "Существующая информация об объекте:" << endl;
				vec[index]->PrintAllInformation();
				cout << "Коректировка существующей информации:" << endl;
				vec[index]->enterFromKeyboard();
				break;
			case 3:
				cout << endl;
				cout << "Условия поиска:" << endl;
				cout << "1 - по диапозону цен." << endl;
				cout << "2 - по названию." << endl;
				cout << "3 - по производителю" << endl;
				cout << "Ваш выбор - ";
				cin >> choose_type;
				switch (choose_type) {
				case 1:
				{
					cout << endl;
					cout << "Минимальная цена - ";
					cin >> min;
					cout << "максимальная цена - ";
					cin >> max;
					Vector<IVehicle*>* for_search1 = vec.Search(min, max, FinderByPriceBorder);
					if (for_search1 == nullptr) cout << "Таких объетов не существует!" << endl;
					else {
						cout << "Объекты удовлетворяющие условию: " << endl;
						for (int i = 0; i < for_search1->Size(); i++) {
							cout << "#" << i << " " << (*for_search1)[i]->GetName() << endl;
						}
						delete for_search1;
					}
					break;
				}
				case 2:
				{
					cout << "Введите название - ";
					cin >> searchname;

					IVehicle** for_search2 = vec.SearchName(searchname, FinderByName);
					if (for_search2 == nullptr) cout << "Объектов удовлетворяющих условию не найдено" << endl;
					else {
						cout << "Объект удовлетворяющий условию:" << endl;
						(*for_search2)->PrintAllInformation();
					}
					break;
				}
				case 3: {
					cout << "Введите производителя - ";
					cin >> searchname;

					Vector<IVehicle*>* for_search3 = vec.SearchBrand(searchname, FinderByBrand);
					if (for_search3 == nullptr) cout << "Таких объетов не существует!" << endl;
					else {
						cout << "Объекты удовлетворяющие условию: " << endl;
						for (int i = 0; i < for_search3->Size(); i++) {
							cout << "#" << i << " " << (*for_search3)[i]->GetName() << endl;
						}
						delete for_search3;
					}
					break;
					break;
				}
				}
				break;
			case 4:
				cout << "О каком объекте необходимо вывести информацию?" << endl;
				cout << "1 - 1 объект(указать индекс объекта)." << endl;
				cout << "2 - вывести информацию о всех объектах." << endl;
				cout << "Ваш выбор - ";
				cin >> choose_type;
				switch (choose_type) {
				case 1:
					cout << "Введите индекс объекта - ";
					cin >> index;
					cout << endl;
					cout << "Объект под #" << index << endl;
					vec[index]->PrintAllInformation();
					break;
				case 2:
					cout << endl;
					if (vec.Size() == 0) {
						cout << "Вектор пуст!" << endl;
					}
					for (int i = 0; i < vec.Size(); i++) {
						cout << endl;
						cout << "Объект #" << i << endl;
						vec[i]->PrintAllInformation();
					}
					break;
				default:
					cout << "Такого варианта ответа не существует!" << endl;
					break;
				}
				break;
			case 5:
				cout << "Какой объект необходимо удалить?" << endl;
				cout << "1 - 1 объект(указать индекс объекта)." << endl;
				cout << "2 - удалить все объекты." << endl;
				cout << "Ваш выбор - ";
				cin >> choose_type;
				switch (choose_type) {
				case 1:
					cout << "Введите индекс объекта - ";
					cin >> index;
					cout << endl;
					vec.Erase(index);
					cout << "Объект под #" << index << " удалён!" << endl;
					break;
				case 2:
					cout << endl;
					for (int i = 0; i < vec.Size(); i++) {
						vec.Erase(i);
					}
					cout << "Вектор очищен!" << endl;
					break;
				default:
					cout << "Такого варианта ответа не существует!" << endl;
					break;
				}
				break;
			case 6:
				vec.ComparableSort(SortByPrice);
				cout << "Вектор отсортирован" << endl;
				break;
			case 7:
				cout << "Выберите действие:" << endl;
				cout << "1 - Запись в файл" << endl;
				cout << "2 - Чтение из файла" << endl;
				cout << "Ваш выбор - ";
				cin >> choose_type;
				switch (choose_type) {
				case 1: {
					string path;
					cout << "Введите индекс объекта, который хотите записать в файл - ";
					cin >> index;
					cout << "Путь для сохранения файла - ";
					cin >> path;

					vec[index]->writeToFile(path);
					break;
				}
				case 2: {
					cout << "Какой типа объект, записанный в файл?" << endl;
					cout << "1 - Трактор" << endl;
					cout << "2 - Комбайн" << endl;
					cout << "3 - Сеялка" << endl;
					cout << "4 - Косилка" << endl;
					cout << "Ваш выбор - ";
					cin >> choose_type;
					char* path1 = new char;
					cout << "Путь для чтения файла - ";
					cin >> path1;
					switch (choose_type) {
					case 1: {
						vec.PushBack(new Tractor());
						vec[vec.Size() - 1]->readFromFile(path1);
						cout << "Объект был записан в файл" << endl;
						break;
					}
					case 2: {
						vec.PushBack(new Combine());
						vec[vec.Size() - 1]->readFromFile(path1);
						cout << "Объект был записан в файл" << endl;
						break;
					}
					case 3: {
						vec.PushBack(new Seeder());
						vec[vec.Size() - 1]->readFromFile(path1);
						cout << "Объект был записан в файл" << endl;
						break;
					}
					case 4: {
						vec.PushBack(new Mower());
						vec[vec.Size() - 1]->readFromFile(path1);
						cout << "Объект был записан в файл" << endl;
						break;
					}
					}
				}
				}
				break;
			}
		}
		catch (Exception& ex) {
			cout << "|---------------ОШИБКА!--------------|" << endl;
			cout << ex.GetError() << endl;
			cout << "|------------------------------------|" << endl << endl;
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
