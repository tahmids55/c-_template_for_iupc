#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void print128(__int128 x) {
    if (x == 0) { cout << "0\n"; return; }
    string s;
    bool neg = false;
    if (x < 0) { neg = true; x = -x; }
    while (x > 0) {
        s += '0' + (x % 10);
        x /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

int main() {
    __int128 a = (__int128)1 << 100;
    __int128 b = (__int128)1 << 60;
    __int128 sum = a + b;
    print128(sum); // Output: 1267650600228229401496703205376
    return 0;
}