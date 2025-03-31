#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funzione di ordinamento per gli intervalli
void ordina(vector<pair<int, int>> &arr) {
    sort(arr.begin(), arr.end());
}

// Funzione per verificare se gli intervalli formano un unico intervallo
bool unione(vector<pair<int, int>>& arr, pair<int, int>& ris) {
    if (arr.empty()) return false;
    
    ordina(arr);
    size_t i = 1;
    int endtemp = arr[0].second;
    /*
    La condizione è se i è minore della dimensione del vettore e
    l'estremo destro dell'intervallo precedente "copre" (>=) dell'estremo
    sinostro dell'intervallo corrente.
    Fino a quando ci sono intervalli che si sovrappongono, li conta.
    Alla fine, se il numero di intervalli che si sovrappongono non è
    uguale a quello degli elementi di arr, vuol dire che c'è un buco
    e ritorna false. True altrimenti
    */
    while (i < arr.size() && endtemp + 1 >= arr[i].first){
        if (arr[i].second > endtemp) {
            endtemp = arr[i].second;
        }
        i++;
    }
    
    if (i == arr.size()){//Non ho trovato buchi
        ris = {arr[0].first, endtemp};
        return true;
    }
    
    return false;
}

int main() {
    vector<pair<int, int>> intervalli = {{-7, 4}, {-6, 2}, {10, 12}, {13, 14}};
    pair<int, int> risultato;
    
    if (unione(intervalli, risultato)) {
        cout << "Gli intervalli formano un unico intervallo: [" 
             << risultato.first << ", " << risultato.second << "]\n";
    } else {
        cout << "Gli intervalli non formano un unico intervallo.\n";
    }
    
    return 0;
}
