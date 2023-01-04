#include <iostream>
#include<stack>

using namespace std;

struct node{
	int key;
	node* left;
	node* right;
	node* p;

	node(int k, node* padre = nullptr, node* sx = nullptr, node* dx = nullptr)
		: key{k}, p{padre}, left{sx}, right{dx} {}
}; typedef node* pnode;



int contacentrali_aux(pnode u, int sum, int &numf){
	int nodic, nodisx, numfsx, nodidx, numfdx;

	if(u == nullptr){//Caso base
		numf = 0;
		return 0;
	}

	if(u -> left == nullptr && u -> right == nullptr){//Caso foglia
		numf = 1;
		nodic = 0;
	}

	else{
		nodisx = contacentrali_aux(u -> left, sum + u -> key, numfsx);
		nodidx = contacentrali_aux(u -> right, sum + u -> key, numfdx);

		numf = numfsx + numfdx;
		nodic = nodisx + nodidx;
	}

	if(numf == sum + u -> key){
		return nodic + 1;
	}

	return nodic;
}

int contacentrali(pnode u){
	int numfoglie;//La userò come output

	return contacentrali_aux(u,0,numfoglie);
}

void visita_DFS(node *u){

    stack<node> s;//Uno stack  di nodi

    s.push(*u);

    while(!s.empty()){
        node x = s.top();

        if(&x != nullptr){
            cout << x.key <<endl;

            s.push(*x.right);
            s.push(*x.left);
        }
    }
}

int main() {
	node nodo_1{0};
    node nodo_2{2,&nodo_1};
    node nodo_3{3,&nodo_1};
    node nodo_4{1,&nodo_2};
    node nodo_5{-1,&nodo_2};

    nodo_1.left = &nodo_2;
    nodo_1.right = &nodo_3;
    nodo_2.left = &nodo_4;
    nodo_2.right = &nodo_5;

    //cout << nodo_2.right->key << endl;

    //visita_DFS(&nodo_1);

    cout << "Numero nodi centrali: " << contacentrali(&nodo_1) <<endl;


  return(0);
}
