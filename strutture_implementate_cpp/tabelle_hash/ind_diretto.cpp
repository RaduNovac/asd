//Tabelle ad indirizzamento diretto | ASD in C++

/* 
    g++ ind_diretto.cpp -o ind_diretto
    ./ind_diretto
*/

#include <iostream>

using namespace std;

struct Node {
    int Key;

    Node(): Key(-1){}
};

typedef Node Nodo;

Nodo* direct_address_search(Nodo* T[], int k){
    return T[k];
}

void direct_address_insert(Nodo* T[], Nodo* x){
    T[x -> Key] = x;
}

void direct_address_delete(Nodo* T[], Nodo x){
    T[x.Key] = nullptr;
}

int main(){
    const int SIZE = 10;
    Nodo* T[SIZE] = {nullptr};

    Nodo* n1 = new Nodo;
    n1 ->Key = 0;
    Nodo* n2 = new Nodo;
    n2 ->Key = 1;
    Nodo* n3 = new Nodo;
    n3 ->Key = 2;
    Nodo* n4 = new Nodo;
    n4 ->Key = 3;
    /*Nodo* n5 = new Nodo;
    n5 ->Key = 4;
    Nodo* n6 = new Nodo;
    n6 ->Key = 5;
    Nodo* n7 = new Nodo;
    n7 ->Key = 6;
    Nodo* n8 = new Nodo;
    n8 ->Key = 7;
    Nodo* n9 = new Nodo;
    n9 ->Key = 8;*/
    Nodo* n10 = new Nodo;
    n10 ->Key = 9;

    direct_address_insert(T, n1);
    direct_address_insert(T, n2);
    direct_address_insert(T, n3);
    direct_address_insert(T, n4);
    /*direct_address_insert(T, n5);
    direct_address_insert(T, n6);
    direct_address_insert(T, n7);
    direct_address_insert(T, n8);
    direct_address_insert(T, n9);*/
    direct_address_insert(T, n10);

    direct_address_delete(T, *n3);
    //direct_address_delete(T, *n7);

    for(int i = 0; i < SIZE; i++) {
        if(T[i] != nullptr) {
            cout << "Indice " << i << ": " << T[i]->Key << endl;
        } else {
            cout << "Indice " << i << ": VUOTO" << endl;
        }
    }

    Nodo* cercato = direct_address_search(T, 7);

    if(cercato != nullptr){
        cout << "Hai cercato la chiave: " << cercato->Key << " con esito positivo!\n";
    }
    else{
        cout << "Hai cercato una chiave con esito negativo!\n";
    }

    return 0;
}