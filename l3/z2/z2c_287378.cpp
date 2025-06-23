#include <iostream>
using namespace std;

int pow(int base, int power){
    int res = 1;
    for (int i = 0; i < power; i++){
        res *= base;
    }
    return res;
}

void print_set(int* set, int n){
    for (int i = 0; i < n; i++){
        cout << set[i] << " ";
    }
    cout << endl;
}


int main(){
    int n;
    int numbers[100];
    cout << "Podaj dlugosc ciagu:" << endl;
    cin >> n;
    cout << "Podaj ciag:" << endl;
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    int k;
    cout << "Podaj dlugosc podciagu:" << endl;
    cin >> k;

    for (int i = 1; i < pow(2, n); i++){
        int subset[100];
        int subset_end = 0;
        int a = i;
        for (int j = 0; a > 0; j++){
            //if (a%2 == 1) cout << numbers[j] << " ";
            if (a%2 == 1) {
                subset[subset_end] = numbers[j];
                subset_end++;
            }
            a >>= 1;
        }
        if (subset_end == k) print_set(subset, subset_end);
    }
    cout << "empty" << endl;
}
