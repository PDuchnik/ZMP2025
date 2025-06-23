#include <iostream>
using namespace std;

int main(){
    int length = 0;
    int x;
    int* numbers;
    int buffer;
    cout << "Wpisz liczbe szukana x i dlugosc ciagu n: " << endl;
    cin >> x >> length;
    cout << "Wpisz ciag n liczb: " << endl;
    for(int i = 0; i < length; i++){
        cin >> numbers[i];
    }
    bool flag = false;
    for(int i = 0; i < length; i++){
        if(numbers[i] == x){
            cout << "tak " << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << "nie";
    }
    
}
