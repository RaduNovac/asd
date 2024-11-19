//Counting sort | ASD in C++

/* 
    g++ counting_sort.cpp -o counting_sort
    ./counting_sort
*/
#include <iostream>

using namespace std;

// Funzione per stampare un vettore
void stampaVettore(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

int max_value(int A[], int n){
  int max = A[0];

  for(int i = 1; i < n; i++){//Parto da 1 perché 0 l'ho già messo in max
    if(A[i] > max){
      max = A[i];
    }
  }

  return max;
}
//Counting sort
void counting_sort(int A[], int B[], int n, int k) {//k è il valore massimo dell'array
    // Crea array di conteggio
    int C[k + 1], i, j;
    
    // Setto C tutto a 0
    for(i = 0; i <= k; i++){
      C[i] = 0;
    }

    // Conto quante volte occorre l'elemento j-esimo in A
    for(j = 0; j < n; j++){
      C[A[j]]++;
    }

    // Somme prefisse
    for(i = 1; i <= k; i++){
      C[i] = C[i] + C[i - 1];
    }

    //Sistemo gli elementi in B
    for (j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    // Vettore di esempio
    int vettore[] = {5, 2, 7, 3, 10, 1, 6, 9, 4, 8,};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);
    int risultato[lunghezza];
    int massimo = max_value(vettore, lunghezza);
    
    cout << "Vettore originale: ";
    stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    counting_sort(vettore, risultato, lunghezza, massimo);
	
    cout << "Vettore ordinato: ";
    stampaVettore(risultato, lunghezza);
    
  return 0;
}