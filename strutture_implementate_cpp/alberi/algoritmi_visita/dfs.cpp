//Visita di alberi implementata con i puntatori ai figli, quindi uso come base quella implementazione | ASD in C++

/* 
    g++ dfs.cpp -o dfs
    ./dfs
*/

#include <iostream>
#include <string>
#include <list>
#include <stack>

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

void visitaDFS(Nodo *root){
    // Se l'albero è vuoto, termina
    if (root == nullptr) {
        return;
    }

    // Creo uno stack per la visita
    stack<Nodo*> s;
    
    // Inserisco la radice nello stack
    s.push(root);
    
    // Continuo finché lo stack non è vuoto
    while (!s.empty()) {
        // Estraggo il nodo in cima allo stack
        Nodo* current = s.top();
        s.pop();
        
        // Visito il nodo corrente
        cout << current->Key << " ";
        
        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
    cout << endl;
}

void visitaDFS_ric(Nodo *r){
    if(r != nullptr){
        cout << r->Key << " ";
        visitaDFS_ric(r -> left);
        visitaDFS_ric(r -> right);
    }
}

void visitaDFS_ric_preordine(Nodo *r){
    if(r != nullptr){
        cout << r->Key << " ";
        visitaDFS_ric_preordine(r -> left);
        visitaDFS_ric_preordine(r -> right);
    }
}

void visitaDFS_ric_simmetrica(Nodo *r){
    if(r != nullptr){
        visitaDFS_ric_simmetrica(r -> left);
        cout << r->Key << " ";
        visitaDFS_ric_simmetrica(r -> right);
    }
}

void visitaDFS_ric_postordine(Nodo *r){
    if(r != nullptr){
        visitaDFS_ric_postordine(r -> left);
        visitaDFS_ric_postordine(r -> right);
        cout << r->Key << " ";
    }
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

    visitaDFS(albero.root);
    visitaDFS_ric(albero.root);
    cout << endl;
    visitaDFS_ric_preordine(albero.root);
    cout << endl;
    visitaDFS_ric_simmetrica(albero.root);
    cout << endl;
    visitaDFS_ric_postordine(albero.root);

    return 0;
}