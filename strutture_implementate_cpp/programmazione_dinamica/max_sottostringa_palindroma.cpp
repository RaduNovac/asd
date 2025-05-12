#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Funzione ausiliaria esterna
bool isPalindrome(const string& s, int i, int j, vector<vector<int>>& verifica){
    if (i >= j){//Se la stringa ha lunghezza < 0
        return true;
    }
    if (verifica[i][j] != -1){//Se ho già risolto il problema
        return verifica[i][j];
    }
    if (s[i] == s[j] && isPalindrome(s, i + 1, j - 1, verifica)){//Se i caratteri sono uguali e se la sottostringa in i + 1 e j - 1 è palindroma anch'essa
        return verifica[i][j] = 1;//Mi segno che la sottostringa è palindroma (1)
    }
    else{
        return verifica[i][j] = 0;//Mi segno che la sottostringa NON è palindroma (0)
    }
}

string maxPalindrome_TD_aux(const string& s, int n, vector<vector<int>>& verifica){
    int maxLen = 1, start = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(isPalindrome(s, i, j, verifica) && (j - i + 1 > maxLen)){
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    return s.substr(start, maxLen);
}

string maxPalindrome_TD(const string& s){
    int n = s.size();
    //Dentro a dp mi salvo il fatto se ho risolto o meno il problema
    vector<vector<int>> verifica(n, vector<int>(n, -1));//Inizializzo tutto a -1 per indicare non calcolato, siccome è una dichiarazione, ha costo n^2? Boh
    
    return maxPalindrome_TD_aux(s, n, verifica);
}

string maxPalindrome_BU(const string& s){
    int n = s.size();
    vector<vector<bool>> verifica(n, vector<bool>(n, false));
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) verifica[i][i] = true;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len == 2 || verifica[i+1][j-1]) {
                    verifica[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

int main(){
    string s1 = "ciaoaaaciao";
    string s2 = "canena";
    string s3 = "miciobaubau";
    string s4 = "marcocram";

    cout << "\nTop-down:\n";

    cout << "Sottostringa palindroma di lunghezza massima di: " << s1 << "e': " << maxPalindrome_TD(s1) << endl;
    cout << "Sottostringa palindroma di lunghezza massima di: " << s2 << "e': " << maxPalindrome_TD(s2) << endl;
    cout << "Sottostringa palindroma di lunghezza massima di: " << s3 << "e': " << maxPalindrome_TD(s3) << endl;
    cout << "Sottostringa palindroma di lunghezza massima di: " << s4 << "e': " << maxPalindrome_TD(s4) << endl;

    cout << "\nBottom-up:\n";

    cout << "Sottostringa palindroma di lunghezza massima di: " << s1 << "e': " << maxPalindrome_BU(s1) << endl;
    cout << "Sottostringa palindroma di lunghezza massima di: " << s2 << "e': " << maxPalindrome_BU(s2) << endl;
    cout << "Sottostringa palindroma di lunghezza massima di: " << s3 << "e': " << maxPalindrome_BU(s3) << endl;
    cout << "Sottostringa palindroma di lunghezza massima di: " << s4 << "e': " << maxPalindrome_BU(s4) << endl;
}