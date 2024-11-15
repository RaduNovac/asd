//Binary Search Tree | ASD in C++

/* 
    g++ BST.cpp -o BST
    ./BST
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node* p;
    Node* left;
    Node* right;
    int Key;

    Node() : p(nullptr), left(nullptr), right(nullptr) {}
};

typedef Node Nodo;

class Albero {
    public:
        Nodo* root;

        Albero(){
            root = nullptr;
        }
        //Padre
        Nodo* padre(Nodo v){
            return v.p;
        }
};
//Algoritmo visita albero
void visita(Nodo *r){
    if(r != nullptr){
        visita(r -> left);
        cout << r->Key << " ";
        visita(r -> right);
    }
}
/*
    Ricerca ricorsiva, T(n) = O(n) worst case con albero slibanciato, 
    con albero bilanciato invece T(n) = O(log n)
*/
Node* tree_search(Nodo* r, int k){
    if(r == nullptr || r -> Key == k){
        return r;
    }
    else{
        if(r -> Key > k){
            return tree_search(r -> left, k);
        }
        else{
            return tree_search(r -> right, k);
        }
    }
}
//Complessità uguale alla versione ricorsiva
Node* tree_search_iter(Nodo r, int k){
    Nodo* tmp = &r;

    while(tmp != nullptr && tmp->Key != k){
        if(k < tmp -> Key){
            tmp = tmp -> left;
        }
        else{
            tmp = tmp -> right;
        }
    }

    return tmp;
}
//Massimo e minimo, tutti e due di complessità T(n) = O(h), con h = altezza albero
//Massimo
Node* tree_maximum(Node* r){
    Nodo* tmp = r;

    while(tmp -> right != nullptr){
        tmp = tmp -> right;
    }

    return tmp;
}
//Minimo
Node* tree_minimum(Node* r){
    Nodo* tmp = r;

    while(tmp -> left != nullptr){
        tmp = tmp -> left;
    }
    
    return tmp;
}

//Predecessore e successore, tutti e due con complessità T(n) = O(h), con h = altezza albero
//Predecessore
Node* tree_predecessor(Node* x){
    if(x -> left != nullptr){
        return tree_maximum(x -> left);
    }
    else{
        Node* y = x -> p;

        while(y != nullptr && x == y -> left){
            x = y;

            y = y -> p;
        }

        return y;
    }
}
//Successore
Node* tree_successor(Node* x){
    if(x -> right != nullptr){
        return tree_minimum(x ->right);
    }
    else{
        Node* y = x -> p;

        while(y != nullptr && x == y -> right){
            x = y;

            y = y -> p;
        }

        return y;
    }
}

//Inserimento e cancellazione
//Inserimento, T(n) = O(h), con h = altezza albero, perché seguo un percorso dalla radice verso il basso
void tree_insert(Node* root, Node z){
    Node* y = nullptr;
    Node* x = root;

    while(x != nullptr){
        y = x;

        if(z.Key < x -> Key){
            x = x -> left;
        }
        else{
            x = x -> right;
        }
    }

    z.p = y;

    if(y == nullptr){
        root = &z;
    }
    else{
        if(z.Key < y -> Key){
            y -> left = &z;
        }
        else{
            y -> right = &z;
        }
    }
}

//Cancellazione, userò una funzione ausiliaria chiamata Transplant, complessità T(n) = O(1) perché sono solo assegnazioni
void transplant(Node*& r, Node* u, Node* v){
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
//Funzione effettiva di cancellazione, T(n) = O(h), con h = altezza albero, per la chiamata a tree_minimum
void tree_delete(Node*& root, Node* z){
    if(z ->left == nullptr){
        transplant(root, z, z -> right);
    }
    else{
        if(z -> right == nullptr){
            transplant(root, z, z -> left);
        }
        else{
            Nodo *y = tree_minimum(z -> right);

            if(y -> p != z){
                transplant(root, y, y -> right);
                y -> right = z -> right;
                z -> right -> p = y;
            }

            transplant(root, z, y);
            y -> left = z -> left;
            y -> left -> p = y;
        }
    }
}

//Costruzione di BST
/*
    Partiamo da un array iniziale contenente tutti gli elementi ORDINATI
    e ritorno il nodo radice root con tutto l'albero radicato in esso
*/
//Funzione che crea un nodo
Nodo creaNodo(int n){
    Nodo x;
    //Assegno solo il valore di Key perché dal costruttore tutto il resto viene assegnato a n
    x.Key = n;

    return x;
}
//Funzione ausiliaria
Nodo* build_BST_aux(vector<int> A, int inf, int sup, Nodo* padre){
    if(inf > sup){
        return nullptr;
    }
    else{
        int med = (inf + sup) / 2;
        Nodo* r = new Nodo();
        r -> Key = A[med];
        r -> p = padre;

        r -> left = build_BST_aux(A, inf, med - 1, r);
        r -> right = build_BST_aux(A, med + 1, sup, r);

        return r;
    }
}
//Funzione effettiva
Albero build_BST(vector<int> A){
    Albero tree;

    tree.root = build_BST_aux(A, 0, A.size()-1, nullptr);

    return tree;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};  // Array di interi
    vector<int> vettore(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Albero albero = build_BST(vettore);

    //visita(albero.root);

    Nodo* n1 = tree_search(albero.root, 5);

    Nodo* succ = tree_successor(n1);

    cout << "Il successore del nodo con Key = " << n1 -> Key << " e': " << succ -> Key << endl;

    Nodo* prec = tree_predecessor(n1);

    cout << "Il predecessore del nodo con Key = " << n1 -> Key << " e': " << prec -> Key << endl;

    Nodo* max = tree_maximum(n1);

    cout << "Il valore massimo dell'albero e': " << max -> Key  << endl;

    Nodo* min = tree_minimum(n1);

    cout << "Il valore minimo dell'albero e': " << min -> Key  << endl;

    return 0;
}