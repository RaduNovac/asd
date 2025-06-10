#include<iostream>
#include<vector>
#include<algorithm> // Per std::swap, anche se lo hai implementato tu, è buona pratica

using namespace std;

/*
    Dati due max heap, ritornare un max heap contenente l'intersezione dei due heap
*/

//Heap Sort
void max_heapify(vector<int>& v, int n, int i){ // n è la heap_size (dimensione attuale del vettore), i è il nodo radice del sottoalbero
    int largest = i; // Inizializza largest come radice
    int l = 2 * i + 1;     // Figlio sinistro
    int r = 2 * i + 2;    // Figlio destro

    // Se il figlio sinistro esiste ed è più grande della radice
    if(l < n && v[l] > v[largest]){ // Corretto: l < n
        largest = l;
    }

    // Se il figlio destro esiste ed è più grande del corrente largest
    if(r < n && v[r] > v[largest]){ // Corretto: r < n
        largest = r;
    }

    // Se il nodo più grande non è la radice
    if(largest != i){
        swap(v[i], v[largest]);  // Scambia la radice con il nodo più grande
        max_heapify(v, n, largest);    // Richiama heapify sul sotto-albero
    }
}

// Funzione per costruire un max-heap da un vettore arbitrario
void build_max_heap(vector<int>& v){
    int n = v.size();
    // Inizia dall'ultimo nodo non-foglia e risali fino alla radice
    for(int i = n / 2 - 1; i >= 0; i--){
        max_heapify(v, n, i);
    }
}


int extract_root(vector<int>& v){
    if (v.empty()) {
        // Gestire l'errore: l'heap è vuoto
        return -1; // O lanciare un'eccezione
    }
    int res = v[0];

    // Scambia la radice con l'ultimo elemento
    swap(v[0], v[v.size() - 1]);

    // Rimuovi l'ultimo elemento (che era la vecchia radice)
    v.pop_back();

    // Ripristina la proprietà di max-heap sulla nuova radice
    if (!v.empty()) { // Solo se l'heap non è diventato vuoto
        max_heapify(v, v.size(), 0);
    }

    return res;
}

vector<int> intersezione(vector<int>& h1, vector<int>& h2){
    // Assumiamo che h1 e h2 siano già max-heap validi.
    // Se non lo sono, dovresti chiamare build_max_heap su di essi qui o prima di passare.

    vector<int> res;

    // Continua finché entrambi gli heap non sono vuoti
    while(!h1.empty() && !h2.empty()){
        // Stampa di debug
        // cout << "h1[0]: " << h1[0] << ", h2[0]: " << h2[0] << endl;

        if(h1[0] == h2[0]){ // Se le radici sono uguali, è un elemento dell'intersezione
            res.push_back(h1[0]); // Aggiungi l'elemento alla lista dei risultati

            // Estrai entrambe le radici
            // La extract_root ora gestisce internamente il max_heapify
            extract_root(h1);
            extract_root(h2);

            // cout << "Elemento comune trovato: " << res.back() << endl;
        }
        else if(h1[0] > h2[0]){ // Se la radice di h1 è maggiore, scarta h1[0]
            extract_root(h1);
            // cout << "Scartato h1[0]: " << h1[0] << endl;
        }
        else{ // Allora h1[0] < h2[0], scarta h2[0]
            extract_root(h2);
            // cout << "Scartato h2[0]: " << h2[0] << endl;
        }
    }

    // Nota: la tua funzione intersezione restituisce un vector<int> che non è un heap.
    // Se deve essere un heap, dovresti chiamare build_max_heap su `res` prima di ritornarlo.
    // build_max_heap(res); // Se il risultato deve essere un max-heap

    return res;
}


void print(const vector<int>& v){ // Passa per riferimento costante
    for(int i = 0; i < v.size(); i++){
        cout << "v[" << i << "]: " << v[i] << endl;
    }
    cout << endl;
}

int main(){
    vector<int> h1_raw, h2_raw;

    h1_raw.push_back(100);
    h1_raw.push_back(7);
    h1_raw.push_back(25);
    h1_raw.push_back(1);
    h1_raw.push_back(4);
    h1_raw.push_back(5);

    h2_raw.push_back(101);
    h2_raw.push_back(100);
    h2_raw.push_back(50);
    h2_raw.push_back(25);
    h2_raw.push_back(5);
    h2_raw.push_back(50); // Esempio di duplicato
    h2_raw.push_back(25); // Esempio di duplicato
    h2_raw.push_back(7);
    h2_raw.push_back(1);

    cout << "H1 prima di build_max_heap:" << endl;
    print(h1_raw);
    build_max_heap(h1_raw);
    cout << "H1 dopo build_max_heap:" << endl;
    print(h1_raw);

    cout << "H2 prima di build_max_heap:" << endl;
    print(h2_raw);
    build_max_heap(h2_raw);
    cout << "H2 dopo build_max_heap:" << endl;
    print(h2_raw);

    // Esempio di test per extract_root e max_heapify
    // cout << "Test di extract_root e max_heapify su h1_raw:" << endl;
    // int extracted_val = extract_root(h1_raw);
    // cout << "Radice estratta: " << extracted_val << endl;
    // cout << "H1 dopo extract_root:" << endl;
    // print(h1_raw);


    cout << "\nCalcolo dell'intersezione...\n";
    vector<int> h3 = intersezione(h1_raw, h2_raw);

    cout << "\nIntersezione (h3):" << endl;
    print(h3);

    return 0;
}