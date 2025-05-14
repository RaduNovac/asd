#include <bits/stdc++.h>
using namespace std;

/*
 * Problema: Longest Common Subsequence (LCS)
 *
 * 1) Definizione ricorsiva della lunghezza LCS(X[0..m-1], Y[0..n-1]):
 *
 *    Se m == 0 oppure n == 0:
 *       LCS_len(m,n) = 0
 *    Altrimenti, se X[m-1] == Y[n-1]:
 *       LCS_len(m,n) = 1 + LCS_len(m-1, n-1)
 *    Altrimenti:
 *       LCS_len(m,n) = max( LCS_len(m-1, n), LCS_len(m, n-1) )
 *      L(i,j) = 0                                     se i=0 or j=0
               = 1 + L(i-1,j-1)                        se X[i-1]=Y[j-1]
               = max( L(i-1,j), L(i,j-1) )             altrimenti

 * 
 *
 *
 * 2) Funzione bottom-up ottimizzata in spazio:
 *    int lcsOttSpazio(const string& s1, const string& s2)
 *
 *    Usando una sola array di lunghezza min(m,n)+1,
 *    alterniamo due righe per calcolare la dp corrente da quella precedente.
 *    Complessità temporale: O(m·n)
 *    Complessità spaziale: O(min(m,n))
 *
 *
 * 3) Funzione top-down + ricostruzione LCS:
 *    string lcs(const string& s1, const string& s2)
 *
 *    Costruiamo la tabella dp[m+1][n+1], poi risaliamo da dp[m][n]
 *    per ricostruire una LCS di lunghezza dp[m][n].
 *    Complessità temporale: O(m·n)
 *    Complessità spaziale: O(m·n)
 */

int lcsOttSpazio(const string& s1, const string& s2) {
    // Copio X e Y in A e B in modo da garantire |A| >= |B|
    string A = s1, B = s2;
    if (A.size() < B.size()) 
        swap(A, B);

    int m = A.size(), n = B.size();
    // c[j] corrisponde a c[i][j] nella tabella completa, per l'iterazione corrente i
    vector<int> c(n+1, 0);

    for (int i = 1; i <= m; ++i) {
        int prev_diag = 0;           // salva c[j-1] della riga precedente = dp[i-1][j-1]
        for (int j = 1; j <= n; ++j) {
            int temp = c[j];         // salva c[j] della riga precedente = dp[i-1][j]
            if (A[i-1] == B[j-1]) {
                // match: estendo la sottosequenza
                c[j] = prev_diag + 1;
            } else {
                // no-match: prendo il migliore tra saltare A o saltare B
                c[j] = max(c[j], c[j-1]);
            }
            prev_diag = temp;
        }
    }

    return c[n];
}

string lcs(const string& A, const string& B) {
    int m = A.size(), n = B.size();
    // Costruiamo la tabella dp
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // Ricostruzione della sottosequenza
    int i = m, j = n;
    string W;
    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            W.push_back(A[i-1]);
            --i; --j;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(W.begin(), W.end());
    return W;
}
int lcs_aux(const string& s1, const string& s2, vector<vector<int>>& c, int i,int j){
    if (c[i][j] == -1) {
        if (i == 0 || j == 0) {
            c[i][j] = 0;
        }
        else if (s1[i-1] == s2[j-1]) {
            c[i][j] = lcs_aux(s1, s2, c, i-1, j-1) + 1;
        }
        else {
            int X = lcs_aux(s1, s2, c, i-1, j);
            int Y = lcs_aux(s1, s2, c, i,   j-1);
            c[i][j] = max(X, Y);
        }
    }
    return c[i][j];
}

string lcs(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    // Tabella c(m+1)x(n+1), inizializzata a -1
    vector<vector<int>> c(m+1, vector<int>(n+1, -1));

    // Riempio c delle lunghezze
    lcs_aux(s1, s2, c, m, n);

    // Ricostruzione della sottosequenza
    int i = m, j = n;
    string W;
    while(i > 0 && j > 0){
        if (s1[i-1] == s2[j-1]){// Match
            W.push_back(s1[i-1]);
            i--; j--;
        }
        else if (c[i-1][j] >= c[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(W.begin(), W.end());
    return W;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    // T casi di test. Ogni caso:
    // tipo = 0 => stampare solo lunghezza
    // tipo = 1 => stampare la stringa LCS
    while (T--) {
        int tipo;
        string s1, s2;
        cin >> tipo >> s1 >> s2;

        if (tipo == 0) {
            cout << lcsOttSpazio(s1, s2) << "\n";
        } else {
            cout << lcs(s1, s2) << "\n";
        }
    }

    return 0;
}
