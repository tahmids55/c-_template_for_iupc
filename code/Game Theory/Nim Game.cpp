#include <iostream>
using namespace std;

bool isWinningPosition(int piles[], int n) {
    int nimSum = 0;
    for (int i = 0; i < n; i++) nimSum ^= piles[i];
    return nimSum != 0;
}

int main() {
    int piles[] = {3, 4, 5};
    int n = sizeof(piles) / sizeof(piles[0]);
    cout << "Is winning position: " << isWinningPosition(piles, n) << endl; // Output: 1 (true)
    return 0;
}