//Dizionari implementati con record e puntatori | ASD in C++

/* 
    g++ vettore_posizionale.cpp -o vettore_posizionale
    ./vettore_posizionale
*/

#include <iostream>
#include <string>
#include <cmath>
#include <list>

using namespace std;

struct Node {
    string info;
};

typedef Node Nodo;

class Albero {
    public:
        Nodo* P;
        int length, K;

        Albero(){
            length = 0;
            P = (Nodo*) malloc(length * sizeof(Nodo));
            K = 3;
        }

        void stampaAlbero(){
            for(int i = 0;i < length; i++){
                cout << "P[" << i << "].info = " << P[i].info << endl;
            }
        }

        int findIndex(string info){
            for(int i = 0; i < length; i++){
                if(P[i].info == info){
                    return i;
                }
            }

            return -1;
        }

        void aggiungiNodo(string info){
            //Nuovo nodo da inserire
            Node tmp;
            tmp.info = info;

            //Aumento di uno la grandezza
            length++;

            //Rialloco il vettore con una grandezza in più per il nuovo nodo
            Nodo* TMP = (Nodo*)realloc(P,(length + 1) * sizeof(Nodo));

            //Se è  andato a buon fine l'allocamento di TMP
            if(TMP){
                //Ricopio i valori dentro al nuovo vettore
                P = TMP;

                //Aggiungo in coda il nuovo nodo
                P[length - 1].info = info;
            }
        }

        int padre(int v){
            if(v == 0){
                return -1;
            }
            else{
                return floor((v - 1)/ K);
            }
        }

        //Figli
        list<Nodo> figli(int v){
            //Lista nella quale inserirò i figli
            list<Nodo> l;

            if(v * K + 1 >= length){
                    return l;
                }
                else{
                    for(int i = 0; i < K; i++){
                        l.push_back(P[v * K + 1 + i]);
                    }
                }

            return l;
        }

        void printFigli(list<Nodo> l){
            cout << "Lista dei figli:\n";

            for (Nodo i : l) {
                cout << "Nodo: " << i.info << endl;
            }
        }

};

int main() {
    Albero albero;

    albero.aggiungiNodo("a");
    albero.aggiungiNodo("b");
    albero.aggiungiNodo("c");
    albero.aggiungiNodo("d");
    albero.aggiungiNodo("e");
    albero.aggiungiNodo("f");
    albero.aggiungiNodo("g");
    albero.aggiungiNodo("h");
    albero.aggiungiNodo("i");
    albero.aggiungiNodo("l");
    albero.aggiungiNodo("m");
    albero.aggiungiNodo("n");
    albero.aggiungiNodo("o");

   // cout << "Padre di o: " << albero.P[albero.padre(albero.findIndex("o"))].info << endl; 

    cout << "Figli di b:\n";
    albero.printFigli(albero.figli(albero.findIndex("b")));

    return 0;
}