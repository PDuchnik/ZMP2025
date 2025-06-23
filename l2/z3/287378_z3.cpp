#include <iostream>
using namespace std;
int main(){
    bool message[16];
    cout << "Podaj sekret (ciag 0/1 o dlugosci 8) oraz wiadomosc (drugi ciag 0/1 o dlugosci 8): (znaki po spacjach lub enterach)" << endl;
    for(int i = 0; i < 16; i++){
       cin >> message[i];
    }
    for(int i = 0; i < 8; i++){
        cout << (message[i]^message[i+8]) << ' ';
    }
    cout << endl;
}
