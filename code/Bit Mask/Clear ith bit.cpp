#include <iostream>
using namespace std;

int clearBit(int num, int i) {
    return num & ~(1 << i);
}

int main() {
    int num = 10; // Binary: 1010
    cout << "After clearing bit 3: " << clearBit(num, 3) << endl; // Output: 2 (0010)
    return 0;
}