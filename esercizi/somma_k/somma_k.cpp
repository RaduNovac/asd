#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funzione di ordinamento
void ordina(vector<int>& v) {
    sort(v.begin(), v.end());
}

// Restituisce true se trova due valori che sommati danno k, false altrimenti.
// Se trova i valori, li salva in val1 e val2.
bool sommaK(vector<int>& v, int k, int& val1, int& val2){
    // Ordiniamo il vettore per poter usare il metodo dei due puntatori
    ordina(v);

    // Inizializziamo i due puntatori (p: inizio, f: fine)
    int p = 0;
    int f = static_cast<int>(v.size()) - 1;

    // Scorriamo finché p < f
    while (p < f) {
        int somma = v[p] + v[f];

        // Se la somma è esattamente k, abbiamo trovato la coppia
        if (somma == k) {
            val1 = v[p];
            val2 = v[f];
            return true;
        }
        // Se la somma è minore di k, incrementiamo p per aumentare la somma
        else if (somma < k) {
            p++;
        }
        // Altrimenti (somma > k), decrementiamo f per diminuire la somma
        else {
            f--;
        }
    }

    // Se usciamo dal while senza aver trovato la coppia, restituiamo false
    return false;
}

int main() {
    // Esempio di array
    vector<int> arr = {2, 4, 1, 6, 3, 9, 7};
    
    // Valore di k da cercare
    int k = 10;
    
    // Variabili che conterranno i valori trovati
    int val1, val2;

    // Chiamata alla funzione
    if (sommaK(arr, k, val1, val2)) {
        cout << "Trovata coppia che somma a " << k << ": (" << val1 << ", " << val2 << ")\n";
    } else {
        cout << "Nessuna coppia trovata per somma " << k << "\n";
    }

    return 0;
}
