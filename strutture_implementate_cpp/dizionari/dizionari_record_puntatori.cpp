//Dizionari implementati con record e puntatori | ASD in C++

/* 
    g++ dizionari_record_puntatori.cpp -o dizionari
    ./dizionari
*/
#include <iostream>
#include <string>

using namespace std;

struct Record {
    int key;
    string info;
    Record* next;
    Record* prev;
};

typedef Record Record;

class Dizionario{
    public:
        Record* Head;
        Dizionario(){
            Head = NULL;
        }

        void search(int k){
            //Scorro la lista fino a quando non trovo la prima occorrenza di k
            Record* tmp = Head;
            
            while(tmp != NULL){
                if(tmp -> key == k){
                    cout << "Trovato!\n";
                    return;
                }
                else{
                    tmp = tmp -> next;
                }
            }

            cout << "Non trovato!\n";
        }

        void insert(int k, string str){
            //Inserisco sempre in testa, non mi devo preoccupare dei duplicati!
            Record* r = new Record;

            r -> next = Head;

            Head = r;

            
        }

        void cancel(int k){
            //Cancella tutte le occorrenze di k
            
        }
};

int main(){
    Dizionario dizionario;

    Record* r1 = new Record;
    Record* r2 = new Record;
    Record* r3 = new Record;
    //Siccome è un puntatore uso la freccia e non il punto
    r1 -> key = 1; r1 -> info = "Radu"; r1 -> next = r2; r1 -> prev = NULL;
    r2 -> key = 2; r2 -> info = "Udar"; r2 -> next = r3; r2 -> prev = r1;
    r3 -> key = 3; r3 -> info = "Marco"; r3 -> next = NULL; r3 -> prev = r3;

    dizionario.Head = r1;
    dizionario.Head -> next = r2;
    dizionario.Head -> next -> next = r3;

    cout << dizionario.Head -> key << endl;
    cout << dizionario.Head -> next -> key << endl;
    cout << dizionario.Head -> next -> next -> key << endl;

    dizionario.search(8);

    return 0;
}