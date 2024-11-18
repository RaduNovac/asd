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

// Funzione per implementare l'insertion sort
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

int main() {
    // Vettore di esempio
    int vettore[] = {5, 2, 7, 3, 1};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);

    //cout << "Vettore originale: ";
    stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    insertionSort(vettore, lunghezza);
	
    cout << "Vettore ordinato: ";
    stampaVettore(vettore, lunghezza);

  return 0;
}
