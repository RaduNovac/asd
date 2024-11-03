//Dizionari ASD in C++

/* 
    g++ dizionari.cpp -o dizionari
    ./dizionari
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Coppia {
    int key;
    string valore;
};

typedef Coppia Coppia;

class Dizionario {

    public:
        Coppia S[3];
        int numeroElementi;

        Dizionario() : numeroElementi(3) {}//Da modificare poi in 0

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
            if (left > right) {
                return -1;
            }

            int mid = left + (right - left) / 2;

            if (S[mid].key == key) {
                return mid;
            } else if (S[mid].key < key) {
                return search_index_aux(key, mid + 1, right);
            } else {
                return search_index_aux(key, left, mid - 1);
            }
        }

        void insert(int key, string valore) {
            //Se la chiave che voglio inserire c'è già la aggiorno, altrimenti la aggiungo trovando la posizione, ingrandendo il vettore di 1 posizione e shiftando tutto di 1 a dx

            int posizione = search_index(key);

            if(posizione != -1){//Se è già presente la aggiorno
                cout << "Già presente! Provvedo ad aggiornare il valore...\n";

                S[posizione].valore = valore;
            }
            else{//Altrimenti inserisco una nuova coppia
                Coppia nuovaCoppia = {key, valore};
            }
        }
};

int main() {
    Dizionario dizionario;
    /*
    dizionario.insert(1, "Radu");
    dizionario.insert(2, "Andrea");
    dizionario.insert(3, "Matteo");
    */
    Coppia c1, c2, c3;

    c1.key = 1;
    c1.valore = "Radu";

    c2.key = 2;
    c2.valore = "Andrea";

    c3.key = 3;
    c3.valore = "Piero";

    dizionario.S[0] = c1;
    dizionario.S[1] = c2;
    dizionario.S[2] = c3;

    cout << "S[0]: " << dizionario.S[0].key << ", " << dizionario.S[0].valore << endl;
    cout << "S[1]: " << dizionario.S[1].key << ", " << dizionario.S[1].valore << endl;
    cout << "S[2]: " << dizionario.S[2].key << ", " << dizionario.S[2].valore << endl;

    dizionario.insert(1, "Ciao");

    cout << "S[0]: " << dizionario.S[0].key << ", " << dizionario.S[0].valore << endl;
    cout << "S[1]: " << dizionario.S[1].key << ", " << dizionario.S[1].valore << endl;
    cout << "S[2]: " << dizionario.S[2].key << ", " << dizionario.S[2].valore << endl;

    return 0;
}