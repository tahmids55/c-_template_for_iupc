//Lowest/Highest Prime
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e8 + 10;
vector<bool> isPrime(MAX, true);
vector<int> lp(MAX), hp(MAX);
void precalculate() {
    for(int i = 2; i <= MAX; i++) {
        if(isPrime[i]) {
            lp[i] = hp[i] = i;
            for(int j = 2 * i; j <= MAX; j += i) {
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
}

int main()
{
    precalculate();
    for(int i = 0; i < 20; i++) cout << i << '\t' << lp[i] << '\t' << hp[i] << '\n';

    //prime factorization using lp/hp

    int n = 2 * 2 * 3 * 5 * 5 * 7;
    vector<int> v;
    while(n > 1)
    {
        int factor = hp[n];
        // int factor = lp[n];
        while(n % factor == 0) n /= factor, v.push_back(factor);
    }
    for(auto it : v) cout << it << ' ';
}