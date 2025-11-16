#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(string pat) {
    vector<int> lps(pat.size(), 0);
    int len = 0, i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

void KMPSearch(string txt, string pat) {
    vector<int> lps = computeLPS(pat);
    int i = 0, j = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i]) i++, j++;
        if (j == pat.size()) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < txt.size() && pat[j] != txt[i]) {
            if (j) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(txt, pat); // Output: Pattern found at index 10
    return 0;
}