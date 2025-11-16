struct Edge{
    int u , v , w ;
};
void johnson_vaiji(int n , vector<Edge> &edges){
    vector<Edge> G = edges;
    for(int i = 1 ; i <= n ; i++){
        G.pb({n + 1, i , 0});
    }
    vector<int> d(n + 2 , MAX);
    d[n + 1] = 0 ; 
    int x = -1 ;
    for(int i = 0 ; i <= n ; i++){
        x = -1 ;
        for(auto [u , v , w] : G){
            if(d[u] < MAX && d[u] + w < d[v]){
                d[v] = d[u] + w ;
                x = v ;
            }
        }
    }
    if(x != -1){
        printf("graph %d no\n\n" , cs++);
        return;
    }
    printf("graph %d yes\n\n" , cs++);
    for(int i = 1 ; i <= n + 1; i++){
        cout << d[i] << " ";
    }cout << "\n\n" ;

    vector<vector<pair<int,int>>> adj(n + 1); 
    for(auto [u , v , w] : edges){
        int nw =  w + d[u] - d[v] ;
        adj[u].pb({v , nw});
    }
    for(int i = 1 ; i <= n ; i++){
        vector<int> dis(n + 1 , MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ; 
        pq.push({0 , i});
        dis[i] = 0 ; 
        while(!pq.empty()){
            auto [D , u] = pq.top();
            pq.pop();
            if(D > dis[u]) continue;
            for(auto [v , w] : adj[u]){
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w ;
                    pq.push({dis[v] , v});
                } 
            }
            
        }
        
        for(int j = 1 ; j <= n ; j++){
            if(dis[j] == MAX){
                cout << "# " ;
                continue;
            }
            cout << dis[j] - d[i] + d[j] << " "; 
        }cout << endl;
    }
    cout << endl;
}
void solve(){
    int n  , m ; 
    cin >> n >> m ; 
    vector<Edge> edges; 
    for(int i = 0 ; i < m ; i++){
        int u , v , w ; 
        cin >> u >> v >> w; 
        edges.pb({u , v , w});
    }
    if(n == 1 && m == 0){
        printf("graph %d yes\n\n" , cs++);
        cout <<"0 0" << endl << endl;
        cout << "0" << endl << endl;
        return;
    }
    johnson_vaiji(n , edges);
}