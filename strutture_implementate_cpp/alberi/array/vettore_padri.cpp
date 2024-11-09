//Albero implementato con il vettore dei padri | ASD in C++

/* 
    g++ vettore_padri.cpp -o vettore_padri
    ./vettore_padri
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string info;
    int parent;
};

typedef Node Nodo;

class Albero {
    public:
        Nodo* P;
        int length;

        Albero(){
            length = 0;
            P = (Nodo*) malloc(length * sizeof(Nodo));
        }

        //Stampare l'albero
        void stampaAlbero(){
            for(int i = 0;i < length;i++){
                cout << "Indice: " << i << "\nP.info = " << P[i].info << "\nP.parent = " << P[i].parent << endl << endl;
            }
        }

        //Aggiungere un nodo
        void aggiungiNodo(string info, int parent){
            //Aumento di uno la grandezza
            length++;

            //Rialloco il vettore con una grandezza in più per il nuovo nodo
            Nodo* TMP = (Nodo*)realloc(P,(length + 1) * sizeof(Nodo));

            if(TMP != NULL){
                //Ricopio i valori dentro al nuovo vettore
                P = TMP;

                //Aggiungo in coda il nuovo nodo
                P[length - 1].info = info;
                P[length - 1].parent = parent;
            }
        }

        //Padre
        Nodo* padre(int v){
            if(P[v].parent == -1){
                return nullptr;
            }
            else{
                return &P[P[v].parent];
            }
        }
        //Figli

};

int main() {
    Albero albero;

    albero.aggiungiNodo("paperino", -1);
    //Figli di paperino
    albero.aggiungiNodo("qui", 0);
    albero.aggiungiNodo("quo", 0);
    albero.aggiungiNodo("qua", 0);
    //Figli di qui
    albero.aggiungiNodo("qui_f1", 1);
    albero.aggiungiNodo("qui_f2", 1);
    albero.aggiungiNodo("qui_f3", 1);
    //Figli di quo
    albero.aggiungiNodo("quo_f1", 2);
    albero.aggiungiNodo("quo_f2", 2);
    albero.aggiungiNodo("quo_f3", 2);
    //Figli di qua
    albero.aggiungiNodo("qua_f1", 3);
    albero.aggiungiNodo("qua_f2", 3);
    albero.aggiungiNodo("qua_f3", 3);

    albero.stampaAlbero();
    
    return 0;
}