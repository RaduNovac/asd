//Radix sort | ASD in C++

/* 
    g++ radix_sort.cpp -o radix_sort
    ./radix_sort
*/
#include <iostream>
#include <cmath>

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

int cifra(int x, int n, int i){
  return (x/(int)pow(n, i)) % n;
}

//Counting sort
void counting_sort(int A[], int n, int k) {//k è il valore massimo dell'array
    // Crea array di conteggio
    int C[k + 1], i, j;
    int B[n];
    
    // Setto C tutto a 0
    for(i = 0; i <= k; i++){
      C[i] = 0;
    }

    // Conto quante volte occorre la cifra j-esima in A
    for(j = 0; j < n; j++){
      C[cifra(A[j], k, i)]++;
    }

    // Somme prefisse
    for(i = 1; i <= k; i++){
      C[i] = C[i] + C[i - 1];
    }

    //Sistemo gli elementi in B
    for (j = n - 1; j >= 0; j--) {
        B[C[cifra(A[j], k, i)]] = A[j];
        C[cifra(A[j], k, i)]--;
    }
    //Copio B in A
    for(i = 0; i < n; i++){
      A[i] = B[i];
    }
}

void radix_sort(int A[], int d, int k){
  for(int i = 0; i < d; i++){
    counting_sort(A, k, i);
  }
}

int main() {
    // Vettore di esempio
    int vettore[] = {326, 453, 608, 835, 751, 435, 704, 690};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);
    int massimo = max_value(vettore, lunghezza);
    
    cout << "Vettore originale: ";
    stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    radix_sort(vettore, lunghezza, massimo);
	
    cout << "Vettore ordinato: ";
    stampaVettore(vettore, lunghezza);
    
  return 0;
}