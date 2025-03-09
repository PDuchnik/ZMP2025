#include <iostream>
using namespace std;

int func(int n){
    int res = 0;
    for(int i = 1; i <= n; i++){
        int j = i;
        while(j%10 == 0){
            res += 1;
            j/=10;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << func(n) << endl;
}