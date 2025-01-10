#include <vector>
#include <iostream>

using namespace std;

// Funzione di utility per lo swap
void swap(vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void ordina_modulo3(vector<int>& A) {
    int n = A.size();
    
    // Prima partition: separa gli elementi con resto 0 
    int k = 0;  // indice per elementi con resto 0
    for(int i = 0; i < n; i++) {
        if(A[i] % 3 == 0) {
            swap(A, k, i);
            k++;
        }
    }
    
    // Seconda partition: separa gli elementi con resto 1 da quelli con resto 2
    int j = k;  // indice per elementi con resto 1
    for(int i = k; i < n; i++) {
        if(A[i] % 3 == 1) {
            swap(A, j, i);
            j++;
        }
    }
}

// Funzione di utility per stampare il vettore
void stampa_vettore(vector<int>& A) {
    cout << "[";
    for(int i = 0; i < A.size(); i++) {
        cout << A[i];
        if(i < A.size() - 1) std::cout << ", ";
    }
    cout << "]" << std::endl;
}

int main(){
    // Inizializzazione del vettore con i valori dell'esempio
    vector<int> A;
    A.push_back(4);
    A.push_back(1);
    A.push_back(5);
    A.push_back(3);
    A.push_back(7);
    A.push_back(2);
    A.push_back(8);
    
    cout << "Vettore originale: ";
    stampa_vettore(A);
    
    // Chiamata alla funzione di ordinamento
    ordina_modulo3(A);
    
    cout << "Vettore ordinato per modulo 3: ";
    stampa_vettore(A);
    
    // Stampa i resti per verifica
    cout << "\nResti modulo 3:" << std::endl;
    for(int i = 0; i < A.size(); i++) {
        cout << "A[" << i << "] = " << A[i] << ": resto " << A[i] % 3 << std::endl;
    }

    return 0;
}