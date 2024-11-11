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

            Nodo *iterator = v.left_child;
            
            while(iterator != nullptr){
                l.push_back(*iterator);
                iterator = iterator->right_sib;
            }

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
    
    //root
    albero.root = &root;
    root.left_child = &nodo_1;
    //nodo_1
    nodo_1.p = &root;
    nodo_1.left_child = &nodo_3;
    nodo_1.right_sib = &nodo_2;
    //nodo_2
    nodo_2.left_child = &nodo_5;
    //nodo_3
    nodo_3.p = &nodo_1;
    nodo_3.right_sib = &nodo_4;
    //nodo_4
    nodo_4.p = &nodo_1;
    //nodo_5
    nodo_5.p = &nodo_2;

    albero.printFigli(albero.figli(nodo_1));

    return 0;
}