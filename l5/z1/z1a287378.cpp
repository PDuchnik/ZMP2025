#include <iostream>
using namespace std;

int main(){
    int s[1000];
    int n;
    int inv = 0;
    cout << "Podaj dlugosc ciagu: " << endl;
    cin >> n;
    cout << "Podaj ciag: " << endl;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if (s[i] > s[j]) inv++;
        }
    }
    cout << inv;
}