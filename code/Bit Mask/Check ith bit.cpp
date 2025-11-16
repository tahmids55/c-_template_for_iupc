#include <iostream>
using namespace std;

bool isBitSet(int num, int i) {
    return (num & (1 << i)) != 0;
}

int main() {
    int num = 10; // Binary: 1010
    cout << "Bit 3: " << isBitSet(num, 3) << endl; // Output: 1 (set)
    cout << "Bit 1: " << isBitSet(num, 1) << endl; // Output: 0 (not set)
    return 0;
}