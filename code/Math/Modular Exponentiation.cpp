#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long modPow(long long a, long long b) {
    long long result = 1;
    while (b) {
        if (b & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

int main() {
    cout << "2^100 mod 1e9+7 = " << modPow(2, 100) << endl; // Output: 976371285
    return 0;
}