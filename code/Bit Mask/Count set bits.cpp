#include <iostream>
using namespace std;

int countSetBits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

int main() {
    int num = 15; // Binary: 1111
    cout << "Set bits: " << countSetBits(num) << endl; // Output: 4
    return 0;
}