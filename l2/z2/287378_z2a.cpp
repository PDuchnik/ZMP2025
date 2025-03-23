#include <iostream>
using namespace std;
#include "math.h"
#include <string>
#include <vector>
int main(){
    int length = 0;
    int x;
    vector<int> numbers;
    int buffer;
    for(int i = -2; i < length; i++){
        cin >> buffer;
        if (i == -2){
            x = buffer;
        }
        else if(i == -1){
            length = buffer;
        }
        else{
            numbers.push_back(buffer);
        }
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