//Dizionari implementati con array ordinati versione vecchia MA FUNZIONA| ASD in C++

/* 
    g++ dizionari_array_ordinati_old.cpp -o dizionari
    ./dizionari
*/

#include <iostream>
#include <string>

using namespace std;

struct Coppia {
    int key;
    string valore;
};

typedef Coppia Coppia;

class Dizionario {
    public:
        Coppia* S;
        int numeroElementi;

        Dizionario(){
            numeroElementi = 0;
            S = (Coppia*) malloc(numeroElementi * sizeof(Coppia));
        }
        //Stampa
        void stampa(){
            cout << "\nIl vettore S:\n";

            for(int i = 0; i < numeroElementi; i++){
                cout << "S["<< i <<"]: " << S[i].key << ", " << S[i].valore << endl;
            }
        }

        //Ricerca
        void search(int key){
            if(search_index(key) != -1){
                cout << "Trovato!\n";
            }
            else{
                cout << "Elemento non presente!\n";
            }
        }

        int search_index(int key){
            return search_index_aux(key, 0, numeroElementi - 1);
        }

        int search_index_aux(int key, int left, int right){
            //Se l'indice sx è > di quello dx, cioè non ho un range valido
            if(left > right) {
                return -1;
            }
            //Trovo l'indice di mezzo
            int mid = left + (right - left) / 2;

            //Se ho trovato l'elemento
            if(S[mid].key == key){
                return mid;
            } 
            //Se il mio valore è maggiore, cerco nella parte dx
            else if(S[mid].key < key){
                return search_index_aux(key, mid + 1, right);
            }
            //Altrimenti è <= e cerco nella parte sx
            else{
                return search_index_aux(key, left, mid - 1);
            }
        }
        //Inserimento
        void insert(int key, string valore) {
            //Se la chiave che voglio inserire c'è già la aggiorno, altrimenti la aggiungo trovando la posizione, ingrandendo il vettore di 1 posizione e shiftando tutto di 1 a dx

            int posizione = search_index(key);

            if(posizione != -1){//Se è già presente la aggiorno
                cout << "Già presente! Provvedo ad aggiornare il valore...\n";

                S[posizione].valore = valore;
            }
            else{//Altrimenti inserisco una nuova coppia
                int pos = 0;

                //Creo la nuova coppia con i valori
                Coppia nuovaCoppia = {key, valore};
                
                //Trovo la posizione dove inserirlo
                while(pos < numeroElementi && S[pos].key < key) {
                    pos++;
                }
                //Creo un nuovo vettore di dimensione + 1

                Coppia* TMP = (Coppia*)realloc(S,(numeroElementi + 1) * sizeof(Coppia));

                //Se l'allocazione del nuovo vettore è andata a buon fine
                if(TMP != NULL){
                    //Aumento numeroElementi di 1
                    numeroElementi++;

                    //Ricopio i valori dentro al nuovo vettore

                    S = TMP;

                    S[numeroElementi - 1] = S[numeroElementi - 2];//Riempio l'ultima coppia

                    //Shifto dalla posizione dove devo inserire a dx di 1 tutti gli elementi
                    for(int i = numeroElementi - 1; i > pos; i--){
                        S[i] = S[i - 1];
                    }

                    //Inserisco nella posizione corretta

                    S[pos] = nuovaCoppia;
                }
            }
        }
        //Cancellazione
        void cancel(int key){
            //Cerco l'indice della chiave key
            int index = search_index(key);
            
            //Shifto a sx di 1 gli elementi > di key
            for(int i = index; i < numeroElementi - 1; i++){
                S[i].key = S[i + 1].key;
                S[i].valore = S[i + 1].valore;
            }
            //Rialloco lo spazio a numeroElementi - 1
            Coppia* TMP = (Coppia*)realloc(S,(numeroElementi - 1) * sizeof(Coppia));

            //Se il realloc va a buon fine
            if(TMP != NULL){
                numeroElementi--;

                S = TMP;
            }
        }
};

int main() {
    Dizionario dizionario;

    if(!dizionario.S){
        cout << "Assegnazione vettore S NON andata a buon fine!\n";
        exit(1);
    }

    dizionario.insert(1,"Radu");
    dizionario.insert(6,"Andrea");
    dizionario.insert(3,"Piero");
    dizionario.insert(4,"Giulio");
    dizionario.insert(5,"Lorenzo");
    dizionario.insert(2,"Alvise");
    dizionario.insert(8,"Francesco");
    dizionario.insert(9,"Pino");
    dizionario.insert(7,"Alessandro");
    
    dizionario.stampa();
    /*
    dizionario.cancel(4);
    
    dizionario.stampa();
    */
    return 0;
}