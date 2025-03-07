#include <iostream>
#include <vector>
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
    std::unordered_map<int, int> contaOccorrenze;
    
    // Contare le occorrenze di ogni numero
    for(int num : A) {
        contaOccorrenze[num]++;
    }
    
    // Mappa per tracciare il numero di volte delle occorrenze
    std::unordered_map<int, int> conteggioRipetizioni;
    
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

bool stesse_occorrenze(vector<int>& A) {
    // Mappa per contare le occorrenze di ogni numero
    unordered_map<int, int> contaOccorrenze;
    
    // Contare le occorrenze di ogni numero
    for(int num = 0; num < A.size(); num++) {
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

int main(){
    vector<int> A = {2, 4, 4, 3, 3, 3, 4};

    if(stesse_occorrenze(A)){
        cout << "Yes!\n";
    }
    else{
        cout << "No!\n";
    }

    return 0;
}