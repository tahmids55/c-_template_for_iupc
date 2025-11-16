#include <iostream>
using namespace std;

int toggleBit(int num, int i) {
    return num ^ (1 << i);
}

int main() {
    int num = 10; // Binary: 1010
    cout << "After toggling bit 0: " << toggleBit(num, 0) << endl; // Output: 11 (1011)
    return 0;
}