#include "Cars.h"
#include <iostream>
#include <fstream>

using namespace std;

std::string CarC::GetBrand() {
	return brand;
}

std::string CarC::GetModel() {
	return model;
}

std::string CarC::GetSegment() {
	return segment;
}

std::string CarC::GetBody() {
	return body;
}

double CarC::GetengineVolume() {
	return engineVolume;
}

int CarC::GetenginePower() {
	return enginePower;
}

int CarC::GetYear() {
	return year;
}

int CarC::GetPrice() {
	return price;
}

std::string CarC::GetTrim() {
	return trim;
}

void CarC::SetBrand(const std::string& newBrand) {
	brand = newBrand;
}
void CarC::SetModel(const std::string& newModel) {
	model = newModel;
}
void CarC::SetTrim(const std::string& newTrim) {
	trim = newTrim;
}
void CarC::SetSegment(const std::string& newSegment) {
	segment = newSegment;
}
void CarC::SetBody(const std::string& newBody) {
	body = newBody;
}
void CarC::SetVolume(const double& newVolume) {
	engineVolume = newVolume;
}
void CarC::SetPower(const int& newPower) {
	enginePower = newPower;
}
void CarC::SetYear(const int& newYear) {
	year = newYear;
}
void CarC::SetPrice(const int& newPrice) {
	price = newPrice;
}

CarC::CarC(string br, string md, string tr, string sg, string bd, double eV, int eP, int yr, int pr)
{
	brand = br;
	model = md;
	trim = tr;
	segment = sg;
	body = bd;
	engineVolume = eV;
	enginePower = eP;
	year = yr;
	price = pr;
	cout << "\nВызван конструктор класса CarC";
}
string CarC::get_model()
{
	return model;
}

bool operator ==(CarC CarC1, CarC CarC2)
{
	if (CarC1.brand != CarC2.brand) return false;
	if (CarC1.model != CarC2.model) return false;
	if (CarC1.trim != CarC2.trim) return false;
	if (CarC1.segment != CarC2.segment) return false;
	if (CarC1.body != CarC2.body) return false;
	if (CarC1.engineVolume != CarC2.engineVolume) return false;
	if (CarC1.enginePower != CarC2.enginePower) return false;
	if (CarC1.year != CarC2.year) return false;
	return true;
}

ostream& operator<<(ostream& stream, const CarC& acar)
{
	stream << "===========================================\n";
	stream << " Бренд:                 " << acar.brand << std::endl;
	stream << " Модель:                " << acar.model << std::endl;
	stream << " Двигатель:             " << acar.trim << std::endl;
	stream << " Сегмент:               " << acar.segment << std::endl;
	stream << " Кузов:                 " << acar.body << std::endl;
	stream << " Объем двигателя:       " << acar.engineVolume << std::endl;
	stream << " Мощность двигателя:    " << acar.enginePower << std::endl;
	stream << " Год выпуска:           " << acar.year << std::endl;
	return stream;
}

istream& operator>>(istream& stream, CarC& acar) {
	getline(stream, acar.brand);
	getline(stream, acar.model);
	getline(stream, acar.trim);
	getline(stream, acar.segment);
	getline(stream, acar.body);
	stream >> acar.engineVolume;
	stream >> acar.enginePower;
	stream >> acar.year;
	stream.get();
	return stream;
}

ofstream& operator<<(ofstream& stream, const CarC& acar) {
	stream << acar.brand << endl;
	stream << acar.model << endl;
	stream << acar.trim << endl;
	stream << acar.segment << endl;
	stream << acar.body << endl;
	stream << acar.engineVolume << endl;
	stream << acar.enginePower << endl;
	stream << acar.year << endl;
	stream << acar.price << endl;
	return stream;
}

ifstream& operator>>(ifstream& stream, CarC& acar) {
	getline(stream, acar.brand);
	getline(stream, acar.model);
	getline(stream, acar.trim);
	getline(stream, acar.segment);
	getline(stream, acar.body);
	stream >> acar.engineVolume;
	stream >> acar.enginePower;
	stream >> acar.year;
	stream.get();
	return stream;
}


// Методы производного класса secondhand_car

secondhand_car::secondhand_car(string br, string md, string tr, string sg, string bd, double eV, int eP, int yr, int pr, string oc, string rp) 
	: CarC(br, md, tr, sg, bd, eV, eP, yr, pr), originalcolour(oc), replacedparts(rp)
{
	cout << "\nВызван конструктор класса secondhand_car";
}

bool operator ==(secondhand_car CarC1, secondhand_car CarC2)
{
	bool are_equal_cars = static_cast<CarC>(CarC1) == static_cast<CarC>(CarC2);
	bool are_equal_cas = CarC1.originalcolour == CarC2.originalcolour;
	bool are_equal_rps = CarC1.replacedparts == CarC2.replacedparts;
	if (are_equal_cars && are_equal_cas && are_equal_rps)
		return true;
	return false;
}

ostream& operator<<(ostream& stream, const secondhand_car& tcar)
{
	stream << static_cast<CarC>(tcar);
	stream << "Оригинальный цвет: " << tcar.originalcolour << endl;
	stream << "Замена деталей: " << tcar.replacedparts << endl;
	return stream;
}


ofstream& operator<<(ofstream& stream, const secondhand_car& tcar)
{
	stream << static_cast<CarC>(tcar) << endl;
	stream << tcar.originalcolour << endl;
	stream << tcar.replacedparts << endl;
	return stream;
}
