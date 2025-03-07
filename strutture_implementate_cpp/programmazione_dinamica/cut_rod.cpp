//Programmazione dinamica - cut rod | ASD in C++

/* 
    g++ cut_rod.cpp -o cut_rod
    ./cut_rod
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

int memoized_cut_rod_aux(int p[], int j, int r[]){//Complessità: Theta(n^2)
    int q;
    
    if(r[j] < 0){
        if(j == 0){
            r[j] = 0;
        }
        else{
            q = -1;

            for(int i = 0; i < j; i++){
                q = max(q, p[i] + memoized_cut_rod_aux(p, j - i, r));
            }

            r[j] = q;
        }
    }

    return r[j];
}

int top_down_memoized_cut_rod(int p[], int n){//Calcola solo i sottoproblemi necessari
    int r[n];

    for(int i = 0; i < n; i++){
        r[i] = -1;
    }

    return memoized_cut_rod_aux(p, n, r);
}

int bottom_up_cut_rod(int p[], int n){//Calcola le soluzioni di tutti i sottoproblemi
    int r[n], s[n], q;

    r[0] = 0;

    for(int j = 0; j < n; j++){
        q = -1;

        for(int i = 0; i < j; i++){
            q = max(q, p[i] + r[j - i]);
        }

        r[j] = q;
    }

    return r[n];
}

//Queste funzioni non ci dicono dove tagliare, per sapere dove tagliare uso la seguente versione modificata della bottom up
void ext_bottom_up_cut_rod(int p[], int n, int r[], int s[]){
    int q;

    r[0] = 0;

    for(int j = 0; j < n; j++){
        q = -1;

        for(int i = 0; i < j; i++){
            if(q < p[i] + r[j - i]){
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }

        r[j] = q;
    }
}

int main(){
    // Test case 1: array di prezzi standard
    int prices1[] = {1, 5, 8, 9, 10, 17, 17};
    int n1 = 7;
    
    cout << "\n=== Test Case 1: Prezzi standard ===" << endl;
    cout << "Prezzi per lunghezza i+1: ";
    for(int i = 0; i < n1; i++) {
        cout << prices1[i] << " ";
    }
    cout << endl;
    
    cout << "\nConfrontiamo le implementazioni per lunghezza = 4:" << endl;
    
    // Test top-down
    cout << "Top-down memoized: " << top_down_memoized_cut_rod(prices1, 4) << endl;
    
    // Test bottom-up (correzione: passare n1-1)
    cout << "Bottom-up: " << bottom_up_cut_rod(prices1, n1-1) << endl;
    
    // Test extended bottom-up con tagli
    int r[4] = {0}, s[4] = {0};
    ext_bottom_up_cut_rod(prices1, 4, r, s);
    cout << "Extended bottom-up: " << r[3] << endl;
    
    // Stampa la sequenza dei tagli
    cout << "Sequenza dei tagli per lunghezza 4: ";
    int n = 4;
    while (n > 0) {
        cout << s[n-1] + 1 << " ";
        n = n - (s[n-1] + 1);
    }
    cout << endl;
    
    // Test case 2: prezzi crescenti linearmente
    int prices2[] = {1, 2, 3, 4, 5, 6, 7};
    int n2 = 7;
    
    cout << "\n=== Test Case 2: Prezzi crescenti linearmente ===" << endl;
    cout << "Prezzi per lunghezza i+1: ";
    for(int i = 0; i < n2; i++) {
        cout << prices2[i] << " ";
    }
    cout << endl;
    
    // Test per lunghezza 5
    cout << "\nRisultati per lunghezza = 5:" << endl;
    cout << "Top-down memoized: " << top_down_memoized_cut_rod(prices2, 5) << endl;
    cout << "Bottom-up: " << bottom_up_cut_rod(prices2, n2-1) << endl;
    
    int r2[5] = {0}, s2[5] = {0};
    ext_bottom_up_cut_rod(prices2, 5, r2, s2);
    cout << "Extended bottom-up: " << r2[4] << endl;
    cout << "Sequenza dei tagli per lunghezza 5: ";
    n = 5;
    while (n > 0) {
        cout << s2[n-1] + 1 << " ";
        n = n - (s2[n-1] + 1);
    }
    cout << endl;
    
    // Test case 3: prezzi non monotoni
    int prices3[] = {2, 5, 3, 9, 6, 11, 7};
    int n3 = 7;
    
    cout << "\n=== Test Case 3: Prezzi non monotoni ===" << endl;
    cout << "Prezzi per lunghezza i+1: ";
    for(int i = 0; i < n3; i++) {
        cout << prices3[i] << " ";
    }
    cout << endl;
    
    // Test per lunghezza 6
    cout << "\nRisultati per lunghezza = 6:" << endl;
    cout << "Top-down memoized: " << top_down_memoized_cut_rod(prices3, 6) << endl;
    cout << "Bottom-up: " << bottom_up_cut_rod(prices3, n3-1) << endl;
    
    int r3[6] = {0}, s3[6] = {0};
    ext_bottom_up_cut_rod(prices3, 6, r3, s3);
    cout << "Extended bottom-up: " << r3[5] << endl;
    cout << "Sequenza dei tagli per lunghezza 6: ";
    n = 6;
    while (n > 0) {
        cout << s3[n-1] + 1 << " ";
        n = n - (s3[n-1] + 1);
    }
    cout << endl;
    
    return 0;
}