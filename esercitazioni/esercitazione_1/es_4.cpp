#include<iostream>
#include<vector>

using namespace std;
int occ(const vector<int>& v, int k) {
    int occorrenze = 0, index = -1;
    //Cerco la prima occorrenza di k e mi salvo l'indice
    for(int i = 0; i < v.size() && index == -1; i++){
        if(v[i] == k){
            index = i;
        }
    }
    //Partendo dall'indice cerco tutte le occorrenze fino a quando v[i] è uguale a k, non vado oltre perché so che il vettore è ordinato in modo decrescente
    for(int i = index; i < v.size() && v[i] == k; i++){
        if(v[i] == k){
            occorrenze++;
        }
    }
    
    return occorrenze;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    cout << occ(v,k) << endl;
}