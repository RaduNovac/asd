#include <iostream>

using namespace std;

/*
scrivere una funzione efficiente in C o C++ che ritorna il numero di nodi per i quali la chiave
x->key è minore o uguale dell’altezza del nodo. Il prototipo della funzione è:
int lessHeight(PNode r)
*/

struct node{
    int key;
    node* left = nullptr;
    node* right = nullptr;

    node(int k = 0)
        : key{k} {}
}; typedef  node *pnode;

struct Tree {
    pnode root;
}; typedef Tree *ptree;

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

int less_height_aux(pnode r, int &contatore)
{
    if(r){//Se il nodo è != nullptr
        //Chiamo ricorsivamente sui sottoalberi sx e dx fino a quando non arrivo dopo le foglie
        int h_sx = less_height_aux(r -> left, contatore);
        int h_dx = less_height_aux(r -> right, contatore);

        //cout << "nodo: " << r -> key << ", h: " << max(h_sx, h_dx) << endl;

        //Se l'altezza del sottoalbero radicato in r soddisfa la condizione
        if(r -> key <= max(h_sx, h_dx)){
            contatore++;
        }
        /*
        salgo di un livello sull'albero e sommo 1 all'altezza del nodo, 
        che è il massimo tra le altezze dei sottoalberi dx ed sx
        */
        return 1 + max(h_sx, h_dx);
    }
    else{
        return 0;
    }
}

int less_height(pnode r)
{
    int contatore = 0;
    less_height_aux(r, contatore);
    return contatore;
}

void print_tree(pnode root, int level = 0)
{
    if (root == nullptr) // Use nullptr instead of NIL
        return;

    // Print indentation based on the tree level
    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << root->key << endl;

    // Recursive call for left child (increase level for indentation)
    print_tree(root->left, level + 1);

    // Recursive call for right child (same level)
    print_tree(root->right, level + 1);
}

int main()
{
    ptree t1 = new Tree;
    ptree t2 = new Tree;

    // Albero t1:

    pnode t1_n1 = new node{3};
    pnode t1_n2 = new node{2};
    pnode t1_n3 = new node{4};
    pnode t1_n4 = new node{1};
    pnode t1_n5 = new node{9};
    pnode t1_n6 = new node{2};
    pnode t1_n7 = new node{3};
    pnode t1_n8 = new node{2};
    pnode t1_n9 = new node{1};
    pnode t1_n10 = new node{0};

    // Collegamenti
    t1_n1 -> left = t1_n2;
    t1_n1 -> right = t1_n3;

    t1_n2 -> left = t1_n4;
    t1_n3 -> left = t1_n5;
    t1_n3 -> right = t1_n6;

    t1_n4 -> left = t1_n7;
    t1_n4 -> right = t1_n8;

    t1_n6 -> right = t1_n9;

    t1_n9 -> right = t1_n10;

    t1 -> root = t1_n1;

    // Albero t2:

    pnode t2_n1 = new node{3};
    pnode t2_n2 = new node{2};
    pnode t2_n3 = new node{7};
    pnode t2_n4 = new node{9};
    pnode t2_n5 = new node{4};
    pnode t2_n6 = new node{5};
    pnode t2_n7 = new node{3};
    pnode t2_n8 = new node{4};
    pnode t2_n9 = new node{3};
    pnode t2_n10 = new node{4};

    // Collegamenti
    t2_n1 -> left = t2_n2;
    t2_n1 -> right = t2_n3;

    t2_n2 -> left = t2_n4;
    t2_n3 -> left = t2_n5;
    t2_n3 -> right = t2_n6;

    t2_n4 -> left = t2_n7;
    t2_n4 -> right = t2_n8;

    t2_n6 -> right = t2_n9;

    t2_n9 -> right = t2_n10;

    t2 -> root = t2_n1;

    //Esecuzione su t1
    //print_tree(t1 -> root);

    cout << "Less Height Counter t1 = " << less_height(t1 -> root) << endl;

    //Esecuzione su t2
    //print_tree(t2 -> root);

    cout << "Less Height Counter t2 = " << less_height(t2 -> root) << endl;

    return 0;
}