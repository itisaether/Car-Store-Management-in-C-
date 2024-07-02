#include "cars.h" 
#include <fstream>
#include <iostream>
#include "carstore.h"

using namespace std;

carstore::carstore(int max_oc, int max_tc) {
    max_num_ocars = max_oc;
    max_num_ocars = max_tc;
    ocars = new CarC[max_oc];
    tcars = new secondhand_car[max_tc];
    num_ocars = 0;
    num_tcars = 0;
    cout << "\n������ ����������� ������ carstore:";
    cout << "\n �������� �������� (��� ����� �����) - " << max_num_ocars;
    cout << "\n �������� �������� (��� �/y �����) - " << max_num_tcars;
    cout << "\n ��������� ����� (�����) - " << num_ocars;
    cout << "\n ��������� ����� (�/�) - " << num_tcars;
    cout << endl;

}

carstore::~carstore() {
    cout << "\n������ ���������� ������ carstore:";
    max_num_ocars = 0;
    delete[] ocars;
    num_ocars = 0;

    max_num_tcars = 0;
    delete[] tcars;
    num_tcars = 0;
    cout << "\n ���������� ������ �����������";
}

void carstore::operator+=(const CarC& ocar)
{
    if (num_ocars < max_num_ocars)
    {
        ocars[num_ocars] = ocar;
        num_ocars++;
    }
}

void carstore::operator+=(const secondhand_car& tcar)
{
    if (num_tcars < max_num_tcars)
    {
        tcars[num_tcars] = tcar;
        num_tcars++;
    }
}


ostream& operator<<(ostream& stream, const carstore& astore)
{
    stream << "\n ���� ����������� ��������:\n";
    stream << "\n �) ����� ������\n";
    for (int i = 0; i < astore.num_ocars; i++)
    {
        stream << "=========== ������ " << i + 1 << " ============== \n";
        stream << astore.ocars[i] << endl;
    }
    stream << "\n �) �/� ������\n";
    for (int i = 0; i < astore.num_tcars; i++)
    {
        stream << "=========== ������ " << i + 1 << " ============== \n";
        stream << astore.tcars[i] << endl;
    }
    return stream;
}


void carstore::add_car(CarC aCarC) {
    if (num_ocars < max_num_ocars)
    {
        ocars[num_ocars] = aCarC;
        num_ocars++;
    }
}

void carstore::read_ocars_from_file(std::string filename) {
    std::ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        std::cout << "\n\n���� ������ �� ������!" << std::endl;
        system("pause");
        exit(1);
    }

    int N;
    infile >> N;
    infile.get();

    for (int i = 0; i < N; i++) {
        CarC new_car;
        new_car.read_from(infile);
        this->operator+=(new_car);
    }
    infile.close();

    std::cout << "\n��������� ������ �� ����� " << filename << ":";
    std::cout << "\n ����� ����������� ����� - " << num_ocars;

}

void carstore::read_tcars_from_file(std::string filename) {
    std::ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        std::cout << "\n\n���� ������ �� ������!" << std::endl;
        system("pause");
        exit(1);
    }

    int N;
    infile >> N;
    infile.get();

    for (int i = 0; i < N; i++) {
        CarC new_car;
        new_car.read_from(infile);
        this->operator+=(new_car);
    }
    infile.close();

    std::cout << "\n��������� ������ �� ����� " << filename << ":";
    std::cout << "\n ����� ����������� ����� - " << num_tcars;

}

void carstore::write_ocars_to_file(string filename) {

    ofstream outfile;
    outfile.open(filename);
    outfile << num_ocars << std::endl;
    for (int i = 0; i < num_ocars; i++)
        outfile << ocars[i];
    outfile.close();

    std::cout << "\n������ �������� � ���� " << filename << ":";
    std::cout << "\n ����� ���������� ����� - " << num_ocars;
}

void carstore::write_tcars_to_file(string filename) {

    ofstream outfile;
    outfile.open(filename);
    outfile << num_tcars << std::endl;
    for (int i = 0; i < num_tcars; i++)
        outfile << tcars[i];
    outfile.close();

    std::cout << "\n������ �������� � ���� " << filename << ":";
    std::cout << "\n ����� ���������� ����� - " << num_tcars;
}


void carstore::find_car(string amodel) {
    cout << "\n\n���� ������ � ������� \"" << amodel << "\"";
    bool found = false;
    for (int i = 0; i < num_ocars; i++)
    {
        if (ocars[i].get_model() == amodel)
        {
            found = true;
            cout << "\n������� ������:\n";
            cout << ocars[i];
        }
    }
    for (int i = 0; i < num_tcars; i++)
    {
        if (tcars[i].get_model() == amodel)
        {
            found = true;
            cout << "\n������� ������:\n";
        }
    }
    if (!found)
        cout << "\n������ � ����� ������� �� �������!\n";
}

