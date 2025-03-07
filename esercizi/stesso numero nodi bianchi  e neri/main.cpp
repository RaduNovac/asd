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

    node(int k, node* sx = nullptr, node* dx = nullptr)
        : is_black{k}, left{sx}, right{dx} {}
}; typedef  node *pnode;
//Versione mia
int discendenti_bianchi_neri_aux(pnode u, int& nodi){
    int sum = 0;
    /*
    Se u è una foglia, coltrolla se è bianca o nera e ritorna il valore 
    per la somma in modo che aggiunga 1 se nera, altrimenti toglie 1 se bianca
    */
    if(u -> left == nullptr && u -> right == nullptr){
        return u -> is_black ? 1 : -1;//Se u è nero ritorna 1, altrimenti -1
    }
    else{
        if(u -> left != nullptr){//Se ho un figlio sx
            sum += discendenti_bianchi_neri_aux(u -> left, nodi);
        }
        if(u -> right != nullptr){//Se ho un figlio dx
            sum += discendenti_bianchi_neri_aux(u -> right, nodi);
        }
        /*
        Se la somma è 0, vuol dire che il sottoalbero radicato in u ha lo
        stesso numero di discendenti bianchi e neri
        */
        if(sum == 0){
            nodi += 1;
        }
        return sum + u -> is_black ? 1 : -1;
    }
}
int discendenti_bianchi_neri(pnode u){
    //Se u è nullo oppure foglia
    if(u == nullptr || (u -> left == nullptr && u -> right == nullptr)){
        return 0 ;
    }
    else{//Se invece è un nodo interno
        int nodi = 0;
        discendenti_bianchi_neri_aux(u, nodi);
        return nodi;
    }
}
//Versione prof
void sameColorAux (pnode u, int& count, int& bianchi, int& neri){
    if(u){
        int bsx = 0, nsx = 0, bdx = 0 , ndx = 0;

        sameColorAux (u -> left , count , bsx , nsx );
        sameColorAux (u -> right , count , bdx , ndx );

        bianchi = bsx + bdx + (u -> is_black == 0);
        neri = nsx + ndx + (u -> is_black == 1);
        cout << "bianchi: " << bianchi << ";neri: " << neri << endl;
        if (bianchi == neri){
            count++;
        }
    }
}
int discSameColor(pnode u){
    int count = 0, bianchi = 0 , neri = 0;

    sameColorAux (u , count , bianchi , neri );

    return count;
}

int main() {
    int x = 0;

    //Padri, 1 = true = nero, 0 = false = bianco
    node nodo_1{0};
    node nodo_2{1};
    node nodo_3{0};
    node nodo_4{1};
    node nodo_5{1};
    node nodo_6{1};
    node nodo_7{0};
    node nodo_8{0};
    node nodo_9{1};
    node nodo_10{0};
    node nodo_11{0};
    node nodo_12{0};
    node nodo_13{1};
    node nodo_14{0};
    node nodo_15{1};
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

    //x = discendenti_bianchi_neri(&nodo_1);
    x = discSameColor(&nodo_1);

    cout << x << " nodi con numero di discendenti bianchi e neri uguali." << endl;

    return 0;
}
