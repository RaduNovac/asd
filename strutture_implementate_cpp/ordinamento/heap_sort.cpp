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

int max_element(int arr[]){
    int lunghezza = sizeof(arr) / sizeof(arr[0]);

    cout << "lunghezza: " << lunghezza <<endl;

    return 0;
}

// Funzione per implementare l'insertion sort
void insertionSort(int arr[], int n) {
  // Dichiaro le variabili che mi servono
  int i, j, chiave;

  for (i = 1; i < n;
       i++) { // Il ciclo verrà eseguito n-1 volte e parte dal secondo elemento
    chiave = arr[i]; // La chiave è il valore puntato dal cursore i, che è il
                     // primo elemento della parte non ordinata
    j = i - 1; // j indica l'elemento prima di i, quindi fa parte della parte
               // ordinata

    // Sposta gli elementi del vettore che sono maggiori della chiave in avanti
    // di una posizione
    while (j >= 0 && arr[j] > chiave) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    // Ricopio la chiave nella posizione corretta
    arr[j + 1] = chiave;

    // Stampo l'array ad ogni passaggio per debug
    cout << "Al passaggio " << i << " l'array e' il seguente: ";
    stampaVettore(arr, n);
  }
}

//Heap Sort
void max_heapify(int arr[], int n, int i) {
	int largest = i;          // Inizializza il nodo più grande come radice
	int left = 2 * i + 1;     // Figlio sinistro
	int right = 2 * i + 2;    // Figlio destro

	// Se il figlio sinistro è più grande della radice
	if (left < n && arr[left] > arr[largest]) {
			largest = left;
	}

	// Se il figlio destro è più grande della radice
	if (right < n && arr[right] > arr[largest]) {
			largest = right;
	}

	// Se il nodo più grande non è la radice
	if (largest != i) {
			swap(arr[i], arr[largest]);  // Scambia la radice con il nodo più grande
			max_heapify(arr, n, largest);    // Richiama heapify sul sotto-albero
	}
}

// Funzione principale di Heap Sort
void heapSort(int arr[], int n) {
	// Costruisce il max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
			max_heapify(arr, n, i);
	}

	// Estrae uno a uno gli elementi dall'heap
	for (int i = n - 1; i > 0; i--) {
			swap(arr[0], arr[i]);  // Sposta la radice corrente alla fine
			max_heapify(arr, i, 0);    // Richiama heapify sulla radice ridotta
	}
}
//Counting sort
void countingSort(vector<int>& arr) {
		//int max_element = *max_element(arr.begin(), arr.end()); // trova il valore massimo dell'array
		//vector<int> count(max_element+1, 0); // crea un array di conteggio con una dimensione pari al valore massimo + 1
        vector<int> count(1, 0);
		// contare il numero di occorrenze di ciascun elemento
		for (int i = 0; i < arr.size(); i++) {
				count[arr[i]]++;
		}

		// riempie l'array originale nell'ordine corretto
		int j = 0;
		for (int i = 0; i < count.size(); i++) {
				while (count[i] > 0) {
						arr[j] = i;
						j++;
						count[i]--;
				}
		}
}

int main() {
    // Vettore di esempio
    int vettore[] = {5, 2, 7, 3, 1};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);

    //cout << "Vettore originale: ";
    //stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    //insertionSort(vettore, lunghezza);
    
    //heapSort(vettore, lunghezza);
	
    //cout << "Vettore ordinato: ";
    //stampaVettore(vettore, lunghezza);

    int x = max_element(vettore);//non va

  return 0;
}
