#include <iostream>

using namespace std;

// Definizione del nodo dell'albero
struct Node {
    int key;            // Valore del nodo
    Node* left_child;   // Puntatore al figlio sinistro
    Node* right_sib;    // Puntatore al fratello destro

    // Costruttore per inizializzare un nodo
    Node(int k) : key(k), left_child(nullptr), right_sib(nullptr) {}
};

// Funzione ricorsiva per contare il numero di foglie nell'albero
int countLeaves(Node* root) {
    if (root == nullptr) {
        // Se l'albero è vuoto, non ci sono foglie
        return 0;
    }
    
    // Se il nodo corrente è una foglia (nessun figlio sinistro)
    if (root->left_child == nullptr) {
        cout << root->key<<endl;
        return 1; // Conta il nodo corrente come una foglia
    }
    
    // Ricorsivamente conta le foglie nei figli e nei fratelli
    return countLeaves(root->left_child) + countLeaves(root->right_sib);
}

int main() {
    // Esempio di costruzione dell'albero
    /*Node* root = new Node(1);
    root->left_child = new Node(2);
    root->left_child->right_sib = new Node(3);
    root->left_child->right_sib->right_sib = new Node(4);
    root->left_child->left_child = new Node(5);
    root->left_child->left_child->right_sib = new Node(6);*/

    Node* root = new Node(1);
    root->left_child = new Node(2);
    root->left_child -> right_sib = new Node(3);
    root->left_child -> right_sib -> right_sib = new Node(4);
    root->left_child -> right_sib -> right_sib -> right_sib = new Node(5);
    root -> left_child ->left_child = new Node(6);
    root -> left_child ->left_child -> right_sib = new Node(7);//foglia
    root->left_child -> right_sib -> right_sib ->right_sib -> left_child = new Node(8);
    root->left_child -> right_sib -> right_sib ->right_sib -> left_child -> right_sib = new Node(9);//foglia
    root->left_child -> right_sib -> right_sib ->right_sib -> left_child -> left_child = new Node(10);
    root->left_child -> right_sib -> right_sib ->right_sib -> left_child -> left_child -> right_sib = new Node(11);//foglia

    // Calcolo e stampa del numero di foglie
    cout << "Numero di foglie: " << countLeaves(root) << std::endl;

    // Liberazione della memoria (non mostrata per semplicità)

    return 0;
}
