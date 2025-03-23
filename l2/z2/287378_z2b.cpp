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
    int up = length;
    int down = 0;
    int average = std::floor((up + down)/2);
    bool flag = false;
    while(up != down){
        if(numbers[average] < x){
            down = average;
        }
        else if(x < numbers[average]){
            up = average;
        }
        else{
            flag = true;
            break;
        }
        average = std::floor((up + down)/2);
    }
    if(flag){
        cout << "tak "<< average << endl;
    }
    else{
        cout << "nie" << endl;
    }
}