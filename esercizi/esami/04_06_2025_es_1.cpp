#include <iostream>

using namespace std;

struct NodeG {
    int key;
    NodeG* left_child;
    NodeG* right_sib;

    NodeG(int k): key(k), left_child(nullptr), right_sib(nullptr) {}
};

typedef NodeG* PNodeG;

// Funzione ricorsiva di supporto
int contaIntermedi(PNodeG nodo, int sommaPercorso, int& conta){
    if(!nodo) return 0;

    // Somma dei nodi sul cammino verso la radice (escluso nodo corrente)
    int newSommaPercorso = sommaPercorso;

    // Calcolo somma del sottoalbero
    int sommaSottoalbero = nodo->key;
    for(PNodeG f = nodo->left_child; f != nullptr; f = f->right_sib){
        sommaSottoalbero += contaIntermedi(f, newSommaPercorso + nodo->key, conta);
    }

    // Verifica condizione di "nodo intermedio"
    if(sommaSottoalbero == newSommaPercorso){
        conta++;
    }

    return sommaSottoalbero;
}

int intermedi(PNodeG u){
    int conta = 0;
    contaIntermedi(u, 0, conta);
    return conta;
}

int main(){
    //Albero 1
    PNodeG r1 = new NodeG(6);
    PNodeG a1 = new NodeG(3);
    PNodeG b1 = new NodeG(4);
    PNodeG c1 = new NodeG(5);
    PNodeG d1 = new NodeG(2);
    PNodeG e1 = new NodeG(1);
    PNodeG f1 = new NodeG(1);

    r1 -> left_child = a1;
    a1 -> left_child = d1;

    a1 -> right_sib = b1;
    b1 -> right_sib = c1;

    d1 -> right_sib = e1;

    c1 -> left_child = f1;
    //Albero 2
    PNodeG r2 = new NodeG(10);
    PNodeG a2 = new NodeG(3);
    PNodeG b2 = new NodeG(5);
    PNodeG c2 = new NodeG(7);
    PNodeG d2 = new NodeG(1);
    PNodeG e2 = new NodeG(6);
    PNodeG f2 = new NodeG(2);
    PNodeG g2 = new NodeG(2);
    PNodeG h2 = new NodeG(1);

    r2 -> left_child = a2;

    a2 -> right_sib = b2;
    b2 -> right_sib = c2;

    a2 -> left_child = d2;
    d2 -> right_sib = e2;

    b2 -> left_child = f2;

    c2 -> left_child = g2;
    g2 -> right_sib = h2;

    cout << "Numero nodi intermedi: " << intermedi(r1) << endl;

    return 0;
}