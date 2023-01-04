#include <iostream>

using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node* p;

    node(int k, node* padre = nullptr, node* sx = nullptr, node* dx = nullptr)
            : key{k}, p{padre}, left{sx}, right{dx} {}
}; typedef node* pnode;

void three_bil_aux(pnode u, int &min, int &max){
    int minsx, maxsx, mindx, maxdx;

    if(u == nullptr){//Caso base
        min = -1;
        max = -1;
    }
    else{
        three_bil_aux(u -> left, minsx, maxsx);
        three_bil_aux(u -> right, mindx, maxdx);

        min = (minsx <= mindx ? minsx : mindx) + 1;//Aggiungo 1 perchè ho il passo dalla radice al sottoalbero
        max = (mindx != maxdx ? maxdx : maxsx) + 1;
    }
}

bool three_bil(pnode u){
    int min, max;

    three_bil_aux(u,min,max);//Uso una funzione ausiliaria

    return (max - min <= 3);
}

int main() {
    //Albero 3_bilanciato
    node nodo_1{0};
    node nodo_2{0,&nodo_1};
    node nodo_3{0,&nodo_1};
    node nodo_4{0,&nodo_2};
    node nodo_5{0,&nodo_4};

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

    if(three_bil(&nodo_6)){
        cout << "e' 3 bilanciato!" << endl;
    }
    else{
        cout << "NON e' 3 bilanciato!" << endl;
    }

    return(0);
}
