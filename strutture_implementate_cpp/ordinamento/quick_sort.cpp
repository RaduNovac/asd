//Merge sort | ASD in C++

/* 
    g++ quick_sort.cpp -o quick_sort
    ./quick_sort
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

int partition(int A[], int p, int r){
    int x = A[r], i = p - 1, tmp;

    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i = i + 1;
            //Scambio A[i] con A[j]
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    //Scambio A[i + 1] con A[r]
    tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;

    return i + 1;
}

void quick_sort(int A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int main() {
    // Vettore di esempio
    int vettore[] = {5, 2, 7, 3, 10, 1, 6, 9, 4, 8,};
    int lunghezza = sizeof(vettore) / sizeof(vettore[0]);

    cout << "Vettore originale: ";
    stampaVettore(vettore, lunghezza);

    // Applica l'ordinamento al vettore
    quick_sort(vettore, 0, lunghezza - 1);
	
    cout << "Vettore ordinato: ";
    stampaVettore(vettore, lunghezza);

  return 0;
}
