#include <iostream>

using namespace std;

void print_array(char* s){

}

class Tree{
    private:
        Tree* left;
        Tree* right;
        int root;
        void DisplayTree(string prefix, bool isLeft){
            cout << prefix;
            cout << (isLeft ? "|--" : "!--");
            cout << root << endl;

            if (left)
            left->DisplayTree(prefix + (isLeft ? "|  " : "   "), true);
            if (right)
             right->DisplayTree(prefix + (isLeft ? "|  " : "   "), false);
        }
    public:
        Tree(Tree* _left, Tree* _right, int _root){
            right = _right;
            left = _left;
            root = _root;
        } 
        bool Contains(int n){
            if(root == n) return true;
            if(!left && right){
                return right->Contains(n);
            }
            else if(left && !right){
                return left->Contains(n);
            }
            else if(left && right){return max(left->Contains(n), right->Contains(n));}
            return 0;
        }
        static int GetHeight(Tree* t){
            if(!t) return 0;
            return 1 + max(GetHeight(t->left), GetHeight(t->right));
        }
        int Nodes(){
            int sum = (left ? left->Nodes() : 0) + (right? right-> Nodes() : 0);
            if(!left && !right) return 1;
            else return sum+ 1;            
        }
        int Leaves(){
            int sum = (left ? left->Leaves() : 0) + (right ? right->Leaves() : 0);
            return (!left && !right) + sum;
        }
        void DisplayTree(){
            DisplayTree("", false);
        }
        Tree* Right() {return right;}
        Tree* Left() {return left;}
        void FillTree(int* s, int n, int i){
            if(i < n){
                root = s[i];
                if(2*i + 1 < n){
                    left = new Tree(nullptr, nullptr, 0);
                    left->FillTree(s, n, 2*i + 1);
                }
                if(2*i + 2 < n){
                    right = new Tree(nullptr, nullptr, 0); 
                    right->FillTree(s, n, 2*i + 2);
                }
                
            }
        }
    
};

int main(){
    int s1[1000], s2[1000];
    int n1, n2, r, s;
    cout << "Wprowadz dlugosc pierwszej tablicy:" << endl;
    cin >> n1;
    cout << "Wprowadz dlugosc drugiej tablicy:" << endl;
    cin >> n2;
    cout << "Wprowadz wartosc korzenia po sklejeniu drzew:"<< endl;
    cin >> r;
    cout << "Wprowadz wartosc szukana s:" << endl;
    cin >> s;
    cout << "Wprowadz tablice liczb parsowana w 2 drzewa:" << endl;
    for (int i = 0; i < n1; i++){
        cin >> s1[i];
    }
    for (int i = 0; i < n2; i++){
        cin >> s2[i];
    }
    Tree t1 = Tree(nullptr, nullptr, 0);
    Tree t2 = Tree(nullptr, nullptr, 0);
    t1.FillTree(s1, n1, 0);
    t2.FillTree(s2, n2, 0);
    Tree t = Tree(&t1, &t2, r);
    t.DisplayTree();
    cout << "Wezly: " << t.Nodes() << endl;
    cout << "Liscie: " << t.Leaves() << endl;
    cout << "Wysokosc: " << Tree::GetHeight(&t) << endl;
    if(t.Contains(s)){
        cout << "Drzewo zawiera s" << endl;
    }else {
        cout << "Drzewo nie zawiera s" << endl;
    }
}

