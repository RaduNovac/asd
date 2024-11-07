//Dizionari implementati con array ordinati versione vecchia MA FUNZIONA| ASD in C++

/* 
    g++ dizionari_array_ordinati_old.cpp -o dizionari
    ./dizionari
*/

#include <iostream>
#include <string>

using namespace std;

struct Coppia {
    int key;
    string valore;
};

typedef Coppia Coppia;

class Dizionario {
    public:
        Coppia* S;
        int numeroElementi;

        Dizionario(){
            numeroElementi = 0;
            S = (Coppia*) malloc(numeroElementi * sizeof(Coppia));
        }
        
};

int main() {
    
    return 0;
}