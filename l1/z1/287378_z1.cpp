#include <iostream>
using namespace std;


int f(int n){
    double m = n%2;
    return ((1+5*m)/2)*n + m;
}

int main(){
    int n;
    cin >> n;
    if(n <= 0) return 0;
    int i = 0;
    while(n != 1){
        cout << n << " ";
        n = f(n);
        i++;
    }
    cout << "1, " << i + 1;
    cout << "\nOdpowiadajac na pytanie - Nie wiem." << endl;
}