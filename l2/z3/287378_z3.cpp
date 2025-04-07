#include <iostream>
using namespace std;
#include <vector>
int main(){
    bool* message;
    cout << "Podaj sekret (ciag 0/1 o dlugosci 8) oraz wiadomosc (drugi ciag 0/1 o dlugosci 8):" << endl;
    for(int i = 0; i < 16; i++){
       cin >> message[i];
    }
    for(int i = 0; i < 8; i++){
        cout << (message[i]^message[i+8]) << ' ';
    }
    cout << endl;
}
