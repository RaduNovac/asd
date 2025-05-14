#include <iostream>

using namespace std;

struct node{
    int key;
    node* left;
    node* right;

    node(int k, node* sx = nullptr, node* dx = nullptr)
            : key{k}, left{sx}, right{dx} {}
}; typedef node* pnode;

void three_bil_aux(pnode u, int &min, int &max){
    int min_sx, max_sx, min_dx, max_dx;

    if(u == nullptr){
        /*
        Caso base, cioè caso oltre la foglia, setto 1 perché ho contato 1 in più,
        quindi il conteggio parte effettivamente da -1.
        */
        min = -1;
        max = -1;
    }
    else{
        /*
        Fa chiamate ricorsive fino alle foglie e poi da lì continua a calcolare i
        cammini massimi e minimi percorrendoli al contrario fino alla radice.
        Nel caso base io mi trovo oltre la foglia e tolgo -1 perché effettivamente
        sono andato oltre di 1 nodo dalla struttura del mio albero avendogli passato
        un nullptr.
        */
        three_bil_aux(u -> left, min_sx, max_sx);//Sottoalbero sx
        three_bil_aux(u -> right, min_dx, max_dx);//Sottoalbero dx
        
        cout << "min_sx: " << min_sx << "\nmax_sx: " << max_sx << endl;
        cout << "min_dx: " << min_dx << "\nmax_dx: " << max_dx << endl;

        min = (min_sx <= min_dx ? min_sx : min_dx) + 1;//Aggiungo 1 perchè ho il passo dalla radice al sottoalbero
        max = (max_sx <= max_dx ? max_dx : max_sx) + 1;
    }
}

bool three_bil(pnode u){
    int min, max;

    three_bil_aux(u,min,max);//Uso una funzione ausiliaria

    cout << "min: " << min << "\nmax: " << max << endl;

    return (max - min <= 3);
}

//Un altra versione
int check(pnode root){
        int alt_sx, alt_dx;//altezza sinistra e destra
        if (!root){
            return 0;
        }

        alt_sx = check(root->left);
        alt_dx = check(root->right);


        if (alt_sx == -1 ||alt_dx == -1){
            return -1;
        }

        if (abs(alt_sx - alt_dx) > 1) return -1;

        return max(alt_sx, alt_dx) + 1;
}
bool isBalanced(pnode root){
    return check(root) != -1;
}

//Una versione generica, per un albero k bilanciato
int check(pnode root, int k){
        int alt_sx, alt_dx;//altezza sinistra e destra
        //Scorro fino alle foglie dell'albero
        if(!root){//Se l'albero non c'è, ritorno 0
            return 0;
        }

        alt_sx = check(root->left, k);
        alt_dx = check(root->right, k);


        if(alt_sx == -1 ||alt_dx == -1){//Se ho il sottoalbero sx o dx nulli ritorno -1
            return -1;
        }

        if(abs(alt_sx - alt_dx) > k){//Appena trovo due sottoalberi sbilanciati ritorno -1
            return -1;
        }

        return max(alt_sx, alt_dx) + 1;
}
bool isBalanced(pnode root, int k){
    return check(root, k) != -1;
}

int main(){
    //Albero 3_bilanciato
    node nodo_1{0};
    node nodo_2{0};
    node nodo_3{0};
    node nodo_4{0};
    node nodo_5{0};

    nodo_1.left = &nodo_2;
    nodo_1.right = &nodo_3;
    nodo_2.right = &nodo_4;
    nodo_4.left = &nodo_5;
    //Albero NON 3_bilanciato
    node nodo_6{0};
    node nodo_7{0};
    node nodo_8{0};
    node nodo_9{0};
    node nodo_10{0};

    nodo_6.left = &nodo_7;
    nodo_7.left = &nodo_8;
    nodo_8.left = &nodo_9;
    nodo_9.left = &nodo_10;
    //Albero da BIBBIA pag 73 - cammino terminabile
    node nodo_11{0};
    node nodo_12{0};
    node nodo_13{0};
    node nodo_14{0};
    node nodo_15{0};

    nodo_11.left = &nodo_12;
    nodo_11.right = &nodo_13;
    nodo_12.left = &nodo_14;
    nodo_14.right = &nodo_15;
    //soluzione prof
    if(three_bil(&nodo_11)){
        cout << "e' 3 bilanciato!" << endl;
    }
    else{
        cout << "NON e' 3 bilanciato!" << endl;
    }
    //versione generica
    if(isBalanced(&nodo_11, 3)){
        cout << "e' 3 bilanciato!" << endl;
    }
    else{
        cout << "NON e' 3 bilanciato!" << endl;
    }

    return(0);
}
