//Alberi implementati con le strutture collegate | ASD in C++

/* 
    g++ figlio_sx_fratello_dx.cpp -o figlio_sx_fratello_dx
    ./figlio_sx_fratello_dx
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Node {
    Node* p;
    Node* left_child;
    Node* right_sib;
    string Key;

    Node() : p(nullptr), left_child(nullptr), right_sib(nullptr) {}
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
        //Figli
        list<Nodo> figli(Nodo v){
            //Lista nella quale inserirò i figli
            list<Nodo> l;

            

            return l;
        }

        void printFigli(list<Nodo> l){
            cout << "Lista dei figli:\n";

            for (Nodo i : l) {
                cout << "Nodo: " << i.Key << endl;
            }
        }
};

int main() {
    Albero albero;
    Nodo root, nodo_1, nodo_2, nodo_3, nodo_4, nodo_5;
    
    root.Key = "A";
    nodo_1.Key = "L";
    nodo_2.Key = "B";
    nodo_3.Key = "E";
    nodo_4.Key = "R";
    nodo_5.Key = "O";
    
    
    
    albero.root = &root;

    albero.printFigli(albero.figli(nodo_1));

    return 0;
}