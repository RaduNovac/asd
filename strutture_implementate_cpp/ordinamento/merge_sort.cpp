//Merge sort | ASD in C++

/* 
    g++ merge_sort.cpp -o merge_sort
    ./merge_sort
*/
#include <iostream>
#include <vector>

#define MAX_INT 2147483647

using namespace std;

// Funzione per stampare un vettore
void stampaVettore(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
}
//p è il punto di partenza, q il valore medio e r è il l'ultimo elemento
void merge(int A[], int p, int q, int r){
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

void merge_sort(int A[], int p, int r){
    if(p < r){
        int med = (p + r) / 2;
        merge_sort(A, p, med);
        merge_sort(A, med + 1, r);
        merge(A, p, med, r);
    }
}

int main() {
    // Vettore di esempio
    int vettore[] = {5, 2, 7, 3, 10, 1, 6, 9, 4, 8,};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);

    cout << "Vettore originale: ";
    stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    merge_sort(vettore, 0, lunghezza - 1);
	
    cout << "Vettore ordinato: ";
    stampaVettore(vettore, lunghezza);

  return 0;
}
