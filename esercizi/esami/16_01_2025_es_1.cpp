#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x) : key(x), left(nullptr), right(nullptr) {}
};

typedef Node* PNode;

int aux(PNode r, int &h){
    if(!r){
        h = -1;

        return 0;
    }
    else{
        int hsx, hdx, numsx, numdx;

        numsx = aux(r -> left, hsx);
        numdx = aux(r -> right, hdx);

        h = ((hsx >= hdx) ? hsx : hdx) + 1;

        if(r -> key <= h){
            return 1 + numsx + numdx;
        }

        return numsx + numdx;
    }
}

int less_height(PNode r){
    int h;

    return aux(r, h);
}

int main(){
    // --- Albero 1: un singolo nodo ---
    //    5
    PNode tree1 = new Node(5);

    // --- Albero 2: piccolo albero bilanciato ---
    //        3
    //       / \
    //      1   4
    //     / \
    //    0   2
    PNode tree2 = new Node(3);
    tree2->left  = new Node(1);
    tree2->right = new Node(4);
    tree2->left->left  = new Node(0);
    tree2->left->right = new Node(2);

    // --- Albero 3: albero "skewed" a destra ---
    // 3
    //  \
    //   2
    //    \
    //     1
    //      \
    //       0
    PNode tree3 = new Node(3);
    tree3->right = new Node(2);
    tree3->right->right = new Node(1);
    tree3->right->right->right = new Node(0);

    // Esecuzione dei test
    cout << "Risultato su tree1 (solo root=5): " 
         << less_height(tree1) << "\n";
    cout << "Risultato su tree2 (bilanciato):   " 
         << less_height(tree2) << "\n";
    cout << "Risultato su tree3 (skewed right): " 
         << less_height(tree3) << "\n";

    // Pulizia (per correttezza, anche se il programma termina subito)
    delete tree1;

    // tree2
    delete tree2->left->left;
    delete tree2->left->right;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    // tree3
    delete tree3->right->right->right;
    delete tree3->right->right;
    delete tree3->right;
    delete tree3;
    
    return 0;
}
