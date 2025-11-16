int Lis(vector<int> &a , int n){
    vector<int> d(n + 1 , MAX);
    d[0] = -MAX;
    for(int i = 0 ; i < n ; i++){
        int l = upper_bound(all(d) , a[i]) - d.begin();
        if(d[l - 1] < a[i] && a[i] < d[l]){
            d[l] = a[i];
        }
    }
    int ans = 0 ; 
    for(int i = 0 ; i <= n ; i++){
        if(d[i] < MAX){
            ans = i ; 
        }
    }
    return ans ; 
}
void solve(){
    int n ; 
    cin >> n;
    vector<int> v(n) ; 
    for(auto &u : v) cin >> u ;
    cout << Lis(v , n) << endl;
}
// vector<int> d(n + 1 , MAX);
//     vector<int> p(n + 1 , -1);
//     vector<int> pos(n + 1 , -1);
//     d[0] = -MAX;
//     for(int i = 0 ; i < n ; i++){
//         int l = upper_bound(all(d) , a[i]) - d.begin();
//         if(d[l - 1] < a[i] && a[i] < d[l]){
//             d[l] = a[i];
//             pos[l] = i;
//             p[i] = pos[l - 1];
//         }
//     }
//     int ans = 0 ; 
//     vector<int> Lr ; 
//     int id = n - 1 ;
//     while(d[id] >= MAX) id--;
//     while(id != -1){
//         Lr.pb(a[id]);
//         id = p[id];
//     } reverse(all(Lr));
//     return Lr;