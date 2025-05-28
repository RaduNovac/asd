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


void visita_DFS(node *u){
    if(u != nullptr){
        cout << u->key;
        visita_DFS(u->left);
        visita_DFS(u->right);
    }
}

int main() {
    node nodo_1{0};
    node nodo_2{2,&nodo_1};
    node nodo_3{3,&nodo_1};
    node nodo_4{1,&nodo_2};
    node nodo_5{-1,&nodo_2};

    nodo_1.left = &nodo_2;
    nodo_1.right = &nodo_3;
    nodo_2.left = &nodo_4;
    nodo_2.right = &nodo_5;

    visita_DFS(&nodo_1);

    return(0);
}
