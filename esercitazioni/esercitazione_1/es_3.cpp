/* 
La larghezza di un albero è il numero massimo di nodi che stanno tutti al medesimo livello. 
Si fornisca una funzione che calcoli in tempo ottimo la larghezza di un albero generale T di n nodi. 
I nodi hanno campi key, left_child e right_sib.

Il prototipo della funzione è:

int larghezza(PNodeG r)

Analizzare e motivare in modo chiaro, preciso ed approfondito la complessità della funzione.

Il tipo del nodo è definito come segue:

struct NodeG{  
  int key;
  NodeG* left_child;
  NodeG* right_sib;
};

typedef NodeG* PNodeG;
*/
#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct NodeG{
    int key;
    NodeG* left_child;
    NodeG* right_sib;
};

typedef NodeG* PNodeG;

string ltrim(const string &str);
string rtrim(const string &str);
vector<string> split(const string &str);
PNodeG aggiungiNodo(PNodeG u, int val);
PNodeG costruisciInAmpiezzaInput(int dim);
/*
    Complessità:
        Similmente al secondo esercizio, inserisco l'albero (all'inizio solo la radice, 
        poi i figli e via dicendo)in una coda e per ogni nodo, aggiungo i figli nella coda.
        Quindi ogni nodo viene visitato esattamente una volta.
        
        Per ogni nodo il costo delle operazioni eseguite è costante, quindi anche il 
        calcolo della lunghezza di ogni livello (è dato dalla grandezza della coda) è
        costante.
        
        Il ciclo while esterno viene eseguito n volte, con n = n° nodi albero.
        Il ciclo interno è limitato dalla larghezza del livello, quindi << n.
        
        Quindi la complessità T(n) = Theta(n)
*/
int larghezza(PNodeG r) {
    if (!r){ // Albero vuoto => ha larghezza 0
        return 0;
    }

    queue<PNodeG> coda;
    coda.push(r);
    int larghezza_max = 0;

    while(!coda.empty()){
        int larghezza_livello = coda.size(); // Numero di nodi nel livello corrente
        larghezza_max = max(larghezza_max, larghezza_livello); // Confronto con la larghezza massima precedente

        for(int i = 0; i < larghezza_livello; i++){//Tutti i nodi del livello corrente
            PNodeG current = coda.front();
            coda.pop();

            // Se il nodo ha figlio sx lo aggiungo alla coda
            if (current -> left_child) {
                coda.push(current -> left_child);

                // Se il figlio sx ha dei fratelli dx li aggiungo alla coda
                PNodeG sibling = current -> left_child -> right_sib;
                while (sibling) {
                    coda.push(sibling);
                    sibling = sibling -> right_sib;
                }
            }
        }
    }

    return larghezza_max;
}

int main()
{
    vector<int> arr;
    PNodeG r;

    string dim_temp;
    getline(cin, dim_temp);

    int dim = stoi(ltrim(rtrim(dim_temp)));

    arr.resize(dim);

    r = costruisciInAmpiezzaInput(dim);

    cout << larghezza(r);

    return 0;
}

PNodeG aggiungiNodo(PNodeG u, int val){

    PNodeG z, iter;

    z = new NodeG{val,nullptr,nullptr};
    if (u->left_child == nullptr)
        u->left_child = z;
    else{
        iter = u->left_child;
        while (iter->right_sib)
            iter = iter->right_sib;
        iter ->right_sib = z;
    }

    return z;
}

PNodeG costruisciInAmpiezzaInput(int dim){

    PNodeG r, u;
    queue<PNodeG> q;

    if (dim == 0)
        return nullptr;

    string radix_val_temp;
    getline(cin, radix_val_temp);

    int radix_val = stoi(ltrim(rtrim(radix_val_temp)));

    r = new NodeG{radix_val,nullptr,nullptr};

    q.push(r);

    vector<int> vals;

    while (!q.empty()){
        u = q.front();
        q.pop();

        string vals_string_temp;
        getline(cin, vals_string_temp);
        vector<string> splitted_string_temp;

        splitted_string_temp = split(rtrim(ltrim(vals_string_temp)));
        if (splitted_string_temp.size() >= 2) {
            int grado = stoi(splitted_string_temp[0]);

            for (int i = 1; i <= grado; i++){
                int val = stoi(splitted_string_temp[i]);
                q.push(aggiungiNodo(u, val));
            }
        }

    }

    return r;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
