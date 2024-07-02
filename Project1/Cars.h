#ifndef CARS_H
#define CARS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;


class CarC {
private:
    std::string brand;
    std::string model;
    std::string trim;
    std::string segment;
    std::string body;
    double engineVolume;
    int enginePower;
    int year;
    int price;
public:
    CarC() : brand(""), model(""), trim(""), segment(""), body(""), engineVolume(0.0), enginePower(0), year(0), price(0) {};
    CarC(string, string, string, string, string, double, int, int, int);
    string get_model();
    void read_from(ifstream& file);
    void write_to(ofstream& file);
    void SetBrand(const std::string& newBrand);
    void SetModel(const std::string& newModel);
    void SetTrim(const std::string& newTrim);
    void SetSegment(const std::string& newSegment);
    void SetBody(const std::string& newBody);
    void SetVolume(const double& newVolume);
    void SetPower(const int& newPower);
    void SetYear(const int& newYear);
    void SetPrice(const int& newPrice);
    std::string GetBrand();
    std::string GetModel();
    std::string GetTrim();
    std::string GetSegment();
    std::string GetBody();
    double GetengineVolume();
    int GetenginePower();
    int GetYear();
    int GetPrice();

    friend bool operator ==(CarC CarC1, CarC CarC2);
    friend ostream& operator<<(ostream& stream, const CarC& acar);
    friend istream& operator>>(istream& stream, CarC& acar);
    friend ofstream& operator<<(ofstream& stream, const CarC& acar);
    friend ifstream& operator>>(ifstream& stream, CarC& acar);

};

class secondhand_car : public CarC
{
private:
    string originalcolour;
    string replacedparts;
public:
    secondhand_car() : CarC(), originalcolour(""), replacedparts("") {};
    secondhand_car(string, string, string, string, string, double, int, int, int, string, string);

    friend bool operator ==(secondhand_car CarC1, secondhand_car CarC2);
    friend ostream& operator<<(ostream& stream, const secondhand_car& acar);
    friend istream& operator>>(istream& stream, secondhand_car& acar);
    friend ofstream& operator<<(ofstream& stream, const secondhand_car& acar);
    friend ifstream& operator>>(ifstream& stream, secondhand_car& acar);
};

#endif