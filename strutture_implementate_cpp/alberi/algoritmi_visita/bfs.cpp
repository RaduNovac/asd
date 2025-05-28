//Visita di alberi implementata con i puntatori ai figli, quindi uso come base quella implementazione | ASD in C++

/* 
    g++ bfs.cpp -o bfs
    ./bfs
*/

#include <iostream>
#include <string>
#include <list>
#include <queue>

using namespace std;

struct Node {
    Node* p;
    Node* left;
    Node* right;
    string Key;

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
        //Figli
        list<Nodo> figli(Nodo v){
            //Lista nella quale inserirò i figli
            list<Nodo> l;

            if(v.left != nullptr){
                l.push_back(*v.left);
            }
            if(v.right != nullptr){
                l.push_back(*v.right);
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

void visitaBFS(Nodo *root){
    // Se l'albero è vuoto, termina
    if (root == nullptr) {
        return;
    }

    // Creo una coda per la visita
    queue<Nodo*> q;
    
    // Inserisco la radice nella coda
    q.push(root);
    
    // Continuo finché la coda non è vuota
    while (!q.empty()) {
        // Estraggo il nodo in cima alla coda
        Nodo* current = q.front();
        q.pop();
        
        // Visito il nodo corrente
        cout << current->Key << " ";
        
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    Albero albero;
    Nodo root, nodo_1, nodo_2, nodo_3, nodo_4, nodo_5;
    
    root.Key = "A";
    nodo_1.Key = "L";
    nodo_2.Key = "B";
    nodo_3.Key = "E";
    nodo_4.Key = "R";
    nodo_5.Key = "O";
    
    //Radice
    root.left = &nodo_1;
    root.right = &nodo_2;
    //Nodo L
    nodo_1.left = &nodo_3;
    nodo_1.right = &nodo_4;
    nodo_1.p = &root;
    //Nodo B
    nodo_2.p = &root;
    nodo_2.right = &nodo_5;
    //Nodo E
    nodo_3.p = &nodo_1;
    //Nodo R
    nodo_4.p = &nodo_1;
    //Nodo O
    nodo_5.p = &nodo_2;
    
    albero.root = &root;

    albero.printFigli(albero.figli(nodo_1));

    visitaBFS(albero.root);

    return 0;
}