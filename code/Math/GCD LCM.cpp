#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    cout << "GCD(48, 18) = " << gcd(48, 18) << endl; // Output: 6
    cout << "LCM(6, 8) = " << lcm(6, 8) << endl;     // Output: 24
    return 0;
}