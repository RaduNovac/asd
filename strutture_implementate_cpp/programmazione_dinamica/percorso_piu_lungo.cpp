//Programmazione dinamica - percorso più lungo | ASD in C++

/* 
    g++ -std=c++11 percorso_piu_lungo.cpp -o percorso_piu_lungo

    ./percorso_piu_lungo
*/
#include <iostream>
#include <vector>

using namespace std;

/*
    Caratterizzazione ricorsiva:
    
    l_i=
    {
        l = 1                                                    i = 0
        l = max{l_j | j < i & alture[j] >= alture[i]} + 1        0 < i < n    
    }
*/
/*
    Complessità:
    Il ciclo esterno fa esattamente n - 1 iterazioni (perché parto da 1 e non da 0).
    Il ciclo interno fa j iterazioni con che fa da n - 1 - 1 iterazioni a 1.
    
    Ignorando le varie costanti giungiamo alla sommatoria:
    T(n) = sum (from i = 1 to n - 1) i = Theta((n*(n-1))/2) = Theta(n^2)
    
*/

int percorso_piu_lungo(vector<int>& alture){
    int n = alture.size();//Do per scontato che ci sia almeno 1 elemento delle alture

    vector<int> l(n, 1); // l[i] = lunghezza max del percorso che termina in i
    int massimo = 1;      // Memorizza la lunghezza massima trovata fino ad ora
    
    for(int i = 1; i < n; i++){//Parto dall'indice 1 perché nella prima altura ho un cammino di lunghezza 1 per definizione
        for(int j = i - 1; j >= 0; j--){//Verifico le lunghezze dei percorsi precedenti partendo da i - 1 fino a 0
            if(alture[j] >= alture[i]){//Condizione di altura precedente >= di quella corrente
                l[i] = max(l[i], l[j] + 1);//Il + 1 interno lo faccio per contare la lunghezza del percorso fino all'altura corrente
            }
        }
        if(l[i] > massimo){//Mi salvo il massimo
            massimo = l[i];
        }
    }

    return massimo;
}

int main(){
    vector<int> test1 = {1000, 900, 800, 700}; // atteso 4
    vector<int> test2 = {1000, 1100, 1050, 900, 950, 850}; // atteso 4
    vector<int> test3 = {500, 600, 700, 800}; // atteso 1
    vector<int> test4 = {10, 1, 9, 7, 8, 2, 6, 5, 4, 3}; // atteso 7

    cout << "Test 1 (atteso 4): " << percorso_piu_lungo(test1) << endl;
    cout << "Test 2 (atteso 4): " << percorso_piu_lungo(test2) << endl;
    cout << "Test 3 (atteso 1): " << percorso_piu_lungo(test3) << endl;
    cout << "Test 4 (atteso 7): " << percorso_piu_lungo(test4) << endl;

    return 0;
}
