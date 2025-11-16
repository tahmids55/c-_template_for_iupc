#include <bits/stdc++.h>
using namespace std;
int harmonic(int n)
{
    int ans = 0;
    if(n == 1) return 1;
    ans += 1 + n;
    for(int i = 2; i * i <= n; i++)
    {
        if(i != n / i) ans += i + n / i;
        else ans += i;
        int l = n / i + 1;
        int r = n / (i - 1) - 1;
        if(l <=  r) ans += (r - l + 1) * (i - 1);
    }
    return ans;
}

int harmonic_brute(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (n / i);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << harmonic(n) << '\n';
    cout << harmonic_brute(n) << '\n';
}