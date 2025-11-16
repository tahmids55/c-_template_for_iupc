#include <iostream>
using namespace std;

long long power(long long a, long long b) {
    long long result = 1;
    while (b) {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}

int main() {
    cout << "2^10 = " << power(2, 10) << endl; // Output: 1024
    return 0;
}