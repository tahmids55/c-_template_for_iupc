#include <iostream>
using namespace std;

bool isPowerOfTwo(int num) {
    return (num & (num - 1)) == 0;
}

int main() {
    int num = 16;
    cout << "Is power of two: " << isPowerOfTwo(num) << endl; // Output: 1 (true)
    return 0;
}