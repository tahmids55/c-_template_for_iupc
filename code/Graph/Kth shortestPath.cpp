void solve(){
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<vector<pair<int,int>>> adj(n + 1);
    vector<priority_queue<int>> dist(n + 1);
    for(int i = 0 ; i < m ; i++){
        int u , v , w ; 
        cin >> u >> v >> w; 
        adj[u].pb({v , w});
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq ; 
    pq.push({0 , 1});
    dist[1].push(0);
    while(!pq.empty()){
        auto [d , v] = pq.top();
        pq.pop();
        if(d > dist[v].top()) continue;

        for(auto [u , w] : adj[v]){
            int D = w + d; 
            if(dist[u].size() < k){
                dist[u].push(D);
                pq.push({D , u});
            } else if(D < dist[u].top()){
                dist[u].pop();
                dist[u].push(D);
                pq.push({D , u});
            }
        }
    }
    vector<int> ans ;
    while(!dist[n].empty()){
        ans.pb(dist[n].top());
        dist[n].pop();
    }
    reverse(all(ans));
    for(auto u : ans){
        cout << u << " ";
    }
    cout << endl;
}