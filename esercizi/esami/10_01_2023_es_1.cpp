#include <iostream>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

typedef TreeNode* PTree;

int somma(PTree u){
    if(u != nullptr){
        return u -> key + somma(u -> left) + somma(u -> right);
    }
    else return 0;
}

int k_compreso(PTree u, int k){
    if(u == nullptr){return 1;}
    int x = somma(u);
    return x > -k && x < k && k_compreso(u -> left, k) && k_compreso(u ->right, k);
}

int aux(PTree u, int k, int& sum){
    if(u == nullptr){
        sum = 0;
        return 1;
    }
    else{
        int somma_sx = 0, somma_dx = 0;

        int left_ok = aux(u -> left, k, somma_sx);
        int right_ok = aux(u -> right, k, somma_dx);

        sum = somma_dx + somma_sx + u -> key;

        int ok = sum < k && sum > -k;

        if(left_ok && right_ok && ok){
            return 1;
        }

        return 0;
    }
}

int k_compreso2(PTree u, int k){//Versione migliore
    int sum = 0;
    return aux(u, k, sum);
}

int k_compreso3(PTree u, int k){//Versione di giorgia, ho tanti dubbi...
    if(u == nullptr){
        return 0;
    }
    else{
        int sum_left = k_compreso(u -> left, k);
        int sum_right = k_compreso(u -> right, k);

        return (sum_left + u -> key < k && sum_left + u -> key > -k && sum_right + u -> key < k && sum_right + u -> key > -k);
    }
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
    PTree T1 = new TreeNode(12);
    T1 -> left = new TreeNode(11);
    T1 -> left -> left = new TreeNode(9);
    T1 -> left -> right = new TreeNode(13);
    T1 -> left -> left -> right = new TreeNode(10);
    T1 -> left -> right -> left = new TreeNode(12);
    T1 -> right = new TreeNode(16);
    T1 -> right -> left = new TreeNode(14);
    T1 -> right -> left -> right = new TreeNode(15);
    T1 -> right -> right = new TreeNode(20);
    T1 -> right -> right -> right = new TreeNode(22);

    //Stampo la somma dei nodi di T1
    cout << "Somma:" << somma(T1) << endl;

    //Verifico
    int x = k_compreso2(T1, 155);

    if(x == 1) {cout << "Compreso!\n";}
    else {cout << "Non compreso!\n";}

    return 0;
}
