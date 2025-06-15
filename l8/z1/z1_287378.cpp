#include <iostream>

using namespace std;

void copy(char* source, char* destination, int start, int n){
    for (int i = 0; i < n; i++){
        destination[i + start] = source[i];
    }
}

class Pojazd{
    protected:
        char marka[100];
        char model[100];
        int rok_produkcji;
    public:
        void DisplayBrand(){
            cout << "Marka: ";
            for (int i = 0; marka[i]; i++){
                cout << marka[i];
            }
            cout << endl;
        }
        void DisplayModel(){
            cout << "Model: " << model << endl;
        }
        void DisplayProductionYear(){
            cout << "Rok produkcji: " << rok_produkcji << endl; 
        }
        virtual void DisplayInfo(){
            DisplayBrand();
            DisplayModel();
            DisplayProductionYear();
        }
};

class Rower : protected Pojazd{
    protected:
        int liczba_przerzutek;
    public:
        Rower(char* _marka, char* _model, int _rok_produkcji, int _liczba_przerzutek, int lmarka, int lmodel){
            copy(_marka, marka, 0, lmarka);
            copy(_model, model, 0, lmodel);
            rok_produkcji = _rok_produkcji;
            liczba_przerzutek = _liczba_przerzutek;
        }
        void DisplayDerailleurCount(){
            cout << "Liczba przerzutek: " << liczba_przerzutek << endl;
        }
        void DisplayInfo(){
            DisplayBrand();
            DisplayModel();
            DisplayProductionYear();
            DisplayDerailleurCount();
        }
};

class Samochod : protected Pojazd{
    protected:
        int liczba_drzwi;
    public:
        Samochod(char* _marka, char* _model, int _rok_produkcji, int _liczba_drzwi, int lmodel, int lmarka){
            copy(_marka, marka, 0, lmarka);
            copy(_model, model, 0, lmodel);
            rok_produkcji = _rok_produkcji;
            liczba_drzwi = _liczba_drzwi;
        }
        void DisplayDoorCount(){
            cout << "Liczba drzwi: " << liczba_drzwi << endl;
        }
        void DisplayInfo(){
            DisplayBrand();
            DisplayModel();
            DisplayProductionYear();
            DisplayDoorCount();
        }
};

int main(){
    char brandBicycle[100], brandCar[100], modelBicycle[100], modelCar[100];
    int productionYearCar, productionYearBicycle, derailleurCount, doorCount;
    cout << "Wprowadz marke roweru: ";
    cin >> brandBicycle;
    cout << "Wprowadz model roweru: ";
    cin >> modelBicycle;
    cout << "Wprowadz rok produkcji roweru: ";
    cin >> productionYearBicycle;
    cout << "Wprowadz liczbe przerzutek: ";
    cin >> derailleurCount;
    cout << "Wprowadz marke samochodu: ";
    cin >> brandCar;
    cout << "Wprowadz model samochodu";
    cin >> modelCar;
    cout << "Wprowadz rok produkcji samochodu: ";
    cin >> productionYearCar;
    cout << "Wprowadz liczbe drzwi: ";
    cin >> doorCount;
    Rower b = Rower(brandBicycle, modelBicycle, productionYearBicycle, derailleurCount, 100, 100);
    Samochod c = Samochod(brandCar, modelCar, productionYearCar, doorCount, 100, 100);
    b.DisplayInfo();
    c.DisplayInfo();
}