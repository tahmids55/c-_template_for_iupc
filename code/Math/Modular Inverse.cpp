#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function to perform modular exponentiation
int modPow(int base, int exp) {
    int result = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

// Function to compute modular inverse using Fermat's Little Theorem
int modInverse(int a) {
    return modPow(a, MOD - 2);
}

int main() {
    int a = 5;
    cout << "Inverse of 5 mod 1e9+7: " << modInverse(a) << endl;  // Output: 400000003
    return 0;
}