#include <iostream>

using namespace std;

struct node{
    int key;
    node* p = nullptr;
    node* left = nullptr;
    node* right = nullptr;

    node(int k = 0)
        : key{k} {}
}; typedef  node *pnode;

struct Tree {
    pnode root;
}; typedef Tree * ptree;

void rimuovi(pnode u){
    if (u != nullptr){
        rimuovi (u -> left);
        rimuovi (u -> right);
        delete u;
    }
}

void transplant(pnode& r, pnode u, pnode v){
    if(u -> p == nullptr){
        r = v;
    }
    else{
        if(u == u -> p -> left){//Se u è figlio sx di suo padre
            u -> p -> left = v;//v diventa figlio x del padre di u
        }
        else{//Se u è figlio dx di suo padre
            u -> p -> right = v;//v diventa figlio dx del padre di u
        }
    }
    if(v != nullptr){
        v -> p = u -> p;
    }
}

void eliminaMaggioriK(ptree t , int k){
    pnode iter, temp;
    iter = t -> root ;
    while (iter -> key != k){
        if(iter -> key > k){
            rimuovi (iter -> right);
            iter -> right = nullptr;
            temp = iter ;

            transplant (t -> root, iter, iter -> left);
            iter = iter -> left;

            delete temp;
            }
        else{
            iter = iter -> right;
        }
    }
    rimuovi(iter -> right);
    iter -> right = nullptr ;
}

//Algoritmo visita albero
void visita(pnode r){
    if(r != nullptr){
        visita(r -> left);
        cout << r->key << " ";
        visita(r -> right);
    }
}

int main(){
    ptree t = new Tree;

    pnode nodo_1 = new node{15};
    pnode nodo_2 = new node{7};
    pnode nodo_3 = new node{3};
    pnode nodo_4 = new node{20};
    pnode nodo_5 = new node{17};
    pnode nodo_6 = new node{25};
    pnode nodo_7 = new node{21};

    nodo_1->left = nodo_2;
    nodo_1->right = nodo_4;

    nodo_2->left = nodo_3;

    nodo_4->left = nodo_5;
    nodo_4->right = nodo_6;

    nodo_6->left = nodo_7;

    //padri
    nodo_3 -> p = nodo_2;
    nodo_2 -> p = nodo_1;
    nodo_4 -> p = nodo_1;
    nodo_5 -> p = nodo_4;
    nodo_6 -> p = nodo_4;
    nodo_7 -> p = nodo_6;

    t->root = nodo_1;

    //visita prima
    visita(t -> root);

    eliminaMaggioriK(t, 17);
    cout << endl;

    //visita dopo
    visita(t -> root);

    return 0;
}