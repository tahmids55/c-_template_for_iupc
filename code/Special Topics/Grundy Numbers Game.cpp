#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int calculateMex(unordered_set<int>& Set) {
    int mex = 0;
    while (Set.count(mex)) mex++;
    return mex;
}

int grundy(int n, int maxMove) {
    if (n == 0) return 0;
    unordered_set<int> Set;
    for (int i = 1; i <= min(maxMove, n); i++) {
        Set.insert(grundy(n - i, maxMove));
    }
    return calculateMex(Set);
}

bool isWinning(int n, int maxMove) {
    return grundy(n, maxMove) != 0;
}

int main() {
    int n = 5, maxMove = 3;
    cout << "Grundy number: " << grundy(n, maxMove) << endl; // Output: 2
    cout << "Is winning position: " << isWinning(n, maxMove) << endl; // Output: 1 (true)
    return 0;
}