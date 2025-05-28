#include <iostream>

using namespace std;

/*
Si scriva una procedura efficiente in C o C++ che assegni True al campo fruitful 
del nodo se e solo se la somma delle chiavi dei nodi di ciascuno dei sottoalberi 
radicati nei figli è maggiore di una costante k fornita in input. 
Il prototipo della procedura è:
void set_fruitful(PTNode r, int k)
*/

struct node{
    int key;
    bool fruitful = false;
    node* left = nullptr;
    node* center = nullptr;
    node* right = nullptr;

    node(int k = 0) : key{k} {}
}; typedef  node *pnode;

struct Tree {
    pnode root;
}; typedef Tree *ptree;

/*
Scorro fino alle foglie e mi faccio ritornare la somma delle key dei figli di ogni nodo
*/
int aux(pnode r, int k){
    if(r){
        int sx = aux(r -> left, k);
        int cx = aux(r -> center, k);
        int dx = aux(r -> right, k);

        if(sx + cx + dx > k){
            r -> fruitful = true;
        }
        /*
        Sommo key perché al suo nodo superiore devo ritornare la somma dei
        suoi sottoalberi + il valore della sua chiave, altrimenti escluderei
        un valore e sarebbe sbagliato!
        */
        return sx  + cx + dx + r -> key; 
    }

    return 0;
}

void set_fruitful(pnode r, int k){
    aux(r, k);
}

void print_fruitful_tree(pnode r){
    if(r){
        if(r -> fruitful){
            cout << "nodo: " << r -> key << " is fruitful\n";
        }

        print_fruitful_tree(r -> left);
        print_fruitful_tree(r -> center);
        print_fruitful_tree(r -> right);
    }
}

int main()
{
    /*
    t1:
                 1                 <-- Livello 0 (Radice)
             /   |   \
           2     3     4           <-- Livello 1
         / | \   |    /  \
        5  6  7  8    9  10        <-- Livello 2
       /         |        | \
     11         12       13 14     <-- Livello 3
    */
    ptree t1 = new Tree;

    pnode t1_n1 = new node{1};
    pnode t1_n2 = new node{2};
    pnode t1_n3 = new node{3};
    pnode t1_n4 = new node{4};
    pnode t1_n5 = new node{5};
    pnode t1_n6 = new node{6};
    pnode t1_n7 = new node{7};
    pnode t1_n8 = new node{8};
    pnode t1_n9 = new node{9};
    pnode t1_n10 = new node{10};
    pnode t1_n11 = new node{11};
    pnode t1_n12 = new node{12};
    pnode t1_n13 = new node{13};
    pnode t1_n14 = new node{14};

    t1_n1 -> left = t1_n2;
    t1_n1 -> center = t1_n3;
    t1_n1 -> right = t1_n4;

    t1_n2 -> left = t1_n5;
    t1_n2 -> center = t1_n6;
    t1_n2 -> right = t1_n7;

    t1_n3 -> center = t1_n8;

    t1_n4 -> left = t1_n9;
    t1_n4 -> right = t1_n10;

    t1_n5 -> left = t1_n11;

    t1_n8 -> center = t1_n12;

    t1_n10 -> center = t1_n13;
    t1_n10 -> right = t1_n14;

    t1 -> root = t1_n1;

    set_fruitful(t1 -> root, 12);

    print_fruitful_tree(t1 -> root);

    return 0;
}