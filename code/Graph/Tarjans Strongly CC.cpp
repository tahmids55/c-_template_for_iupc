#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<bool> inStack;
vector<int> disc , low ; 
stack<int> stk;
int timer = 0;
vector<vector<int>> Sccs;
vector<vector<int>> adj ; 
void dfs(int u){
    disc[u] = low[u] = ++timer;
    stk.push(u);
    inStack[u] = true;
    for(int v : adj[u]){
        if(disc[v] == -1){
            dfs(v);
            low[u] = min(low[u] , low[v]);
        } else if(inStack[v]){
            low[u] = min(low[u] , low[v]);
        }
    }
    if(low[u] == disc[u]){
        vector<int> scc ; 
        while(1){
            int node = stk.top(); 
            stk.pop();
            inStack[node] = false;
            scc.push_back(node);
            if(node == u){
                break;
            }
        }
        Sccs.push_back(scc);
    }
}
void reset_to(int x){
    adj.assign(x + 1 , {});
    disc.assign(x + 1 , -1);
    low.assign(x + 1 , 0);
    inStack.assign(x + 1 , false);
    Sccs.clear();
    timer = 0;
}
void solve(){
    int n , m ; 
    cin >> n >> m ; 
    reset_to(n);
    for(int i = 0 ; i < m ; i++){
        int u , v ; 
        cin >> u >> v ; 
        if(u == v) continue;
        adj[u].push_back(v);
    }
    vector<int> out_deg(n + 1);
    for(int i = 1 ; i <=n ; i++){
        out_deg[i] += adj[i].size();
    }
    for(int i = 1 ; i <= n ;i++){
        if(disc[i] == -1){
            dfs(i);
        }
    }
    cout << "Strongly Connected component" << endl;
    for(auto u : Sccs){
        for(auto x : u){
            cout << x << " ";
        }
        cout << endl;
    }

}