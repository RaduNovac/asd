/*
Dato un albero binario di ricerca T, scrivere un algoritmo 
efficiente che restituisca il numero di elementi che occorrono una sola volta.
*/
#include <iostream>

using namespace std;

struct node{
    int key;
    node* left = nullptr;
    node* right = nullptr;
    node* p = nullptr;

    node(int k = 0)
        : key{k} {}
}; typedef  node *pnode;

struct Tree {
    pnode root;
}; typedef Tree * ptree;

//Minimo
pnode tree_minimum(pnode r){
    pnode tmp = r;

    while(tmp -> left != nullptr){
        tmp = tmp -> left;
    }
    
    return tmp;
}
//Successore
pnode tree_successor(pnode x){
    if(x -> right != nullptr){
        return tree_minimum(x ->right);
    }
    else{
        pnode y = x -> p;

        while(y != nullptr && x == y -> right){
            x = y;

            y = y -> p;
        }

        return y;
    }
}

int contaDistinti (ptree t){
    int numDistinti = 0, count = 1 , val;
    pnode iter;

    if (t -> root == nullptr ){
        return 0;
    }

    iter = tree_minimum(t -> root);
    val = iter -> key;
    iter = tree_successor(iter);

    while(iter != nullptr){
        if(iter -> key == val){
            count++;
        }
        else{
            if(count == 1){
                numDistinti++;
            }
            count = 1;
            val = iter -> key;
        }
        iter = tree_successor(iter);
    }
    //Controllo per il caso di albero con una sola foglia
    if(count == 1){
        numDistinti++;
    }

    return numDistinti;
}

int main() {
    ptree t = new Tree;

    pnode nodo_1 = new node{10};
    pnode nodo_2 = new node{7};
    pnode nodo_3 = new node{15};
    pnode nodo_4 = new node{10};
    pnode nodo_5 = new node{15};
    pnode nodo_6 = new node{15};
    pnode nodo_7 = new node{20};

    nodo_1->left = nodo_2;
    nodo_1->right = nodo_3;

    nodo_2->right = nodo_4;
    nodo_2->p = nodo_1;

    nodo_3->left = nodo_5;
    nodo_3->right = nodo_6;
    nodo_3->p = nodo_1;

    nodo_4->p = nodo_2;

    nodo_5->p = nodo_3;

    nodo_6->right = nodo_7;
    nodo_6->p = nodo_3;

    nodo_7->p = nodo_6;

    t->root = nodo_1;

    int x = contaDistinti(t);

    cout << "num nodi distinti: " << x << endl;

    return 0;
}