#include <iostream>
#include <vector>

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

bool stesse_occorrenze(vector<int> &arr){
    /*
        Mia logica:
        - Ordino il vettore
        - Conto le occorrenze
        - Verifico se ci sono due numeri uguali nel vettore delle occorrenze
    */
}

int main(){
    vector<int> A = {2, 4, 5, 6, 8, 9, 10};

    if(stesse_occorrenze(A)){
        cout << "Yes!\n";
    }
    else{
        cout << "No|\n";
    }

    return 0;
}