//Radix sort | ASD in C++

/* 
    g++ radix_sort.cpp -o radix_sort
    ./radix_sort
*/
#include <iostream>
#include <cmath>

using namespace std;

// Funzione per stampare un vettore
void stampaVettore(int A[], int n) {
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }

  cout << endl;
}

//La funzione max_value non serve più perché il range sarò da 0 a 9, sempre!

/*
  x: numero dal quale estrarre la cifra 
  n: base numerica 
  i: posizione cifra da estrarre, 0 cifra meno significativa (più a dx)
*/
int cifra(int x, int i){
  return (x/(int)pow(10, i)) % 10;
}

//Counting sort
/*
  A è il vettore
  k è il numero di cifre dei numeri
  i è la posizione della cifra da ordinare
  n è la lunghezza del vettore
*/
void counting_sort(int A[], int i, int n) {
    int C[10] = {0};//Siccome le cifre da ordinare andranno da 0 a 9, il vettore avrà per forza 10 elementi
    int B[n];//vettore di appoggio che alla fine copierò in A
    
    // Conto quante volte occorre la cifra j-esima in A
    for(int j = 0; j < n; j++){
        C[cifra(A[j], i)]++;
    }

    // Somme prefisse
    for(int j = 1; j < 10; j++){
        C[j] += C[j - 1];
    }

    // Sistemo gli elementi in B
    for (int j = n - 1; j >= 0; j--) {
        B[C[cifra(A[j], i)] - 1] = A[j];
        C[cifra(A[j], i)]--;
    }

    // Copio B in A
    for(int j = 0; j < n; j++){
        A[j] = B[j];
    }
}
/*
  Tutti i numeri devono avere lo stesso numero di cifre!!!
  d è il numero di cifre dei numeri 
  k è il valore massimo di A 
  n è la grandezza A
*/
void radix_sort(int A[], int d, int n){
  for(int i = 0; i < d; i++){
    counting_sort(A, i, n);
  }
}

int main() {
    int vettore[] = {326, 453, 608, 835, 751, 435, 704, 690, 75};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);
    
    cout << "Vettore originale: ";
    stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    radix_sort(vettore, 3, lunghezza);
	
    cout << "Vettore ordinato: ";
    stampaVettore(vettore, lunghezza);
    
  return 0;
}