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

bool check(ptree t){
    pnode iter, succ;
    bool ok  = true;
    iter = t -> root;

    if(iter == nullptr){
        return true ; // Condizione vacuamente vera
    }

    iter = tree_minimum(iter);

    while(iter != nullptr && ok == true){
        succ = tree_successor(iter);
        if(succ != nullptr && succ -> key == iter -> key + 2){//Quindi manca k + 1
            ok = false;
        }
        else{
            iter = succ;
        }
    }

    return ok;
}

int main(){
    ptree t1 = new Tree;
    ptree t2 = new Tree;

    // Albero t1:
    //      15
    //     /  \
    //   11    21
    //        /  \
    //      18    35

    pnode t1_n15 = new node{15};
    pnode t1_n11 = new node{11};
    pnode t1_n21 = new node{21};
    pnode t1_n18 = new node{18};
    pnode t1_n35 = new node{35};

    // Collegamenti
    t1_n15->left = t1_n11;
    t1_n11->p = t1_n15;

    t1_n15->right = t1_n21;
    t1_n21->p = t1_n15;

    t1_n21->left = t1_n18;
    t1_n18->p = t1_n21;

    t1_n21->right = t1_n35;
    t1_n35->p = t1_n21;

    t1->root = t1_n15;

    // Albero t2:
    //      13
    //     /  \
    //   11    21
    //        /  \
    //      18    35

    pnode t2_n13 = new node{13};
    pnode t2_n11 = new node{11};
    pnode t2_n21 = new node{21};
    pnode t2_n18 = new node{18};
    pnode t2_n35 = new node{35};

    // Collegamenti
    t2_n13->left = t2_n11;
    t2_n11->p = t2_n13;

    t2_n13->right = t2_n21;
    t2_n21->p = t2_n13;

    t2_n21->left = t2_n18;
    t2_n18->p = t2_n21;

    t2_n21->right = t2_n35;
    t2_n35->p = t2_n21;

    t2->root = t2_n13;

    // Opzionale: test della funzione check()
    cout << "Check t1: " << (check(t1) ? "OK" : "NO") << endl;
    cout << "Check t2: " << (check(t2) ? "OK" : "NO") << endl;

    return 0;
}