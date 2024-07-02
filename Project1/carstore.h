#ifndef CARSTORE_H
#define CARSTORE_H

#include <string>
#include <fstream>
#include "Cars.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;


class carstore {
private:
	int max_num_ocars;
	int max_num_tcars;
	int num_ocars;
	int num_tcars;
	CarC* ocars;
	secondhand_car* tcars;

public:
	carstore(int max_oc, int max_tc);
	~carstore();

	void operator +=(const CarC& ocar);
	void operator +=(const secondhand_car& tcar);

	friend ostream& operator<<(ostream& stream, const carstore& astore);


	void add_car(CarC aCarC);

	void read_ocars_from_file(std::string filename);
	void read_tcars_from_file(std::string filename);

	void write_ocars_to_file(std::string filename);
	void write_tcars_to_file(std::string filename);

	void display_all();
	void find_car(string amodel);
	void CalculateAndPrintPowerToPriceRatio();
	void AddCarsByUser(char auserchoice);
	void PrintTrimsForModel(string àmodelToSearch);
};


#endif
