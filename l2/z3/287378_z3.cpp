#include <iostream>
using namespace std;
#include <vector>
int main(){
    bool* message;
    for(int i = 0; i < 16; i++){
       cin >> message[i];
    }
    for(int i = 0; i < 8; i++){
        cout << (message[i]^message[i+8]) << ' ';
    }
    cout << endl;
}
