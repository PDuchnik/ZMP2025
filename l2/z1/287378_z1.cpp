#include <iostream>
using namespace std;


int nwd(int a, int b){
    while(b!=0){
        int m = b;
        b = a%b;
        a = m;    
    }
    return a;
}

int main(){ 
    int length;
    int numbers[1000];
    cout << "Podaj dlugosc ciagu:" << endl;
    cin >> length;
    for (int i = 0; i < length; i++){
        cin >> numbers[i];
    }
    int res = nwd(numbers[0], numbers[1]);
    for(int i = 2; i < length; i++){
        res = nwd(res, numbers[i]);
    }
    cout << res << endl;
}   
