#include <iostream>
using namespace std;

int max_value;

int min_c(int a, int b){
    if(a < b){
        return a;
    }
    else return b;
}
int max_c(int a, int b){
    if (a > b){
        return a;
    }
    else return b;
}

void copy(int destination[], int source[], int n, int dest_start, int src_start){
    for (int i = 0; i < n; i++){
        destination[i + dest_start] = source[i + src_start];
    }
}

void print_set(int s[], int n){
    for (int i = 0; i < n; i++){
        cout << s[i] << " ";
    }
}

void merge(int s[], int s1[], int s2[], int l1, int l2){
    int p = 0;
    int q = 0;
    for (int i = 0; i < l1+l2; i++){
        if ((s1[p] <= s2[q] || q == l2) && p != l1){
            s[i] = s1[p];
            p++;
            continue;
        }
        if ((s2[q] <= s1[p] || p == l1) && q != l2){
            s[i] = s2[q];
            q++;
            continue;
        }
    }
}

void merge_sort(int s[], int n){
    int k = 1;
    while(k < n){
        for(int i = 0; i < n; i += 2*k){
            int merged_s[1000];
            int sub1[1000];
            int sub2[1000];
            int l1 = max_c(0, min_c(k, n-i));
            int l2 = max_c(0, min_c(k, n-(i+k)));
            copy(sub1, s, l1, 0, i);
            copy(sub2, s, l2, 0, i+k);
            if(sub2[l2-1] - sub1[0] > max_value) max_value = sub2[l2 - 1] - sub1[0];
            merge(merged_s, sub1, sub2, l1, l2);
            copy(s, merged_s, l1+l2, i, 0);
        }
        
        k *= 2;
    }
}

int main(){
    cout << "Podaj dlugosc ciagu: " << endl;
    int n;
    cin >> n;
    cout << "Podaj ciag: " << endl;
    int s[1000];
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    max_value = s[1] - s[0];
    merge_sort(s, n);
    cout << max_value;
}
