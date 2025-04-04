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
//Counting sort, senza numeri negativi
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

int massimo(int V[], int n){
  int max = V[0];

  for(int i = 0; i < n;i++){
    if(V[i] > max){
      max = V[i];
    }
  }

  return max;
}

int minimo(int V[], int n){
  int min = V[0];

  for(int i = 0; i < n;i++){
    if(V[i] < min){
      min = V[i];
    }
  }

  return min;
}

//Counting sort con numeri negativi
void counting_sort_neg(int A[], int B[], int n){
  // Trova il minimo e massimo valore
  int min_val = minimo(A, n);
  int max_val = massimo(A, n);


  int range = max_val - min_val + 1; // Range degli elementi
  vector<int> C(range, 0); // Array di conteggio
  //int C[range];

  // Conta le occorrenze
  for (int i = 0; i < n; i++) {
      C[A[i] - min_val]++;
  }

  // Somme prefisse
  for (int i = 1; i < range; i++) {
      C[i] += C[i - 1];
  }

  // Costruisce l'array ordinato
  for (int i = n - 1; i >= 0; i--) {
      B[C[A[i] - min_val] - 1] = A[i];
      C[A[i] - min_val]--;
  }
}

int main() {
    // Vettore di esempio
    int vettore1[] = {5, 2, 7, 3, 10, 1, 6, 9, 4, 8,};
    int vettore2[] = {-5, -10, 0, -3, 8, 5, -1, 10};
    
    int lunghezza1 = sizeof(vettore1) / sizeof(vettore1[0]);
    int lunghezza2 = sizeof(vettore2) / sizeof(vettore2[0]);

    int risultato1[lunghezza1];
    int risultato2[lunghezza2];

    int massimo1 = max_value(vettore1, lunghezza1);
    
    cout << "Vettore originale SENZA numeri negativi:\n ";
    stampaVettore(vettore1, lunghezza1);

    //Applica l'ordinamento al vettore
    counting_sort(vettore1, risultato1, lunghezza1, massimo1);
	
    cout << "Vettore ordinato:\n ";
    stampaVettore(risultato1, lunghezza1);

    cout << "Vettore originale CON numeri negativi:\n ";
    stampaVettore(vettore2, lunghezza2);
    // Applica l'ordinamento al vettore
    counting_sort_neg(vettore2, risultato2, lunghezza2);
	
    cout << "Vettore ordinato:\n ";
    stampaVettore(risultato2, lunghezza2);
    
  return 0;
}