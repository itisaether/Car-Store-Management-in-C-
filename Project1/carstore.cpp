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
    cout << "\nВызван конструктор класса carstore:";
    cout << "\n выделено объектов (для новых машин) - " << max_num_ocars;
    cout << "\n выделено объектов (для б/y машин) - " << max_num_tcars;
    cout << "\n загружено машин (новых) - " << num_ocars;
    cout << "\n загружено машин (б/у) - " << num_tcars;
    cout << endl;

}

carstore::~carstore() {
    cout << "\nВызван деструктор класса carstore:";
    max_num_ocars = 0;
    delete[] ocars;
    num_ocars = 0;

    max_num_tcars = 0;
    delete[] tcars;
    num_tcars = 0;
    cout << "\n выделенная память освобождена";
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
    stream << "\n ВЕСЬ АССОРТИМЕНТ МАГАЗИНА:\n";
    stream << "\n А) Новые машины\n";
    for (int i = 0; i < astore.num_ocars; i++)
    {
        stream << "=========== машина " << i + 1 << " ============== \n";
        stream << astore.ocars[i] << endl;
    }
    stream << "\n А) Б/у машины\n";
    for (int i = 0; i < astore.num_tcars; i++)
    {
        stream << "=========== машина " << i + 1 << " ============== \n";
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
        std::cout << "\n\nФайл данных не найден!" << std::endl;
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

    std::cout << "\nЗагружены данные из файла " << filename << ":";
    std::cout << "\n число загруженных машин - " << num_ocars;

}

void carstore::read_tcars_from_file(std::string filename) {
    std::ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        std::cout << "\n\nФайл данных не найден!" << std::endl;
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

    std::cout << "\nЗагружены данные из файла " << filename << ":";
    std::cout << "\n число загруженных машин - " << num_tcars;

}

void carstore::write_ocars_to_file(string filename) {

    ofstream outfile;
    outfile.open(filename);
    outfile << num_ocars << std::endl;
    for (int i = 0; i < num_ocars; i++)
        outfile << ocars[i];
    outfile.close();

    std::cout << "\nДанные записаны в файл " << filename << ":";
    std::cout << "\n число записанных машин - " << num_ocars;
}

void carstore::write_tcars_to_file(string filename) {

    ofstream outfile;
    outfile.open(filename);
    outfile << num_tcars << std::endl;
    for (int i = 0; i < num_tcars; i++)
        outfile << tcars[i];
    outfile.close();

    std::cout << "\nДанные записаны в файл " << filename << ":";
    std::cout << "\n число записанных машин - " << num_tcars;
}


void carstore::find_car(string amodel) {
    cout << "\n\nИщем машину с моделью \"" << amodel << "\"";
    bool found = false;
    for (int i = 0; i < num_ocars; i++)
    {
        if (ocars[i].get_model() == amodel)
        {
            found = true;
            cout << "\nНайдена модель:\n";
            cout << ocars[i];
        }
    }
    for (int i = 0; i < num_tcars; i++)
    {
        if (tcars[i].get_model() == amodel)
        {
            found = true;
            cout << "\nНайдена модель:\n";
        }
    }
    if (!found)
        cout << "\nМашина с такой моделью не найдена!\n";
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

        std::cout << "Соотношение мощности двигателя к стоимости для модели " << CurrentModel << ": " << CurrentRatio << std::endl;

        if (CurrentRatio > maxRatio) {
            maxRatio = CurrentRatio;
            maxRatioModel = CurrentModel;
        }
    }

    std::cout << "\nМодель с самым высоким соотношением: " << maxRatioModel << std::endl;
}

void carstore::AddCarsByUser(char auserchoice) {
    while (auserchoice == 'y') {
        CarC newCar;
        cout << "Введите марку: ";
        string brand;
        cin >> brand;
        newCar.SetBrand(brand);

        cout << "Введите модель: ";
        string model;
        cin >> model;
        newCar.SetModel(model);

        cout << "Введите двигатель: ";
        string trim;
        cin >> trim;
        newCar.SetTrim(trim);

        cout << "Введите сегмент: ";
        string segment;
        cin >> segment;
        newCar.SetSegment(segment);

        cout << "Введите кузов: ";
        string body;
        cin >> body;
        newCar.SetBody(body);

        cout << "Введите объем двигателя: ";
        double engineVolume;
        cin >> engineVolume;
        newCar.SetVolume(engineVolume);

        cout << "Введите мощность двигателя: ";
        int enginePower;
        cin >> enginePower;
        newCar.SetPower(enginePower);

        cout << "Введите год производства: ";
        int year;
        cin >> year;
        newCar.SetYear(year);

        cout << "Введите цену машины: ";
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

        cout << "Вы хотите добавить ещё машины? (y/n): ";
        cin >> auserchoice;

        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

    }
}

void carstore::PrintTrimsForModel(string аmodelToSearch) {
    std::string dataCars[2][100];
    int numMatches = 0;

    for (int i = 0; i < num_ocars; i++) {
        std::string CurrentModel = ocars[i].GetModel();
        std::string CurrentTrim = ocars[i].GetTrim();
        int CurrentPrice = ocars[i].GetPrice();

        if (CurrentModel == аmodelToSearch) {
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

    std::cout << "\nНазвания комплектаций заданной модели в порядке возрастания их стоимости: " << std::endl;

    for (int i = 0; i < numMatches; i++) {
        std::cout << dataCars[0][i] << ", " << dataCars[1][i] << std::endl;
    }
}

void AddCarAndSaveToFile(CarC& newCar, const std::string& filename) {
    std::ofstream outputFile(filename, std::ios::app);

    if (!outputFile) {
        std::cerr << "Ошибка открытия файла для записи" << std::endl;
        return;
    }

    outputFile << "\n" << newCar.GetBrand() << "\n" << newCar.GetModel() << "\n" << newCar.GetTrim() << "\n" << newCar.GetSegment()
        << "\n" << newCar.GetBody() << "\n" << newCar.GetengineVolume() << "\n" << newCar.GetenginePower() << "\n"
        << newCar.GetYear() << "\n" << newCar.GetPrice() << "\n";

    outputFile.close();
}