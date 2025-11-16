#include <iostream>
using namespace std;

int setBit(int num, int i) {
    return num | (1 << i);
}

int main() {
    int num = 10; // Binary: 1010
    cout << "After setting bit 1: " << setBit(num, 1) << endl; // Output: 14 (1110)
    return 0;
}