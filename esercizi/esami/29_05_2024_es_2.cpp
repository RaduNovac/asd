#include <iostream>
#include <vector>

using namespace std;

void counting_sort(vector<string>& arr, int pos){
    int n = arr.size();

    vector<string> output(n);

    int count[10] = {0};

    for(int i = 0; i < n; i++){
        int digit = arr[i][pos] - '0';
        count[digit]++;
    }

    for(int i = 8; i >= 0; i--){
        count[i] += count[i+1];
    }

    for(int i = n - 1; i >= 0; i--){
        int digit = arr[i][pos] - '0';
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void riordina(vector<string>& arr){
    for(int pos = 6; pos > 0; pos--){
        counting_sort(arr, pos);
    }
}

void printArray(const vector<string>& arr) {
    cout << "Array: [";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", " << endl;
        }
    }
    cout << "]" << endl;
}

int main(){
    vector<string> arr;

    arr.push_back("S234567");
    arr.push_back("S654321");
    arr.push_back("S468101");
    arr.push_back("S357911");
    arr.push_back("S876543");
    arr.push_back("S567890");
    arr.push_back("S111111");
    arr.push_back("S999989");
    arr.push_back("S556555");
    arr.push_back("S353333");

    riordina(arr);

    printArray(arr);

    return 0;
}