//Heap sort | ASD in C++

/* 
    g++ heap_sort.cpp -o heap_sort
    ./heap_sort
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

//Heap Sort
void max_heapify(int A[], int n, int i) {//n è la heap_size, i è il nodo radice del sottoalbero
	int massimo = i;          // Inizializza il nodo più grande come radice
	int l = 2 * i + 1;     // Figlio sinistro
	int r = 2 * i + 2;    // Figlio destro

	// Se il figlio sinistro è più grande della radice
	if (l < n && A[l] > A[massimo]) {
			massimo = l;
	}

	// Se il figlio destro è più grande della radice
	if (r < n && A[r] > A[massimo]) {
			massimo = r;
	}

	// Se il nodo più grande non è la radice
	if (i != massimo) {
			swap(A[i], A[massimo]);  // Scambia la radice con il nodo più grande
			max_heapify(A, n, massimo);    // Richiama heapify sul sotto-albero
	}
}

void build_max_heap(int A[], int n){
    // Costruisce il max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
			max_heapify(A, n, i);
	}
}

// Funzione principale di Heap Sort
void heapSort(int A[], int n) {
	build_max_heap(A, n);

	// Estrae uno a uno gli elementi dall'heap
	for (int i = n - 1; i > 0; i--) {
			swap(A[0], A[i]);  // Sposta la radice corrente alla fine
			max_heapify(A, i, 0);    // Richiama heapify sulla radice ridotta
	}
}

int main() {
    // Vettore di esempio
    int vettore[] = {5, 2, 7, 3, 10, 1, 6, 9, 4, 8,};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);
	cout << "check max heapify:"<<endl;
	max_heapify(vettore, lunghezza, 10);
	stampaVettore(vettore, lunghezza);
	cout << endl;

    cout << "Vettore originale: ";
    stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    heapSort(vettore, lunghezza);
	
    cout << "Vettore ordinato: ";
    stampaVettore(vettore, lunghezza);

  return 0;
}