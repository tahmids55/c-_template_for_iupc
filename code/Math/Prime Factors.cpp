#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;

    // Divide by 2 as many times as possible
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for odd factors starting from 3
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is still greater than 2, it is prime
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    int n;
    cin >> n;

    vector<int> factors = primeFactors(n);

    cout << "Prime factors of " << n << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
