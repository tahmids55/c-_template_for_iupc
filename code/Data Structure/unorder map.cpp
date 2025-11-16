//Author :: iamawarrior
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;}
inline long long ceill(ll a , ll b){return (a % b == 0 ? a / b : a / b + 1);}
inline long long lcm(ll a , ll b){return a * b / gcd(a, b);}
#define endl '\n'
#define MOD 1000000007
#define MAX 1e18
#define pb push_back
#define ppb emplace_back
#define int long long
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
using ull = unsigned long long;
using u64 = uint64_t;
using i64 = long long;

// ---------- splitmix64 custom hash (fast + anti-hack) ----------
struct custom_hash {
    static u64 splitmix64(u64 x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    // randomized seed per process
    static const u64 FIXED_RANDOM;
    size_t operator()(u64 x) const noexcept {
        return (size_t) splitmix64(x + FIXED_RANDOM);
    }
    template<typename T, typename U>
    size_t operator()(const pair<T,U>& p) const noexcept {
        u64 a = (u64) ( (u64)(uint32_t)p.first << 32 | (uint32_t)p.second );
        return (size_t) splitmix64(a + FIXED_RANDOM);
    }
};
const u64 custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

// ---------- convenient aliases ----------
template<class K, class V>
using umap = unordered_map<K, V, custom_hash>;

template<class K>
using uset = unordered_set<K, custom_hash>;

// ---------- helper init functions ----------
// call init_map(m, expected_elements) to reserve and set load factor
template<typename Map>
inline void init_map(Map &m, size_t expected_elements, float load_factor = 0.7f) {
    m.max_load_factor(load_factor);
    m.reserve(expected_elements + 8); // small cushion
}

// init vector of maps for adjacency-like use
template<typename Map>
inline void init_vec_maps(vector<Map> &vec, size_t nodes, size_t expected_each = 0, float load_factor = 0.7f) {
    vec.assign(nodes, Map());
    if(expected_each == 0) return;
    for(size_t i = 0; i < nodes; ++i) {
        vec[i].max_load_factor(load_factor);
        vec[i].reserve(expected_each);
    }
}

// ---------- helper for packed uint64 key (undirected canonical) ----------
inline u64 pack_key_int(int a, int b) {
    if (a > b) swap(a,b); // canonical order for undirected
    return ( (u64)(uint32_t)a << 32 ) | (uint32_t)b;
}
void dijasktra(vector<vector<pair<int,int>>> &adj , vector<int> &dist , int src , int n){
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
                pq.push({dist[u], u}); 
            }
        }
    }
}
void solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q ;
    umap<u64, int> mp;                 // key = pack_key_int(u,v)
    init_map(mp, m);                   // reserve to avoid rehash
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        u64 key = pack_key_int(u,v);
        auto it = mp.find(key);
        if(it==mp.end()) mp.emplace(key, w);
        else it->second = min(it->second, w);
    }
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> deg(n+1, 0);
    for (auto &kv : mp) {
        u64 key = kv.first;
        int a = int32_t(key >> 32);
        int b = int32_t(key & 0xffffffffULL);
        deg[a]++;
        deg[b]++;
    }
    for (int i = 1; i <= n; ++i) if (deg[i]) adj[i].reserve(deg[i]);
    for (auto &kv : mp) {
        u64 key = kv.first;
        int w = kv.second;
        int a = int32_t(key >> 32);
        int b = int32_t(key & 0xffffffffULL);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<vector<int>> dist(n + 1 , vector<int> (n + 1 , MAX));
    for(int i = 1 ; i <= n ; i++){
        dijasktra(adj , dist[i] , i , n);
    }
    for(int i = 0 ; i < q ; i++){
        int x , y; 
        cin >> x >> y; 
        if(dist[x][y] == MAX){
            cout << -1 << endl;
            continue;
        }
        cout << dist[x][y] << endl;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1; 
    while(t--){
        solve();
    }
    return 0;
}