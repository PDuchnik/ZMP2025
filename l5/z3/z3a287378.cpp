#include <iostream>
using namespace std;

int main(){
    int s[1000];
    int n;
    cout << "Podaj dlugosc ciagu" << endl;
    cin >> n;
    cout << "Podaj ciag " << endl;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    int max_value = s[1] - s[0];
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (s[j] - s[i] > max_value) max_value = s[j] - s[i];
        }
    }
    cout << max_value;
}