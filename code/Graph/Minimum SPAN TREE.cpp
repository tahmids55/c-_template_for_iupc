vector<int> parent;
vector<int> SZ;
vector<vector<pair<int,int>>> MsT;
struct Edges{
    int u , v , w;
};
int find(int x){
    if(parent[x] == x ){
        return parent[x];
    }
   return parent[x] = find(parent[x]); 
}
void Union(int x , int y){
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (SZ[x] < SZ[y]) swap(x, y);
    parent[y] = x;
    SZ[x] += SZ[y];
}
void solve(){
    int n , m ; 
    cin >> n >> m ; 
    Edges edg[m];
    for(int i = 0 ; i < m ; i++){
        cin >> edg[i].u >> edg[i].v >> edg[i].w;
    }
    parent.resize(n + 1);
    SZ.resize(n + 1);
    MsT.resize(n + 1);
    //Initialize 
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i ;
        SZ[i] = 1 ;  
    }
    //Building MST
    sort(edg , edg + m , [](const Edges &a , Edges &b){return a.w < b.w;});
    for(int i = 0 ; i < m ; i++){
        int v = edg[i].v ; 
        int u = edg[i].u ;
        int w = edg[i].w ;
        if(find(u) != find(v)){
            Union(u , v);
            MsT[v].push_back({u , w});
            MsT[u].push_back({v , w});
        }
    }
    
    //Priniting MST 
    for(int i = 1 ; i <= n ; i++){
        for(auto u : MsT[i]){
            cout << i << " "<< u.ff << " " << u.ss << endl; 
        }
    }
}