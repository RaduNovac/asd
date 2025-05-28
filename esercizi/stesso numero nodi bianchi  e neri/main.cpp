/*
    Dato un albero binario i cui nodi sono colorati di bianco e nero, scrivere una
    funzione efficiente che calcoli il numero di nodi aventi lo stesso numero di 
    discendenti bianchi e neri. Ricordiamo che un nodo è discendente di sé stesso.
    Analizzare la complessità della funzione.
 */
#include <iostream>

using namespace std;

struct node{
    int is_black;
    node* left;
    node* right;
    node* p;

    node(int k, node* padre = nullptr, node* sx = nullptr, node* dx = nullptr)
        : is_black{k}, p{padre}, left{sx}, right{dx} {}
}; typedef  node *pnode;

int discendenti_bianchi_neri_aux(pnode u, int& nodi){
    int sum = 0 ;
    if(u->left==nullptr&&u->right==nullptr){
        return u->is_black ? 1 : -1 ;
    }
    else{
        if(u->left!=nullptr){
            sum += discendenti_bianchi_neri_aux(u->left, nodi);
        }
        if(u->right!=nullptr){
            sum += discendenti_bianchi_neri_aux(u->right, nodi);
        }
        if(sum==0){
            nodi += 1 ;
        }
        return sum + u->is_black ? 1 : -1 ;
    }
}
int discendenti_bianchi_neri(pnode u){
    if(u==nullptr||(u->left==nullptr&&u->right==nullptr)){
        return 0 ;
    }
    else{
        int nodi = 0;
        discendenti_bianchi_neri_aux(u, nodi);
        return nodi;
    }
}

int main() {
    int x = 0;

    //Padri
    node nodo_1{0};
    node nodo_2{1,&nodo_1};
    node nodo_3{0,&nodo_1};
    node nodo_4{1,&nodo_2};
    node nodo_5{1,&nodo_2};
    node nodo_6{1,&nodo_3};
    node nodo_7{0,&nodo_3};
    node nodo_8{0,&nodo_4};
    node nodo_9{1,&nodo_4};
    node nodo_10{0,&nodo_5};
    node nodo_11{0,&nodo_5};
    node nodo_12{0,&nodo_6};
    node nodo_13{1,&nodo_6};
    node nodo_14{0,&nodo_7};
    node nodo_15{1,&nodo_7};
    //Figli
    nodo_1.left = &nodo_2;
    nodo_1.right = &nodo_3;
    nodo_2.left = &nodo_4;
    nodo_2.right = &nodo_5;
    nodo_3.left = &nodo_6;
    nodo_3.right = &nodo_7;
    nodo_4.left = &nodo_8;
    nodo_4.right = &nodo_9;
    nodo_5.left = &nodo_10;
    nodo_5.right = &nodo_11;
    nodo_6.left = &nodo_12;
    nodo_6.right = &nodo_13;
    nodo_7.left = &nodo_14;
    nodo_7.right = &nodo_15;

    x = discendenti_bianchi_neri(&nodo_1);

    cout << x << " nodi con numero di discendenti bianchi e neri uguali." << endl;

    return 0;
}
