/*
Si consideri un albero ternario completo in cui ogni nodo ha i seguenti campi: 
1) key: chiave intera 
2) fruitful: valore booleano 
3) left: puntatore al figlio sinistro 
4) center: puntatore al figlio centrale 
5) right puntatore al figlio destro 

Si scriva una procedura efficiente in C++ che assegni True al campo fruitful del nodo se e solo se 
la somma delle chiavi dei nodi di ciascuno dei sottoalberi radicati nei figli è 
maggiore di una costante k fornita in input.
Il prototipo della procedura è:

void set_fruitful(PTNode r, int k)

Analizzare e motivare in modo chiaro, preciso ed approfondito la complessità della procedura, 
indicando eventuali relazioni di ricorrenza e mostrando la loro risoluzione.
Il tipo PTNode è così definito:
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
  bool fruitful;
  Node* left;
  Node* center;
  Node* right;
};

typedef Node* PTNode;

void set_fruitful(PTNode r, int k);
vector<int> ricostruisci_array(int dim);

int sum_subtree(PTNode r){
    if(r == nullptr){
        return 0;
    }
    else{
        return r -> key + sum_subtree(r->left) + sum_subtree(r->center) + sum_subtree(r->right);
    }
}

void set_fruitful(PTNode r, int k) {
    if(r == nullptr){
        return;
    }
    
    set_fruitful(r->left, k);
    set_fruitful(r->center, k);
    set_fruitful(r->right, k);
    
    int sum_sx = r->left ? sum_subtree(r->left) : 0;
    int sum_cx = r->center ? sum_subtree(r->center) : 0;
    int sum_dx = r->right ? sum_subtree(r->right) : 0;
    
    r->fruitful = (sum_sx > k && sum_cx > k && sum_dx > k);
}

PTNode creaAlbero(vector<int>& arr, int p, int f){
    if (p > f)
        return nullptr;
    size_t ter = (f - p)/3;
    PTNode root = new Node{arr[p], false, nullptr, nullptr, nullptr};
    root->left = creaAlbero(arr, p+1, p + ter);
    root->center = creaAlbero(arr, p+ter+1, p+2*ter);
    root->right = creaAlbero(arr, p+2*ter+1, f);
    return root;
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

void visita_keys(PTNode r) {
    if (r) {
        cout << r->key << ", ";
        visita_keys(r->left);
        visita_keys(r->center);
        visita_keys(r->right);
    }
}

void visita(PTNode r) {
    if (r) {
        cout << (r->fruitful ? "t" : "f");
        visita(r->left);
        visita(r->center);
        visita(r->right);
    }
}

int main()
{
    int dim, k;
    vector<int> arr;
    PTNode r;

    string k_temp;
    getline(cin, k_temp);

    k = stoi(ltrim(rtrim(k_temp)));
    
    string dim_temp;
    getline(cin, dim_temp);

    dim = stoi(ltrim(rtrim(dim_temp)));

    arr = read_array(dim);
    
    //for(int i = 0; i < arr.size(); i++)
    //    cout << arr[i] << "; ";
    //cout << endl;
    
    r = creaAlbero(arr, 0, dim-1);

    //visita_keys(r);
    
    set_fruitful(r, k);
    
    visita(r);

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