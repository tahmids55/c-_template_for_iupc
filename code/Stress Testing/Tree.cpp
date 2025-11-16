#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int n = 10 + rand() % 10;
    cout << n << "\n";
    for (int i = 2; i <= n; i++) {
        int parent = rand() % (i - 1) + 1;
        cout << parent << " " << i << "\n";
    }
}
