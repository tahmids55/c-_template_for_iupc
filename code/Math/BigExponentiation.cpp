//Big Exponenciation with multiply
// a , MOD <= 10 ^ 18
// b <= 10 ^ 9
// log^2(N)
const long long MOD = 1e18 + 7;

int binMultiply(long long a, long long b)
{
    int ans = 0;
    while(b)
    {
        if(b&1) ans = (ans + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ans;
}
int binExp(long long a, long long b)
{
    int ans = 1;
    while(b)
    {
        if(b&1) ans = binMultiply(ans, a);
        a = binMultiply(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    cout << binExp(2, 5) << endl;
}