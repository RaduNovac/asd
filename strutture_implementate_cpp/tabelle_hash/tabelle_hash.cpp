//Tabelle hash | ASD in C++

/* 
    g++ tabelle_hash.cpp -o tabelle_hash
    ./tabelle_hash
*/

#include <iostream>

using namespace std;

struct Node {
    Node* p;
    Node* left;
    Node* right;
    int Key;

    Node() : p(nullptr), left(nullptr), right(nullptr) {}
};

typedef Node Nodo;

class Albero {
    public:
        Nodo* root;

        Albero(){
            root = nullptr;
        }
        //Padre
        Nodo* padre(Nodo v){
            return v.p;
        }
};

int main() {
    int arr[] = {1, 3, 5, 7, 9};  // Array di interi
    vector<int> vettore(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Albero albero = build_BST(vettore);

    return 0;
}