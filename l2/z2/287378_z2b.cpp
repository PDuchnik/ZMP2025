#include <iostream>
using namespace std;
#include "math.h"

int main(){
    int length;
    int x;
    int numbers[1000];
    int buffer;
    cout << "Podaj szukana liczbe:" << endl;
    cin >> x;
    cout << "Podaj dlugosc ciagu:" << endl;
    cin >> length;
    cout << "Podaj ciag:" << endl;
    for(int i = 0; i < length; i++){
        cin >> numbers[i];
    }
    int up = length - 1;
    int down = 0;
    bool flag = false;
    float average = 0;
    while(up >= down){
        average = std::floor((up + down)/2);
        if(numbers[(int)average] < x){
            down = average + 1;
        }
        else if(numbers[(int)average] > x){
            up = average -1;
        }
        if(numbers[(int)average] == x){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "tak "<< average << endl;
    }
    else{
        cout << "nie" << endl;
    }
}
