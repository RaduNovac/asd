#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> mergeBST(vector<int>& t1, vector<int>& t2, int val){
    int heapsize = t1.size();
    
    vector<int> t(heapsize * 2 + 1);

    int h = log2(heapsize + 1);
    cout << h << endl;
    t[0] = val;
    int x = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < pow(2, i); j++){
            t[x + pow(2, i)] = t1[x];
            t[x + pow(2, i) * 2] = t2[x];
            x++;
        }
    }
    return t;
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
    T3 = mergeBST(T1, T2, 150);

    print_vector(T1);
    print_vector(T2);
    print_vector(T3);

    return 0;
}