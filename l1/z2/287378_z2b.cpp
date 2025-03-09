#include <iostream>
using namespace std;

int phi(int n){
    int res = 0;
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = 2; j <= i; j++){
            if (i%j == 0 && n%j == 0) flag = false;
        }
        if(flag) res++;
    }
    return res;
}

int F(int n){
    int res = 0;
    for(int d = 1; d <= n; d++){
        res += (!(n%d))*phi(d);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    if(n<=0) return 0;
    cout << F(n) << endl;
}