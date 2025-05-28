#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

//p è il punto di partenza, q il valore medio e r è il l'ultimo elemento
void merge(vector<int> A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    //Array di appoggio
    int L[n1 + 1], R[n2 + 1];

    //Copia sottoarray
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    //Valori sentinella
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    //Unione effettiva dei due vettori
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {//Facendo il confronto tra i due array di appoggio
            A[k] = L[i];//Inserisco gli elementi in A nella posizione corretta
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<int> A, int p, int r){
    if(p < r){
        int med = (p + r) / 2;
        merge_sort(A, p, med);
        merge_sort(A, med + 1, r);
        merge(A, p, med, r);
    }
}

bool stesse_occorrenze_v2(vector<int> &A){
    // Mappa per contare le occorrenze di ogni numero
    unordered_map<int, int> contaOccorrenze;
    
    // Contare le occorrenze di ogni numero
    for(int num : A) {
        contaOccorrenze[num]++;
    }
    
    // Mappa per tracciare il numero di volte delle occorrenze
    unordered_map<int, int> conteggioRipetizioni;
    
    // Verificare quante volte appare ogni conteggio
    for(const auto& coppia : contaOccorrenze) {
        conteggioRipetizioni[coppia.second]++;
    }
    
    // Verificare se ci sono due conteggi uguali
    for(const auto& ripetizione : conteggioRipetizioni) {
        if(ripetizione.second >= 2) {
            return true;
        }
    }
    
    return false;
}

bool stesse_occorrenze(vector<int> &arr){
    int i = 0,j;
    bool ok = false;
    //Vettore occorrenze
    vector<int> occ(arr.size() + 1);
    //Se il vettore ha un solo elemento esco subito
    if(arr.size() < 2){
        return false;
    }
    //Ordino l'array
    merge_sort(arr, 0, arr.size() - 1);

    while(i < arr.size() && !ok){
        j = i + 1;
        //Conta i numeri uguali in successione, siccome il vettore è ordinato, partendo dalla posizione i
        while(j < arr.size() && arr[i] == arr[j]){
            j++;
        }
        //j - i indica il numero di occorrenze del numero corrente!!!
        if(occ[j - i] == 0){//Se l'occorrenza di quel numero non è mai stata aggiornata
            occ[j - i] = 1;

            i = j;//Sposta l'indice all'inizio del prossimo gruppo di numeri
        }
        else{//Se invece l'occorrenza è già stata aggiornata, vuol dire che c'è un altro numero con lo stesso numero di occorrenze!
            ok = true;
        }
    }

    return ok;
}

bool valori_distinti_costanti(vector<int>& arr){
    int j = 0;
    bool ok;

    vector<pair<int, int>> mappa;
    vector<int> occ(arr.size() + 1);

    if(arr.size() < 2){
        return false;
    }

    for(int i = 0; i < arr.size(); i++){
        j = 0;

        while(j < mappa.size() && mappa[j].first != arr[i]){
            j++;
        }

        if(j == mappa.size()){
            mappa.push_back(pair(arr[i], 1));
        }
        else{
            mappa[j].second += 1;
        }
    }

    ok = false;
    j = 0;

    while(j < mappa.size() && !ok){
        if(occ[mappa[j].second] == 0){
            occ[mappa[j].second] = 1;
            j++;
        }
        else{
            ok = true;
        }
    }

    return ok;
}

int main(){
    vector<int> A = {2, 4, 4, 3, 3, 3, 4};

    if(stesse_occorrenze(A)){
        cout << "Yes!\n";
    }
    else{
        cout << "No!\n";
    }

    if(valori_distinti_costanti(A)){
        cout << "A!\n";
    }
    else{
        cout << "B!\n";
    }

    return 0;
}