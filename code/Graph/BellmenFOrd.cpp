// Which negative cycle attach edges.  
int cs = 1;
vector<int> A(1000 + 1);
struct Edges{
    int a , b , cost ; 
};
int calc(int v , int u){
    return (int)(A[v] - A[u])*(A[v] - A[u])*(A[v] - A[u]);
}
void dfs(vector<vector<int>> &adj , vector<bool> &vis , int x){
    if(vis[x]) return;
    vis[x] = true;
    for(auto u : adj[x]){
        dfs(adj , vis , u);
    }
}
void solve(int n){ 
    
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
    int r ; 
    cin >> r ; 
    vector<Edges> adj;
    vector<vector<int>> adj2(n + 1);
    for(int i = 0 ; i < r ; i++){
        int u , v ; 
        cin >> u >> v ; 
        adj2[u].pb(v);
        adj.pb({u , v , calc(v , u)});
    }
    vector<int> d(n + 1 , MAX);
    vector<int> p(n + 1 , -1);
    d[1] = 0;
    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edges e : adj) {
            if (d[e.a] + e.cost < d[e.b] && d[e.a] < MAX) {
                d[e.b] =  max(-MAX , d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }
    set<int> neg ; 
    vector<bool> InV(n + 1 , false);
    if (x == -1){
        
    } else {
        for (int i = 0; i < n; ++i) x = p[x];
    
    dfs(adj2 , InV , x);
    cout << "Set #" << cs++<<endl;
    int q ; 
    cin >> q;
    for(int i = 0 ; i < q ; i++){
        int x ; cin >> x; 
        if(d[x] == MAX or d[x] < 3 or InV[x]){
            cout << "?" << endl;
        } else {
            cout << d[x] << endl;
        }
    }
}
////////////// Cycle finnding //////////////////////
struct Edges{
    int u , v , W ;
};
void solve(){
    int n , m ; 
    cin >> n >> m ; 
    vector<Edges> edges(m);
    for(int i = 0 ; i < m ; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].W;
    }
    for(int i = 1 ; i <= n ;i++) edges.pb({0 , i , 0});
    vector<int> d(n + 1 , MAX);
    d[0] = 0;
    vector<int> par(n + 1 , -1);
    int node = -1;
    for(int i = 0 ; i <= n ; i++){
        node = -1;
        for(auto [u , v , W] : edges){
            if(d[u] < MAX && d[v] > d[u] + W){
                d[v] = d[u] + W;
                node = v ; 
                par[v] = u;
            }
        }
    }
    if(node == -1){
        cout << "NO" << endl;
        return;
    }
    int y = node ; 
    for(int i = 0 ; i < n ; i++) y = par[y];
    vector<int> path;
    int cur = y;
    do{
        path.pb(cur);
        cur = par[cur];
    }while(y != cur);
    cout << "YES" << endl;
    path.pb(path[0]);
    reverse(all(path));
    for(auto u : path){
        cout << u << " ";
    }
    cout << endl;
}