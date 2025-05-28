#include <iostream>

using namespace std;

struct TreeNode{
    int key;
    TreeNode *left, *right;
    TreeNode(int k){
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

typedef TreeNode* PTree;

PTree insert(PTree root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }
    if (key <= root->key) {
        root->left = insert(root->left, key);
    }
    else if (key >= root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void aux(PTree t, PTree& nuovo, int inf, int k) {
    if (t == nullptr) return;

    if (t->key >= inf && t->key <= k) {
        nuovo = insert(nuovo, t->key);
    }

    aux(t->left, nuovo, inf, k);
    aux(t->right, nuovo, inf, k);
}

PTree creaBSTinterval(PTree t, int k) {
    if (t == nullptr) {
        return nullptr;
    }

    PTree nuovo = nullptr;
    int inf = t->key; // La radice originale diventa il limite inferiore

    aux(t, nuovo, inf, k);
    return nuovo;
}

// Funzione per stampare l'albero (per debug)
void printTree(PTree root, string prefix = "", bool isLeft = false) {
    if (root == nullptr) return;
    
    cout << prefix;
    cout << (isLeft ? "├──" : "└──" );
    cout << root->key << endl;
    
    printTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
}

int main(){
    // Creo un BST di esempio
    PTree root = nullptr;
    root = insert(root, 8);  // radice
    root = insert(root, 3);  // sottoalbero sinistro
    root = insert(root, 10); // sottoalbero destro
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    cout << "Albero originale:" << endl;
    printTree(root);
    
    // Creo un nuovo albero con k = 8 (la radice)
    PTree nuovo = creaBSTinterval(root, 13);
    
    cout << "\nNuovo albero dopo creaBSTinterval:" << endl;
    printTree(nuovo);

    return 0;
}