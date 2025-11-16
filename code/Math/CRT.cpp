#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void Dio_eq_solve(ll aa, ll b, ll c, ll *xx, ll *yy);
void near_zero_solve_for_x(ll a, ll b, ll c, ll *x, ll *y);
ll inverse_modulo(ll a, ll b, ll *x, ll *y);

ll CRT(ll *a, ll *m, ll n)
{
    ll mp,i,y;
    ll p,q;
    mp=1;
    for(i=0;i<n;i++){
        mp=mp*m[i];
    }
    ll x=0;
    for(i=0;i<n;i++){
        y=inverse_modulo(mp/m[i],m[i],&p,&q);
        x=x+(a[i]*mp/m[i]*y)%mp;
    }
    return x%mp;
}


int main()
{

    ll i;
    ll n;
    cin>>n;
    ll a[n],m[n];
    for(i=0;i<n;i++){
        cin>>a[i]>>m[i];
    }
    ll ans=CRT(a,m,n);
    cout<<ans<<endl;
    return 0;
}

void Dio_eq_solve(ll aa, ll b, ll c, ll *xx, ll *yy)
{
    ll a[100],q[100],x[100];
    ll neg_a=0,neg_b=0;
    if(aa<0){
            neg_a++;
            aa=-aa;
    }
    if(b<0){
            neg_b++;
            b=-b;
    }

    if(aa>b){
        a[0]=aa;
        a[1]=b;
    }
    else{
        a[0]=b;
        a[1]=aa;
    }
    ll n,i;
    for(i=1;;i++){
        if(i>1){
            a[i]=a[i-2]%a[i-1];
        }
        if(a[i]!=0){
            q[i]=a[i-1]/a[i];
        }

        if(a[i]==0) {
            n=i;
            break;
        }
    }
    if(n>0){
        x[n]=c;
        x[n-1]=0;
    }
    if(n>1){
        for(i=n-2;i>=0;i--){
            x[i]=x[i+2]-x[i+1]*q[i+1];
        }
    }
    if(aa>b){
        *xx=x[1];
        *yy=x[0];
    }
    else{
        *xx=x[0];
        *yy=x[1];
    }
    if(neg_a) *xx=-(*xx);
    if(neg_b) *yy=-(*yy);
}


void near_zero_solve_for_x(ll a, ll b, ll c, ll *x, ll *y)
{
    Dio_eq_solve(a,b,c,x,y);
    double k= -(double)(*x)/b;

    if(b>0){
        k=ceil(k);
    }
    else{
        k=floor(k);
    }
    *x=*x+k*b;
    *y=*y-k*a;

}
ll inverse_modulo(ll a, ll b, ll *x, ll *y)
{
    near_zero_solve_for_x(a,-b,1,x,y);
    return *x;
}


