#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int _value, Node* _next){
        value = _value, next = _next;
    }
};

bool BubbleSort(Node* Start){
    if(Start->value>Start->next->value){
        Node* debug = Start;
        int temp = Start->value;
        Start->value = Start->next->value;
        Start->next->value = temp;

        if(Start->next->next)
        BubbleSort(Start->next);
        return false;
    }else return true;
}

int main(){
    cout << "Ten program implementuje bubble sort na liscie polaczonej.\nWprowadz dlugosc listy:" <<  endl;
    int n;
    cin >> n;
    Node* previousPointer = nullptr;
    Node* currentPointer = nullptr;
    cout << "Wprowadz liste:" << endl;
    for (int i = 0; i < n; i++){
        int value;
        cin >> value;
        currentPointer = new Node(value, previousPointer);
        previousPointer = currentPointer;
    }
    Node Head = *currentPointer;
    while(!BubbleSort(currentPointer));
    
    while(currentPointer){
        cout << currentPointer->value << " ";
        currentPointer = currentPointer->next;
    }
}
