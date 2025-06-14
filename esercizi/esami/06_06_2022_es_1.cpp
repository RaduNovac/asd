#include<iostream>
#include<vector>

/*
Sia T un albero binario. Si vogliono stampare le chiavi di T memorizzate in nodi il cui sottoalbero radicato nel
figlio sinistro contiene più chiavi del sottoalbero radicato nel figlio destro. 

Scrivere una procedura efficiente in C o C++ per risolvere il problema proposto. 
*/

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

void funzione(PNode u, int& sum){
	if(!u)  return;
	else{
		int sum_sx = 0, sum_dx = 0;

		funzione(u -> left, sum_sx);
		funzione(u -> right, sum_dx);

		sum = 1 + sum_sx + sum_dx;

		if(sum_sx > sum_dx){
			cout << "chiave: " << u -> key << endl;
		}
	}
}

int marco(vector<int> &v, PNode u){
    if(u != nullptr){
        int left = marco(v, u -> left);
        int right = marco(v, u -> right);

        if(left > right){
            v.push_back(u -> key);
        }

        return 1 + left + right;
    }

    return 0;
}

void stampa(PNode root){
    vector<int> v;
    marco(v, root);

    for(int i = 0; i < v.size();i++){
        cout << "v[" << i << "]: " << v[i] << endl;
    }
}

int main(){
    // costruisco i nodi foglia
    PNode n21 = new Node{21, nullptr, nullptr};
    PNode n35 = new Node{35, nullptr, nullptr};
    PNode n45 = new Node{45, nullptr, nullptr};

    // costruisco i genitori
    PNode n25 = new Node{25, n21, nullptr};     // 25 ha solo figlio sinistro 21
    PNode n40 = new Node{40, n35, n45};         // 40 ha figli 35 (sx) e 45 (dx)

    // il nodo radice
    PNode root = new Node{30, n25, n40};        // 30 ha sottoalberi 25 e 40

    // chiamo la funzione
    int total = 0;
    cout << "Nodi con |sottoalbero sx| > |sottoalbero dx|:" << endl;
    funzione(root, total);

    stampa(root);

    return 0;
}