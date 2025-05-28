#include <iostream>
#include <vector>

using namespace std;

// Funzione somma21:
// cerca se esiste una coppia di elementi in v che sommati diano 21.
// Se esiste, la funzione restituisce true e i due valori (val1 e val2).
// Se non esiste, restituisce false.
bool somma21(vector<int>& v, int& val1, int& val2) {
    // Inizializziamo un vettore di occorrenze per i valori possibili (0..21)
    // (Se i valori possono essere più grandi di 21, potresti voler controllare
    //  di non accedere fuori dai limiti del vettore occ)
    vector<int> occ(22, 0);

    bool trovati = false;
    size_t i = 0;

    // Cicliamo sugli elementi del vettore
    while (i < v.size() && !trovati) {
        // Se il valore è <= 21, lo consideriamo nel nostro vettore delle occorrenze
        if (v[i] <= 21) {
            // Incrementiamo l'occorrenza del valore corrente
            occ[v[i]]++;

            // Verifichiamo se l'elemento complementare (21 - v[i]) è presente
            // Se occ[21 - v[i]] è > 0, vuol dire che è già stato visto
            if (occ[21 - v[i]] > 0) {
                trovati = true;
                val1 = v[i];
                val2 = 21 - v[i];
            }
        }
        i++;
    }
    return trovati;
}

bool somma21_alternative(vector<int>& v, int& val1, int& val2) {
    // Creiamo un vettore booleano per tenere traccia degli elementi visti.
    // Poiché i valori sono non negativi e la somma da ottenere è 21, ci basta
    // considerare gli elementi da 0 a 21.
    vector<bool> seen(22, false);

    for (int x : v) {
        if (x <= 21) {
            // Controllo il complementare, ovvero 21 - x.
            // Se l'elemento complementare è già stato visto, allora abbiamo trovato la coppia.
            if (seen[21 - x]) {
                val1 = x;
                val2 = 21 - x;
                return true;
            }
            // Imposto che l'elemento x è stato visto.
            seen[x] = true;
        }
    }
    return false;
}

int main() {
    // Esempio di vettore di interi non negativi
    vector<int> arr = {10, 1, 5, 15, 6, 21, 0, 11};

    // Variabili che conterranno la coppia trovata
    int val1, val2;

    // Chiamata alla funzione somma21
    if (somma21(arr, val1, val2)) {
        cout << "Trovata coppia che somma a 21: "
             << val1 << " + " << val2 << " = 21" << endl;
    } else {
        cout << "Nessuna coppia trovata che sommi a 21." << endl;
    }

    return 0;
}
