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
    return 0;
}