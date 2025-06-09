#include<iostream>
#include<vector>

using namespace std;

/*
    Dati due max heap, ritornare un max heap contenente l'intersezione dei due heap
*/

//Heap Sort
void max_heapify(vector<int>& v, int n, int i) {//n è la heap_size, i è il nodo radice del sottoalbero
    int max = i;
	int l = 2 * i + 1;     // Figlio sinistro
	int r = 2 * i + 2;    // Figlio destro

	// Se il figlio sinistro è più grande della radice
	if(l <= n && v[l] > v[max]){
		max = l;
	}

	// Se il figlio destro è più grande della radice
	if(r <= n && v[r] > v[max]){
		max = r;
	}

	// Se il nodo più grande non è la radice
	if(i != max){
		swap(v[i], v[max]);  // Scambia la radice con il nodo più grande
		max_heapify(v, n, max);    // Richiama heapify sul sotto-albero
	}
}

int extract_root(vector<int>& v){
    int res = v[0];

    //swap
    int tmp;
    tmp = v[0];
    v[0] = v[v.size() -1];
    v[v.size() -1] = tmp;

    v.pop_back();

    return res;
}

vector<int> intersezione(vector<int> h1, vector<int> h2){
    int n1 = h1.size();
    int n2 = h2.size();

    cout << n1 << endl << n2 << endl;

    int i = 0, j = 0;

    vector<int> res;

    while(i <= n1 && j <= n2){//Fino a quando sono nei limiti dei due array
        cout << "h1[0]: " << h1[0] << ", h2[0]: " << h2[0] << endl; 
        if(h1[0] == h2[0]){//Se sono uguali inserisco l'elemento in res e vado avanti
            res.push_back(extract_root(h1));
            extract_root(h2);
            cout << "a\n";
            max_heapify(h1, h1.size(), h1[0]);
            max_heapify(h2, h2.size(), h2[0]);

            i++;
            j++;
        }
        if(h1[0] > h2[0]){//Se la root di h1 è > di quella di h2 la scarto e rifaccio il maxheapify
            extract_root(h1);
            cout << "b\n";
            max_heapify(h1, h1.size(), h1[0]);
            i++;
        }
        else{//Allora h1[0] < h2[0]
            extract_root(h2);
            cout << "c\n";
            max_heapify(h2, h2.size(), h2[0]);
            j++;
        }
    }

    return res;
}



void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << "v[" << i << "]: " << v[i] << endl;
    }

    cout << endl;
}

int main(){
    vector<int> h1, h2;

    h1.push_back(100);
    h1.push_back(7);
    h1.push_back(25);
    h1.push_back(1);
    h1.push_back(4);
    h1.push_back(5);

    h2.push_back(101);
    h2.push_back(100);
    h2.push_back(50);
    h2.push_back(25);
    h2.push_back(5);
    h2.push_back(50);
    h2.push_back(25);
    h2.push_back(7);
    h2.push_back(1);

    print(h1);
    //print(h2);

    extract_root(h1);

    max_heapify(h1, h1.size(), h1[0]);

    print(h1);

    //vector<int> h3 = intersezione(h1, h2);

    //print(h3);

    return 0;
}