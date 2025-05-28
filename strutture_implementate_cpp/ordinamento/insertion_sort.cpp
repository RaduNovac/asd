//Insertion sort | ASD in C++

/* 
    g++ insertion_sort.cpp -o insertion_sort
    ./insertion_sort
*/
#include <iostream>
#include <vector>

using namespace std;

// Funzione per stampare un vettore
void stampaVettore(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

// Funzione per implementare l'insertion sort iterativo
void insertionSort(int arr[], int n) {
  // Dichiaro le variabili che mi servono
  int i, j, chiave;

  for (i = 1; i < n; i++) { // Il ciclo verrà eseguito n-1 volte e parte dal secondo elemento
    chiave = arr[i]; // La chiave è il valore puntato dal cursore i, che è il primo elemento della parte non ordinata
    j = i - 1; // j indica l'elemento prima di i, quindi fa parte della parte ordinata

    // Sposta gli elementi del vettore che sono maggiori della chiave in avanti di una posizione
    while (j >= 0 && arr[j] > chiave) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    // Ricopio la chiave nella posizione corretta
    arr[j + 1] = chiave;
  }
}
// Funzione per implementare l'insertion sort ricorsivo
void insertionSortRic(int arr[], int n)
{ // Caso base
  if(n <= 1) return; 
  
  // Ordino i primi n-1 elementi
  insertionSortRic(arr, n-1); 
  //Inserisco l'ultimo elemento nella posizione corretta nell'array ordinato
  int chiave = arr[n-1]; 
  int j = n-2; 
  /*
    Sposto gli elementi di arr[0..i-1], che sono > key, avanti di una posizione
    rispetto alla posizione corrente
  */
  while(j >= 0 && arr[j] > chiave) 
  {
    arr[j+1] = arr[j];
    j--;
  }

  arr[j+1] = chiave; 
}

int main() {
    // Vettore di esempio
    int v1[] = {5, 2, 7, 3, 1, 6, 9, 4, 8};
    int v2[] = {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 5};
    int lunghezza = sizeof(v2) / sizeof(v2[0]);

    cout << "Vettore originale: ";
    stampaVettore(v2, lunghezza);

    // Applica l'ordinamento al vettore
    insertionSort(v2, lunghezza);
	
    cout << "Vettore ordinato: ";
    stampaVettore(v2, lunghezza);

  return 0;
}
