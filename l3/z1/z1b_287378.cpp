#include <iostream>
using namespace std;
#define N 100000000

unsigned long long int memo[N];

int fib(int n){
    if(memo[n]){
        return memo[n];
    }
    else{
        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
}

int main(){
    memo[0] = memo[1] = 1;
    for (int i = 2; i < N; i++){
        memo[i] = 0;
    }
    int n;
    cout << "Podaj numer wyrazu ciagu:" << endl;
    cin >> n;
    cout << fib(n) << endl;
}