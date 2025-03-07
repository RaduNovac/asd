#include <iostream>
#include<stack>

using namespace std;

/*
Sia T un albero generale i cui nodi hanno chiavi intere e campi: 
Key, left_child, right_sib.
Scrivere una procedura ricorsiva efficiente che trasformi T raddoppiando 
i valori di tutte le chiavi sui livelli pari dell’albero.
*/

struct node{
    int key;
    node* left_child;
    node* right_sib;

    node(int k, node* sx = nullptr, node* dx = nullptr)
            : key{k}, left_child{sx}, right_sib{dx} {}
}; typedef node* pnode;

void trasforma(pnode u){
    pnode iter;

    if(u != nullptr){
        /*
        Per ipotesi, sto chiamando la funzione sulla radice 
        (che sta al livello 0, che e’ pari)
        */

        u -> key = u -> key * 2;
        /*
        Siccome questo nodo si trova su un livello pari, 
        trasformiamo tutti i nodi su quel livello
        */

        trasforma(u -> right_sib);

        iter = u -> left_child;

        while(iter != nullptr){
            trasforma(iter -> left_child);
            iter = iter -> right_sib;
        }
    }
}

void print_tree(pnode u, int depth){
    if (!u) return;

    // Stampa rientro
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }

    // Stampa la chiave del nodo
    cout << u->key << "\n";

    // Stampa il sottoalbero del primo figlio (livello successivo)
    print_tree(u->left_child, depth + 1);

    // Stampa i fratelli (stesso livello)
    print_tree(u->right_sib, depth);
}

int main() {
    // Creazione dei nodi
    pnode n1 = new node(1);
    pnode n5 = new node(5);
    pnode n0 = new node(0);
    pnode n9 = new node(9);
    pnode n10 = new node(10);

    // Collegamenti
    n1->left_child = n5;   // il primo figlio di 1 è 5
    n5->right_sib = n0;    // 0 è il fratello (sibling) di 5

    n0->left_child = n9;   // il primo figlio di 5 è 9
    n9->left_child = n10;   // il primo figlio di 9 è 10

    // Stampa dell'albero prima della trasformazione
    cout << "Albero prima di trasforma:\n";
    print_tree(n1, 0);

    // Applico la trasformazione
    trasforma(n1);

    // Stampa dell'albero dopo la trasformazione
    cout << "\nAlbero dopo trasforma:\n";
    print_tree(n1, 0);

    return(0);
}