void carstore::CalculateAndPrintPowerToPriceRatio() {
    double maxRatio = 0.0;
    std::string maxRatioModel = "";
    double CurrentRatio = 0.0;

    for (int i = 0; i < num_ocars; i++) {
        std::string CurrentModel = ocars[i].GetModel();
        double CurrentengineVolume = ocars[i].GetengineVolume();
        double CurrentPrice = ocars[i].GetPrice();

        CurrentRatio = CurrentengineVolume / CurrentPrice;

        std::cout << "����������� �������� ��������� � ��������� ��� ������ " << CurrentModel << ": " << CurrentRatio << std::endl;

        if (CurrentRatio > maxRatio) {
            maxRatio = CurrentRatio;
            maxRatioModel = CurrentModel;
        }
    }

    std::cout << "\n������ � ����� ������� ������������: " << maxRatioModel << std::endl;
}

void carstore::AddCarsByUser(char auserchoice) {
    while (auserchoice == 'y') {
        CarC newCar;
        cout << "������� �����: ";
        string brand;
        cin >> brand;
        newCar.SetBrand(brand);

        cout << "������� ������: ";
        string model;
        cin >> model;
        newCar.SetModel(model);

        cout << "������� ���������: ";
        string trim;
        cin >> trim;
        newCar.SetTrim(trim);

        cout << "������� �������: ";
        string segment;
        cin >> segment;
        newCar.SetSegment(segment);

        cout << "������� �����: ";
        string body;
        cin >> body;
        newCar.SetBody(body);

        cout << "������� ����� ���������: ";
        double engineVolume;
        cin >> engineVolume;
        newCar.SetVolume(engineVolume);

        cout << "������� �������� ���������: ";
        int enginePower;
        cin >> enginePower;
        newCar.SetPower(enginePower);

        cout << "������� ��� ������������: ";
        int year;
        cin >> year;
        newCar.SetYear(year);

        cout << "������� ���� ������: ";
        int price;
        cin >> price;
        newCar.SetPrice(price);

        CarC* temp = new CarC[num_ocars + 1];

        for (int i = 0; i < num_ocars; i++) {
            temp[i] = ocars[i];
        }

        delete[] ocars;

        ocars = temp;

        ocars[num_ocars] = newCar;
        num_ocars++;

        cout << "�� ������ �������� ��� ������? (y/n): ";
        cin >> auserchoice;

        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

    }
}

void carstore::PrintTrimsForModel(string �modelToSearch) {
    std::string dataCars[2][100];
    int numMatches = 0;

    for (int i = 0; i < num_ocars; i++) {
        std::string CurrentModel = ocars[i].GetModel();
        std::string CurrentTrim = ocars[i].GetTrim();
        int CurrentPrice = ocars[i].GetPrice();

        if (CurrentModel == �modelToSearch) {
            dataCars[0][numMatches] = CurrentTrim;
            dataCars[1][numMatches] = std::to_string(CurrentPrice);
            numMatches++;
        }
    }

    for (int i = 0; i < numMatches; i++) {
        for (int j = 0; j < numMatches - 1; j++) {
            int price1 = std::stod(dataCars[1][j]);
            int price2 = std::stod(dataCars[1][j + 1]);

            if (price1 > price2) {
                std::swap(dataCars[0][j], dataCars[0][j + 1]);
                std::swap(dataCars[1][j], dataCars[1][j + 1]);
            }
        }
    }

    std::cout << "\n�������� ������������ �������� ������ � ������� ����������� �� ���������: " << std::endl;

    for (int i = 0; i < numMatches; i++) {
        std::cout << dataCars[0][i] << ", " << dataCars[1][i] << std::endl;
    }
}

void AddCarAndSaveToFile(CarC& newCar, const std::string& filename) {
    std::ofstream outputFile(filename, std::ios::app);

    if (!outputFile) {
        std::cerr << "������ �������� ����� ��� ������" << std::endl;
        return;
    }

    outputFile << "\n" << newCar.GetBrand() << "\n" << newCar.GetModel() << "\n" << newCar.GetTrim() << "\n" << newCar.GetSegment()
        << "\n" << newCar.GetBody() << "\n" << newCar.GetengineVolume() << "\n" << newCar.GetenginePower() << "\n"
        << newCar.GetYear() << "\n" << newCar.GetPrice() << "\n";

    outputFile.close();
}