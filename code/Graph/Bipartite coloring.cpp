void bfs(int x , vector<vector<int>> &adj , vector<set<int>> &node , vector<bool> &vis , vector<int> &c){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u : adj[v]){
            if(!vis[u]){
                node[x].insert(u);
                q.push(u);
                vis[u] = true;
                c[u] = c[v] ^ 1;
            }
        }
    }
}
void solve(){
    int n;
    cin >> n; 
    int mx = 0;
    vector<pair<int,int>> vp;
    set<int> st;
    for(int i = 0 ; i < n ; i++){
        int x , y ; 
        cin >> x >> y ;
        x--,y--;    
        vp.ppb(x , y);
        st.insert(x) , st.insert(y);
    }
    int mx_el = *max_element(all(st));
     
    vector<vector<int>>adj(mx_el + 1);
    vector<set<int>> node(mx_el + 1);
    vector<bool>vis(mx_el + 1);
    vector<int> c(mx_el + 1);
    for(int i = 0 ; i < n ; i++){
        adj[vp[i].ff].pb(vp[i].ss);
        adj[vp[i].ss].pb(vp[i].ff);
    }


    for(auto u : st){
        if(!vis[u]) bfs(u , adj , node , vis, c);
    }
    int ans = 0 ;
    for(auto u : st){
        int cnt = 0 , cnt1 = 0 ;
        for(auto x : node[u]){
            if(c[x]) cnt1++;
            else cnt++;
        }
        ans += max(cnt1 , cnt);
    }  
    cout << ans << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int t;
    int cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}