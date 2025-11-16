// Prime Sieve
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e8 + 10;
vector<bool> isPrime(MAX, true);

vector<int> precalculate() {
    for(int i = 2; i*i <= MAX; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < MAX; j += i) isPrime[j] = false;
        }
    }
    vector<int>primes;
    for(int i = 2; i < MAX; i++) if(isPrime[i]) primes.push_back(i);
    return primes;
}
int main()
{
    auto primes = precalculate();
    for(auto p : primes) cout << p << " ";
    puts("");
    cout << primes.size() << '\n';
}