#include "carstore.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <limits>

using namespace std;

string modelToSearch;

void main()
{
	setlocale(LC_ALL, "rus");

	carstore my_store(25, 10);

	char UserChoice;
	cout << "Вы хотите добавить ещё машины? (y/n): ";
	cin >> UserChoice;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	my_store.AddCarsByUser(UserChoice);
	my_store.CalculateAndPrintPowerToPriceRatio();

	cout << "\n\nВведите модель, чтобы найти её комплектации в порядке возрастания стоимости: ";
	getline(cin, modelToSearch);

	my_store.PrintTrimsForModel(modelToSearch);
}