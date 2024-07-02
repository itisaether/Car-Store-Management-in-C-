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
	cout << "�� ������ �������� ��� ������? (y/n): ";
	cin >> UserChoice;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	my_store.AddCarsByUser(UserChoice);
	my_store.CalculateAndPrintPowerToPriceRatio();

	cout << "\n\n������� ������, ����� ����� � ������������ � ������� ����������� ���������: ";
	getline(cin, modelToSearch);

	my_store.PrintTrimsForModel(modelToSearch);
}