#include <iostream>
using namespace std;
#include "math.h"
#include <string>
#include <vector>
int main(){
    int length = 0;
    int x;
    int* numbers;
    int buffer;
    cin >> x >> length;
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
