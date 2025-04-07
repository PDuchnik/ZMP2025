#include <iostream>
using namespace std;

int fib(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        long long int a = 1;
        long long int b = 1;
        long long int res = 0;
        for (int i = 1; i < n; i++){
             res = a + b;
             a = b;
             b = res;
        }
        return res;
    }
}

int main(){
    long long int n;
    cout << "Podaj numer wyrazu ciagu:" << endl;
    cin >> n;
    cout << fib(n); 
}