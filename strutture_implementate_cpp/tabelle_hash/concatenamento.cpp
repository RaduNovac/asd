//Tabelle hash - concatenamento | ASD in C++

/* 
    g++ concatenamento.cpp -o concatenamento
    ./concatenamento
*/

#include <iostream>

using namespace std;

struct Record {
    int key;
    Record* next;

    Record(): key(-1), next(nullptr){}
};

typedef Record Record;

//Funzione hash molto basic
int h(int key, int size){
    return key % size;
}
//Inserisce x in testa alla lista T[h(x.key)]
void chained_hash_insert(Record* T[], int x, int size){
    Record* tmp = new Record;//record che inserirò

    tmp -> key = x;

    int indice = h(x, size);//indice della lista dove inserisco x

    tmp -> next = T[indice];//inserendo in testa faccio puntare il record nuovo all'elemento che c'era già

    T[indice] = tmp;//la testa della lista sarà tmp
}

void print_lista(Record* x){
    Record* tmp = x;

    while(tmp != nullptr){
        cout << "key: " << tmp -> key << endl;

        tmp = tmp -> next;
    }
}

int main(){
    const int SIZE = 1000;

    Record* T[SIZE] = {nullptr};//All'inizio tutte le caselle sono nullptr

    chained_hash_insert(T, 1, 1000);
    chained_hash_insert(T, 2, 1000);
    chained_hash_insert(T, 3, 1000);
    chained_hash_insert(T, 2, 1000);

    print_lista(T[h(3, 1000)]);

    return 0;
}