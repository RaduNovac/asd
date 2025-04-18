#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeBST(vector<int>& arr1, vector<int>& arr2, int val){
    vector<int> res(2 * arr1.size() + 1);

    int n = arr1.size();

    res[0] = val;

    for(int i = 0; i < n; i++){
        res[i + 1] = arr1[i];
        res[i + 1 + n] = arr2[i];
    }

    return res;
}

/*
vector<int> mergeBST2(vector<int>& arr1, vector<int>& arr2, int val){
    return {arr1.begin(), arr1.end(), val, arr2.begin(), arr2.end()};
}
*/

vector<int> mergeBST3(vector<int>& arr1, vector<int>& arr2, int val){
    vector<int> res;
    res.reserve(arr1.size() + arr2.size() + 1); // per efficienza

    res.insert(res.end(), arr1.begin(), arr1.end());
    res.push_back(val);
    res.insert(res.end(), arr2.begin(), arr2.end());

    return res;
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