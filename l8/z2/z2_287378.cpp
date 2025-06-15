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
        static bool IsIsomorphic(Tree* t1, Tree* t2){
            if(t1 == nullptr && t2 == nullptr){
                return true;
            }
            else if (t1 && t2){
                return IsIsomorphic(t1->left, t2->left) && IsIsomorphic(t1->right, t2->right);
            }
            else return false;
        }
        void BSTInsertNode(Tree* node){
            if(node->root<this->root){
                if (this->left){
                    this->left->BSTInsertNode(node);
                }else{
                    this->left = node;
                }
            }
            else if(node->root > this->root){
                if (this->right){
                    this->right->BSTInsertNode(node);
                }else{
                    this->right = node;
                }
            }
            else cout << "Duplikat" << endl;
        }
        int Traverse(int* presult, int* pindex, int value){
            cout << *pindex << endl;
            if (*pindex == value) *presult = root;
            (*pindex)++;
            if(left) left->Traverse(presult, pindex, value);
            if(right) right->Traverse(presult, pindex, value);
            return *pindex;
        }
        int operator[](int k){
            int i = 0;
            int result = 0; 
            Traverse(&result, &i, k);
            return result;
        }
        void CopyTree(Tree* t){
            if (left){
                t->left = new Tree(nullptr, nullptr, 0);
                left->CopyTree(t->left);
            } 
            if (right){
                t->right = new Tree(nullptr, nullptr, 0);
                right->CopyTree(t->right);
            } 
            
        }
        void Add(Tree* t, Tree* buffer){
            buffer->root = root + t->root;
            if(left) left->Add(t->left, buffer->left);
            if(right) right->Add(t->right, buffer->right);
        }
        Tree operator+(Tree t){
            Tree result = Tree(nullptr, nullptr, 0);
            CopyTree(&result);
            Add(&t, &result);
            return result;
        }
        void Subtract(Tree* t, Tree* buffer){
            buffer->root = root - t->root;
            if(left) left->Subtract(t->left, buffer->left);
            if(right) right->Subtract(t->right, buffer->right);
        }
        Tree operator-(Tree t){
            Tree result = Tree(nullptr, nullptr, 0);
            CopyTree(&result);
            Subtract(&t, &result);
            return result;
        }
};

int main(){
    int n1, n2;
    int a[100], b[100];
    cout << "Podaj dlugosc pierwszej listy: " << endl;
    cin >> n1;
    cout << "Podaj pierwsza liste: " << endl;
    for (int i = 0; i < n1; i++){
        cin >> a[i];
    }
    cout << "Podaj dlugosc drugiej listy: " << endl;
    cin >> n2;
    cout << "Podaj druga liste: " << endl;
    for (int i = 0; i < n2; i++){
        cin >> b[i];
    }
    Tree t1 = Tree(nullptr, nullptr, a[0]);
    Tree t2 = Tree(nullptr, nullptr, b[0]);
    for (int i = 1; i < n1; i++){
        t1.BSTInsertNode(new Tree(nullptr, nullptr, a[i]));
    }
    for (int i = 1; i < n2; i++){
        t2.BSTInsertNode(new Tree(nullptr, nullptr, b[i]));
    }
    if (Tree::IsIsomorphic(&t1, &t2)) cout << "Drzewa sa izomorficzne" << endl;
    else return 0;
    (t1+t2).DisplayTree();
    (t1-t2).DisplayTree();
}
