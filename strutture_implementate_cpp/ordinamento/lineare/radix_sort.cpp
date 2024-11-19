//Counting sort | ASD in C++

/* 
    g++ counting_sort.cpp -o counting_sort
    ./counting_sort
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
void counting_sort(int A[], int n, int k) {//k è il valore massimo dell'array
    // Crea array di conteggio
    int* count = new int[k + 1]();
    int C[k + 1];
    
    // Conta le occorrenze di ogni elemento
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }
    
    // Ricostruisce l'array ordinato
    int index = 0;
    for (int i = 0; i <= k; i++) {
        while (count[i] > 0) {
            A[index++] = i;
            count[i]--;
        }
    }
    
    // Libera memoria
    delete[] count;
}

int main() {
    // Vettore di esempio
    int vettore[] = {5, 2, 7, 3, 10, 1, 6, 9, 4, 8,};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);
    int massimo = max_value(vettore, lunghezza);
    
    cout << "Vettore originale: ";
    stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    counting_sort(vettore, lunghezza, massimo);
	
    cout << "Vettore ordinato: ";
    stampaVettore(vettore, lunghezza);
    
  return 0;
}
