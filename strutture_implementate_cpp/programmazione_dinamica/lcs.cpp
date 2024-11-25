//Programmazione dinamica - lcs | ASD in C++

/* 
    g++ lcs.cpp -o lcs
    ./lcs
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

void bottom_up_lcs(const string& X, const string& Y, vector< vector<int> >& b, vector< vector<int> >& c) {
    int m = X.length(), n = Y.length();

    // Inizializzazione degli array, tutti inizializzati a 0
    c = vector< vector<int> >(m + 1, vector<int>(n + 1, 0));
    b = vector< vector<int> >(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (X[i] == Y[j]) {
                c[i+1][j+1] = c[i][j] + 1;
                b[i][j] = 1;// Diagonale
            }
            else {
                if (c[i][j+1] >= c[i+1][j]) {
                    c[i+1][j+1] = c[i][j+1];
                    b[i][j] = 2;// Su
                }
                else {
                    c[i+1][j+1] = c[i+1][j];
                    b[i][j] = 3;// Sx
                }
            }
        }
    }
}

// Ritorna l'LCS tra le due stringhe X e Y
int top_down_lcs(string &X, string &Y, int m, int n) {
  
    // Caso base: se almeno una stringa è vuota vuol dire che l'LCS è 0
    if (m == 0 || n == 0)
        return 0;
    // Se l'ultimo carattere di entrambe le sottostringhe combacia
    if (X[m - 1] == Y[n - 1]){
        // Includo il carattere nell'LCS e faccio la chiamata ricorsiva sulle sottostringhe rimanenti
        return 1 + top_down_lcs(X, Y, m - 1, n - 1);
    }
    else
        /*
            Se gli ultimi caratteri non corrispondono ho due casi:
            - Escludo l'ultimo carattere di X
            - Escludo l'ultimo carattere di Y
        */
        return max(top_down_lcs(X, Y, m, n - 1), top_down_lcs(X, Y, m - 1, n));
}

int main(){
    string X = "AGGTAB", Y = "GXTXAYB";
    int m = X.length(), n = Y.length();
    //Matrici
    vector< vector<int> > b, c;

    cout << "Lunghezza LCS Top-Down tra X:" << X << ", e Y: " << Y << " = " << top_down_lcs(X, Y, m, n) << endl;

    bottom_up_lcs(X, Y, b, c);
    cout << "Lunghezza LCS Bottom-Up tra X: "<< X << ", e Y: " << Y << " = " << c[m][n] << endl;

    return 0;
}