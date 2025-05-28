//Dizionari implementati con array ordinati | ASD in C++

/* 
    g++ dizionari_array_ordinati.cpp -o dizionari
    ./dizionari
*/

#include <iostream>
#include <string>

using namespace std;

struct Coppia {
    int key;
    string info;
};

typedef Coppia Coppia;

class Dizionario {
    public:
        Coppia* A;
        int length;

        Dizionario(){
            length = 0;
            A = (Coppia*) malloc(length * sizeof(Coppia));
        }
        //Stampa
        void stampa(){
            cout << "\nIl vettore A:\n";

            for(int i = 0; i < length; i++){
                cout << "A["<< i <<"]: key = " << A[i].key << ", info = " << A[i].info << endl;
            }
        }

        //Ricerca
        void search(int k){
            int i = search_index(k, 0, length);

            if(i != -1){
                cout << "Trovato! " << A[i].info << endl;
            }
            else{
                cout << "Elemento non presente!\n";
            }
        }

        int search_index(int k, int l, int r){
            if(r < l){
                return -1;
            }
            else{
                int mid = (l + r) / 2;

                if(A[mid].key == k){
                    return mid;
                }
                else{
                    if(A[mid].key > k){
                        return search_index(k, l, mid - 1);
                    }
                    else{
                        return search_index(k, mid + 1, r);
                    }
                }
            }
        }
        //Inserimento
        void insert(int k, string info) {
            int i = 0;
            //trovo l'indice del record avente chiave k
            while(i <= length && A[i].key < k){
                i = i + 1;
            }
            //Se c'è già, aggiorno il campoinfo
            if(i <= length && A[i].key == k){
                A[i].info = info;
            }
            //Altrimenti rialloco il vettore e shifto tutti gli elementi a dx di 1
            else{
                int pos = 0;

                //Creo la nuova coppia con i valori
                Coppia nuovaCoppia = {k, info};
                
                //Trovo la posizione dove inserirlo
                while(pos < length && A[pos].key < k) {
                    pos++;
                }
                //Creo un nuovo vettore di dimensione + 1

                Coppia* TMP = (Coppia*)realloc(A,(length + 1) * sizeof(Coppia));

                //Se l'allocazione del nuovo vettore è andata a buon fine
                if(TMP != NULL){
                    //Aumento numeroElementi di 1
                    length++;

                    //Ricopio i valori dentro al nuovo vettore

                    A = TMP;

                    A[length - 1] = A[length - 2];//Riempio l'ultima coppia

                    //Shifto dalla posizione dove devo inserire a dx di 1 tutti gli elementi
                    for(int i = length - 1; i > pos; i--){
                        A[i] = A[i - 1];
                    }

                    //Inserisco nella posizione corretta

                    A[pos] = nuovaCoppia;
                }
            }
        }
        //Cancellazione
        void cancel(int k){
            //Cerco l'indice della chiave key
            int index = search_index(k, 0, length);
            
            //Shifto a sx di 1 gli elementi > di key
            for(int i = index; i < length - 1; i++){
                A[i].key = A[i + 1].key;
                A[i].info = A[i + 1].info;
            }
            //Rialloco lo spazio a numeroElementi - 1
            Coppia* TMP = (Coppia*)realloc(A,(length - 1) * sizeof(Coppia));

            //Se il realloc va a buon fine
            if(TMP != NULL){
                length--;

                A = TMP;
            }
        }
};

int main() {
    Dizionario dizionario;

    if(!dizionario.A){
        cout << "Assegnazione vettore S NON andata a buon fine!\n";
        exit(1);
    }
    
    dizionario.insert(5,"Giacomo");
    dizionario.insert(2,"Alberto");
    dizionario.insert(3,"Paolo");
    dizionario.insert(1,"Radu");
    dizionario.insert(4,"Matteo");
    dizionario.insert(6,"Lorenzo");
    dizionario.insert(9,"Aldo");
    dizionario.insert(8,"Giovanni");
    dizionario.insert(7,"Ermanno");

    dizionario.cancel(6);

    dizionario.stampa();
    return 0;
}