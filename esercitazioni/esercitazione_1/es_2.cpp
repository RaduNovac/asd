/*
Si scriva una funzione efficiente per stabilire se un albero binario è quasi completo, 
cioè tutti i livelli dell’albero sono completamente riempiti, 
tranne eventualmente l’ultimo che ha le foglie addossate a sinistra.
Calcolare la complessità al caso pessimo dell’algoritmo indicando, e risolvendo, 
la corrispondente relazione di ricorrenza.

La rappresentazione dell’albero binario utilizza esclusivamente i campi left, right e key. 
Il prototipo della funzione è:

bool isQuasiCompleto(PNode r)

Analizzare e motivare in modo chiaro, preciso ed approfondito la complessità della funzione.

Il tipo PNode è così definito:

struct Node{  
  int key;
  Node* left;
  Node* right;
};

typedef Node* PNode;
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;
bool quasicompleto(PNode r){
  if (!r){ //Albero vuoto
      return true;
  }

    queue<PNode> coda;
    coda.push(r);
    bool mustBeLeaf = false; // Indica se tutti i nodi successivi devono essere foglie.

    while(!coda.empty()){
        PNode current = coda.front();
        coda.pop();

        if(current -> left){// Se ha un figlio sx
            if(mustBeLeaf){// E deve essere una foglia
                return false;
            } 
            coda.push(current -> left);
        }
        else {
            mustBeLeaf = true;
        }

        if(current -> right){// Se ha un figlio dc
            if(mustBeLeaf){// E deve essere una foglia
                return false;
            }
            coda.push(current -> right);
        }
        else{
            mustBeLeaf = true; // Anche in questo caso, attiva la modalità "foglia".
        }
    }

    return true;
}
PNode ricostruisciAux(const vector<int>& va, int infa, int supa, const vector<int>& vs, int infs, int sups){

    int i;
    PNode r;

    if (infa > supa)
        return nullptr;

    r = new Node{va[infa],nullptr,nullptr};

    i = infs;

    while (vs[i] != va[infa])
        i++;

    r->left = ricostruisciAux(va, infa+1, infa + (i - infs), vs, infs, i-1);
    r->right = ricostruisciAux(va, infa+(i - infs) + 1, supa, vs, i+1, sups);

    return r;
}

PNode ricostruisci(const vector<int>& va, const vector<int>& vs){
    return ricostruisciAux(va, 0, va.size()-1, vs, 0, vs.size()-1);
}

void visita(PNode r) {
    if (r) {
        visita(r->left);
        cout << r->key;
        visita(r->right);
    }
}

vector<int> read_array(int dim) {
    vector<int> res;
    if (dim != 0) {
        string delimiter = " ";
        string line;
        getline(cin, line);
        for(int i = 0; i < dim; i++) {
            string key_str = line.substr(0, line.find(delimiter));
            int key = stoi(ltrim(rtrim(key_str)));
            res.push_back(key);
            line.erase(0, line.find(delimiter) + delimiter.length());
        }
    }
    return res;
}

int main()
{
    int dim;
    vector<int> arr_va, arr_vs;
    PNode r;
    
    string dim_temp;
    getline(cin, dim_temp);

    dim = stoi(ltrim(rtrim(dim_temp)));

    arr_va = read_array(dim);
    
    arr_vs = read_array(dim);
    
    r = ricostruisci(arr_va, arr_vs);

    //visita_keys(r);
    
    cout << quasicompleto(r);

    return 0;
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