#include <iostream>

using namespace std;

struct node{
    int key;
    node* left = nullptr;
    node* right = nullptr;

    node(int k = 0)
        : key{k} {}
}; typedef  node *pnode;

struct Tree {
    pnode root;
}; typedef Tree * ptree;

int aux(pnode r, int h){
    if(r == nullptr) return 0;

    int count = 0;

    if(r -> key <= h) count = 1;
    else{
        count = 0;
    }

    count += aux(r -> left, h + 1);
    count += aux(r -> right, h + 1);

    return count;
}

int lessHeight(pnode r){
    return aux(r, 1);
}

int main(){
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

    
    cout << "Numero nodi che soddisfano la condizione: " << lessHeight(t1 -> root) << endl;

    return 0;
}