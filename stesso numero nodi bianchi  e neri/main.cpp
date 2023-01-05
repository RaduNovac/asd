/*
 * Funzione efficiente che calcoli il n° di nodi avente lo stesso n° di discendenti bianchi e neri.
 * */
#include <iostream>

using namespace std;

struct node{
    int isBlack;
    node* left;
    node* right;
    node* p;

    node(int c, node* padre = nullptr, node* sx = nullptr, node* dx = nullptr)
        : isBlack{c}, p{padre}, left{sx}, right{dx} {}
}; typedef  node *pnode;

int conta_uguali_aux(pnode u, int &num_b, int &num_n){
    int nodeSameNumOfDisc_sx, nodeSameNumOfDisc_dx, nodeSameNumOfDisc;

    if(u == nullptr){
        num_b = 0;
        num_n = 0;
        return 0;
    }
    int discB_dx, discB_sx, discN_dx, discN_sx;
    nodeSameNumOfDisc_sx = conta_uguali_aux(u -> left, discB_sx, discN_sx);
    nodeSameNumOfDisc_dx = conta_uguali_aux(u -> right, discB_dx, discN_dx);

    nodeSameNumOfDisc = nodeSameNumOfDisc_sx + nodeSameNumOfDisc_dx;

    num_b = discB_sx + discB_dx;
    num_n = discN_sx + discN_dx;

    num_b = u ->isBlack == 1 ? num_b+1 : num_b;
    num_n = u ->isBlack == 0 ? num_n+1 : num_n;

    if (num_n ==  num_b){
        return nodeSameNumOfDisc + 1;
    }
    else{
        return nodeSameNumOfDisc;
    }
}

int conta_uguali(pnode u){
    int num_b, num_n;

    return conta_uguali_aux(u,num_b, num_n);
}

int main() {
    int x;

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
    node nodo_15{1,&nodo_8};
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

    x = conta_uguali(&nodo_1);

    cout << x << " nodi con numero di discendenti bianchi e neri uguali." << endl;

    return 0;
}
