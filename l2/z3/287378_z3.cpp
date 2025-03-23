#include <iostream>
using namespace std;
#include <vector>
int main(){
    vector<bool> message;
    for(int i = 0; i < 16; i++){
        bool a;
        cin >> a;
        message.push_back(a);
    }
    for(int i = 0; i < 8; i++){
        cout << (message[i]^message[i+8]) << ' ';
    }
    cout << endl;
}