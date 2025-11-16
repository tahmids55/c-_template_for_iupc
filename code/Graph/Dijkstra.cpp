vector<int>  dijasktra(vector<vector<pair<int,int>>> &adj , vector<int> &dist , int src , int n){
    vector<int> par(n + 1 , -1);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq ;
    dist[src] = 0 ; 
    pq.push({0, src});
    while(!pq.empty()){
        auto [d , v] = pq.top();
        pq.pop();
        if(d != dist[v]) continue ; 
        for(auto [u , w] : adj[v]){
            if(dist[v] + w < dist[u]){
                dist[u] = dist[v] + w; 
                par[u] = v ;
                pq.push({dist[u], u}); 
            }
        }
    }
    return par ; 
}
void solve(){
    int n , m ; 
    cin >> n >> m ; 
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0 ; i < m ; i++){
        int u , v , w ; 
        cin >> u >> v >> w ; 
        adj[u].ppb(v , w);
        adj[v].ppb(u , w);
    }
    vector<int> dist(n + 1 , MAX);
    vector<int> parent = dijasktra(adj , dist , 1 , n);
    if(dist[n] == MAX){
        cout << -1 << endl;
        return ; 
    }
    vector<int> path;
    int v = n ; 
    while(v != -1){
        path.pb(v);
        v = parent[v];
    }reverse(all(path));
    for(auto u : path){
        cout << u << " ";
    }
    cout << endl;
}   