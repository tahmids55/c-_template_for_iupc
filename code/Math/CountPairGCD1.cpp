#include <bits/stdc++.h>
using namespace std;
#define int long long
int N = 1e6 + 1;
int32_t main()
{
    int n, i, j;
    cin >> n;
    vector<int> v(n), cnt(N), pair_cnt(N);
    for(i = 0; i < n; i++) cin >> v[i], cnt[v[i]]++;
    // number of elements in the array divisible by i
    cnt[1] = n;
    for(i = 2; i < N; i++) {
        for(j = i * 2; j < N; j += i) {
            cnt[i] += cnt[j];
        }
    }
    // number of pair divisible by i
    for(i = 1; i < N; i++) pair_cnt[i] = (cnt[i] * 1ll * (cnt[i] - 1)) / 2;
    // number of pair gcd = i (inclusion, exclusion)
    for(i = N - 1; i >= 1; i--) {
        for(j = i * 2; j < N; j += i) {
            pair_cnt[i] -= pair_cnt[j];
        }
    }

    cout << pair_cnt[1] << '\n';
}