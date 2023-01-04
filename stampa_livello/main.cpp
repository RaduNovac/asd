#include <iostream>
#include<stack>

using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node* p;

    node(int k, node* padre = nullptr, node* sx = nullptr, node* dx = nullptr)
            : key{k}, p{padre}, left{sx}, right{dx} {}
}; typedef node* pnode;

void stampa_livello(pnode u, int k){
    if(u != nullptr){//Se l'albero non è vuoto
        if(k == 0){
            cout << u -> key;
        }
        else{
            stampa_livello(u -> left, k-1);
            stampa_livello(u -> right, k-1);
        }
    }
}

int main() {
    //Albero 3_bilanciato
    node nodo_1{1};
    node nodo_2{2,&nodo_1};
    node nodo_3{3,&nodo_1};
    node nodo_4{4,&nodo_2};
    node nodo_5{5,&nodo_3};
    node nodo_6{6,&nodo_3};
    node nodo_7{7,&nodo_4};

    nodo_1.left = &nodo_2;
    nodo_1.right = &nodo_3;
    nodo_2.left = &nodo_4;
    nodo_2.right = &nodo_5;
    nodo_3.right = &nodo_6;
    nodo_4.right = &nodo_7;

    stampa_livello(&nodo_1,2);

    return(0);
}
