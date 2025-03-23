#include <iostream>
using namespace std;
#include <vector>
#include <string>

int nwd(int a, int b){
    while(b!=0){
        int m = b;
        b = a%b;
        a = m;    
    }
    return a;
}

int main(){ 
    int length = 0;
    vector<int> numbers;
    for(int i = -1; i < length; i++){
        if(i == -1){
            cin >> length;
        }
        else{
            int n;
            cin >> n;
            numbers.push_back(n);
        }
    }
    int res = nwd(numbers[0], numbers[1]);
    for(int i = 2; i < length; i++){
        res = nwd(res, numbers[i]);
    }
    cout << res << endl;
}   