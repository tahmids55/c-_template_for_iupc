pair<ll,ll> Fibo(ll n){
   if(n==0)return {0,1};
   auto p=Fibo(n/2);
   ll f=p.F;
   ll s=p.S;
   if(n%2==0){
      return {f*(2*s-f),f*f+s*s};
   }
   else{
      return {f*f+s*s,s*(s+2*f)};
   }
}
