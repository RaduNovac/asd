#include <iostream>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

typedef TreeNode* PTree;

// Trova il nodo con il valore minimo in un BST
PTree findMin(PTree root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Rimuove il nodo con il valore minimo da un BST
PTree removeMin(PTree root) {
    if (!root) 
        return nullptr;
    if (!root->left) {
        PTree rightChild = root->right;
        delete root;
        //cout << "deleted:" << root ->key << endl;
        return rightChild;
    }
    root->left = removeMin(root->left);
    //cout << "returned:" << root ->key<< endl;
    return root;
}

// Funzione per unire due BST, T1 e T2
PTree mergeBST(PTree T1, PTree T2) {
    if (!T1) return T2;  // Se T1 è vuoto, restituisci T2
    if (!T2) return T1;  // Se T2 è vuoto, restituisci T1

    // Trova il minimo in T2
    PTree minNode = findMin(T2);
    
    // Rimuovi il minimo da T2
    T2 = removeMin(T2);
    //cout << "new root for t2:" << T2->key<<endl;
    
    // Imposta minNode come nuova radice
    minNode->left = T1;  // T1 è il figlio sinistro
    minNode->right = T2; // Il resto di T2 è il figlio destro
    
    return minNode;  // Ritorna il nuovo albero unito
}

// Funzione di utilità per stampare il BST in ordine inorder
void inorderTraversal(PTree root) {
    if(!root){
        return;
    }
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
    
}

int main() {
    // Creazione di due BST di esempio
    PTree T1 = new TreeNode(10);
    T1->left = new TreeNode(8);
    T1->left->left = new TreeNode(6);
    T1->left->left->left = new TreeNode(3);

    PTree T2 = new TreeNode(27);
    T2->left = new TreeNode(20);
    T2->left->left = new TreeNode(18);
    T2->left->left->left = new TreeNode(15);

    //Stampo i due alberi:
    inorderTraversal(T1);
    cout << endl;
    inorderTraversal(T2);
    cout << endl;

    // Unione dei due BST
    PTree mergedTree = mergeBST(T1, T2);

    // Verifica: stampa in ordine inorder del BST unito
    inorderTraversal(mergedTree);
    return 0;
}
