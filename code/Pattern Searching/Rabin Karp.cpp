#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string pat, string txt, int q = INT_MAX) {
    int M = pat.size(), N = txt.size();
    int d = 256, h = 1, p = 0, t = 0;

    for (int i = 0; i < M - 1; i++) h = (h * d) % q;
    for (int i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if (match) cout << "Pattern found at index " << i << endl;
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    rabinKarp(pat, txt); // Output: Pattern found at index 0, 10
    return 0;
}