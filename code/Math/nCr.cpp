// nCr
#include <bits/stdc++.h>
using namespace std;
typedef     long long      ll;
const ll MOD = 1e9 + 7;
const ll MAX = 1e5+5;

ll bigMod(ll a, ll b)
{
    if(b == 0) return 1;
    ll m = b/2;
    ll a_m = bigMod(a, m); // a_m = a^m
    if(b&1)
    {
        return ((a_m * a_m)%MOD * a)%MOD;
    }
    return (a_m * a_m)%MOD;
}

ll fac[MAX]; // n!
ll faci[MAX]; // 1 / n!

void precalc()
{
    fac[0] = 1;
    for(int i = 1; i < MAX; i++)
    {
        fac[i] = i * fac[i-1];
        fac[i] %= MOD;
    }
    faci[MAX-1] = bigMod(fac[MAX-1], MOD-2); // modular inverse
    for(int i = MAX - 2; i >= 0; i--)
    {
        faci[i] = ((i+1) * faci[i+1])%MOD;
    }
}

int nCr(int n, int r)
{
    if(r > n) return 0;
    return (((fac[n] * faci[r])%MOD)*faci[n-r])%MOD;
}

int main()
{
    int n, r;
    precalc();
    while(cin >> n >> r) {
        cout << nCr(n, r) << endl;
    }
    return 0;
}
