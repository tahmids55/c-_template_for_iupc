#include <iostream>
using namespace std;

int removeLastSetBit(int num) {
    return num & (num - 1);
}

int main() {
    int num = 12; // Binary: 1100
    cout << "After removing last set bit: " << removeLastSetBit(num) << endl; // Output: 8 (1000)
    return 0;
}