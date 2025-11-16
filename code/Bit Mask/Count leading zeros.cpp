#include <iostream>
#include <bitset>
using namespace std;

int countLeadingZeros(unsigned int num) {
    if (num == 0) return sizeof(num) * 8;
    return __builtin_clz(num);
}

int main() {
    unsigned int num = 1; // Binary: 000...0001
    cout << "Leading zeros: " << countLeadingZeros(num) << endl; // Output: 31 (on 32-bit systems)
    return 0;
}