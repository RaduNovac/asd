#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> mergeBST_marco(vector<int>& t1, vector<int>& t2, int val){
    int heapsize = t1.size(), x = 0;

    vector<int> t(heapsize * 2 + 1);

    int h = log2(heapsize + 1);
    t[0] = val;
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < pow(2, i); j++)
        {
            t[x + pow(2, i)] = t1[x];
            t[x + pow(2, i) * 2] = t2[x];
            x++;
        }
    }

    return t;
}

vector<int> mergeBST_prof(const vector<int>& arr1, const vector<int>& arr2, int val)
{
    vector<int> ris;//Creo il vector da ritornare alla fine
    ris.push_back(val);//Inserisco val che sarà la nuova root
    /*
        sx e dx tengono traccia degli indici in arr1 e arr2
        j rappresenta il numero di nodi da prendere da ciascun albero in ogni livello
    */
    size_t sx = 0, dx = 0, j = 1;

    while(sx < arr1.size()){//Fino a quando non processo tutti gli elementi di arr1
        size_t end = sx+j;//Mi dice fino a quali elementi di arr1 devo prendere, quindi anche di arr2

        while(sx < end){//Prendo gli elementi di arr1
            ris.push_back(arr1[sx]);
            sx++;
        }

        while (dx < end){//Prendo gli elementi di arr2
            ris.push_back(arr2[dx]);
            dx++;
        }
        /*
            Raddoppio il numero di elementi da prendere siccome siamo su
            un BST e ad ogni livello raddoppia il numero di nodi
        */
        j*=2;
    }

    return ris;
}



void print_vector(vector<int> T){
    for(int i = 0; i < T.size(); i++){
        cout << T[i] << "; ";
    }
    cout << endl;
}

int main(){
    vector<int> T1;
    T1.push_back(100);
    T1.push_back(90);
    T1.push_back(111);
    T1.push_back(82);
    T1.push_back(91);
    T1.push_back(104);
    T1.push_back(120);

    vector<int> T2;
    T2.push_back(200);
    T2.push_back(178);
    T2.push_back(230);
    T2.push_back(160);
    T2.push_back(180);
    T2.push_back(227);
    T2.push_back(239);

    vector<int> T3;
    T3 = mergeBST_prof(T1, T2, 150);

    print_vector(T1);
    print_vector(T2);
    print_vector(T3);

    return 0;
}