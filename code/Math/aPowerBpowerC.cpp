#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int iter(int a, int b, int m)
{
    int ans = 1;
    while(b)
    {
        if(b&1) ans = (ans * 1LL * a) % m;
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}
int power(int a, int b){ // a^-1 = power(a, MOD - 2)
    int ans = 1;
    while(b){
        if(b&1) ans = (1LL * ans * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << iter(a, iter(b, c, MOD - 1), MOD) << '\n';
    }
}