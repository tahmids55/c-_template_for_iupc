#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<bool> vis; 
vector<bool> inStack; 
vector<int> par; 
vector<vector<int>> adj ;
int start = -1 , endd =-1 ;
void dfs(int u){
    inStack[u] = vis[u] = true ; 
    for(int v : adj[u]){
        if(!vis[v]){
            inStack[v] = true;
            par[v] = u;
            dfs(v);
            if (start != -1) return;
        } else if(inStack[v]){
            par[v] = u;
            start = v ;
            endd = u ; 
            return;
        }
    }
    inStack[u] = false;
}
void reset_to(int x){
    adj.assign(x + 1 , {});
    vis.assign(x + 1 , false);
    inStack.assign(x + 1 , false);
    par.assign(x + 1 , -1);
}
void solve(){
    int n , m ; 
    cin >> n >> m ; 
    reset_to(n);
    for(int i = 0 ; i < m ; i++){
        int u , v ; 
        cin >> u >> v ; 
        adj[u].push_back(v);
    }
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            dfs(i);
            if(start != -1){
                vector<int> path;
                path.push_back(start);
                for (int cur = endd; cur != start; cur = par[cur])
                    path.push_back(cur);
                path.push_back(start);
                reverse(path.begin(), path.end());
                cout << path.size() << endl; 
                for(auto u : path){ 
                    cout << u << " "; 
                } 
                cout << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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