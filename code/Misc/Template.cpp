#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;}
inline long long ceill(ll a , ll b){return (a % b == 0 ? a / b : a / b + 1);}
inline long long lcm(ll a , ll b){return a * b / gcd(a, b);}
#define MOD 1000000007
#define pb push_back
#define ppb emplace_back
#define int long long
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
void solve(){
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}