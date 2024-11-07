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

        void print(){
            Record* tmp = Head;

            while(tmp != nullptr){
                cout << tmp ->info << endl;
                tmp = tmp -> next;
            }
        }

        string search(int k){
            //Scorro la lista fino a quando non trovo la prima occorrenza di k
            Record* tmp = Head;
            
            while(tmp != NULL && tmp -> key != k){
                tmp = tmp -> next;
            }

            if(tmp != NULL){
                return tmp -> info;
            }
            else{
                return "";
            }
        }

        void insert(int k, string v){
            //Inserisco sempre in testa, non mi devo preoccupare dei duplicati!
            Record* p = new Record;

            p -> info = v;
            p -> key = k;

            p -> next = Head;

            if(Head != NULL){
                Head -> prev = p;
            }

            p -> prev = NULL;

            Head = p;
        }

        void cancel(int k){
            //Cancella tutte le occorrenze di k
            Record *x, *tmp;

            x = Head;

            while(x != nullptr){
                if(x -> key == k){
                    if(x -> next != nullptr){//Se x ha un elemento successivo
                        x -> next -> prev = x -> prev;
                    }
                    if(x -> prev != nullptr){//Se x non è in testa
                        x -> prev -> next = x -> next;
                    }//Se x è la testa
                    else{
                        Head = x -> next;
                    }
                    
                    tmp = x;
                    x = x -> next;
                }
                else{
                    x = x -> next;
                }
            }
        }
};

int main(){
    Dizionario dizionario;

    dizionario.insert(1,"Radu");
    dizionario.insert(2,"Federico");
    dizionario.insert(3,"Alessandro");
    dizionario.insert(4,"Gioele");
    dizionario.insert(5,"Lorenzo");

    dizionario.cancel(4);

    dizionario.print();

    return 0;
}