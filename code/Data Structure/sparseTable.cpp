#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int LOG = 17;
int arr[N];
int m[N][LOG]; // m[i][j] is minimum among arr[i...i+2^j-1]
int bin_log[N];
void precalc()
{
    for(int i = 2; i < N; i++) bin_log[i] = bin_log[i / 2] + 1;
}
int query(int L, int R) // O(1)
{
    int length = R - L + 1;
    int k = bin_log[length];
    return min(m[L][k], m[R - (1<<k) + 1][k]);
}

int main()
{
    precalc();
    int n, i, k;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[i][0] = arr[i];
    }
    // processing O(N*log(N))
    for(k = 0; k < LOG; k++)
    {
        for(i = 0; i + (1 << k) - 1 < n; i++)
        {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
    // answer query;
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}