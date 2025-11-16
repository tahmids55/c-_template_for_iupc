inline int sub(int a, int b) {
    int diff = a - b;
    if (diff < 0) diff += MOD;
    return diff;
}

inline int mul(int a, int b) {
    return (int)((1LL * a * b) % MOD);
}

inline int power(int a, long long b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int mod_inv(int a) {
    return power(a, MOD - 2);
}

inline int divide(int a, int b) {
    return mul(a, mod_inv(b));
}
inline int add(int a , int b){
    int sum =  a + b ; 
    if(sum > MOD) sum -= MOD ; 
    return sum ; 
}