#include <iostream>
#include<stack>

using namespace std;

/*
Sia T un albero binario. Progettare un algoritmo che, presi in ingresso la radice
di T e un intero k che risulti essere maggiore di 0, stampi le chiavi contenuti 
nei nodi di T al livello k, procedendo da sinistra verso destra.
*/

struct node{
    int key;
    node* left;
    node* right;
    node* p;

    node(int k, node* sx = nullptr, node* dx = nullptr)
            : key{k}, left{sx}, right{dx} {}
}; typedef node* pnode;
//Do per scontato che k sia > 0 e < num_livelli albero
void stampa_livello(pnode u, int k){
    if(u != nullptr){//Se l'albero non è vuoto
        if(k == 0){//Se è il livello che voglio
            cout << u -> key << "; ";
        }
        else{//Altrimenti scendo di 1 livello
            stampa_livello(u -> left, k-1);
            stampa_livello(u -> right, k-1);
        }
    }
}

int main() {
    node nodo_1{1};
    node nodo_2{2};
    node nodo_3{3};
    node nodo_4{4};
    node nodo_5{5};
    node nodo_6{6};
    node nodo_7{7};

    nodo_1.left = &nodo_2;
    nodo_1.right = &nodo_3;
    nodo_2.left = &nodo_4;
    nodo_2.right = &nodo_5;
    nodo_3.right = &nodo_6;
    nodo_4.right = &nodo_7;

    stampa_livello(&nodo_1,2);

    return(0);
}
