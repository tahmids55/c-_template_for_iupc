#include<bits/stdc++.h>
using namespace std;

#define TT int t__t;cin>>t__t;while(t__t--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int

ll sub_sum_equal(ll *a, ll n, ll x)
{
    ll i;
    ll c=0;
    ll j,s=0;
    ll k=0;
    for(i=0;i<n;i++){
        s=s+a[i];
        if(s==x)c++;
        if(s>=x){
            s=s-a[k];
            k++;
            s=s-a[i];
            i--;
        }
    }
    return c;
}
int main()
{
    fastio
    TT
    {
        ll i,n,x;
        cin>>n>>x;
        ll a[n];
        for(i=0;i<n;i++) cin>>a[i];
        cout<<sub_sum_equal(a,n,x)<<endl;
    }
    return 0;
}

