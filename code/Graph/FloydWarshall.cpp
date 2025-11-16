#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e9 + 10;
int dist[N][N];
int main()
{
    int i, j, k;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(i == j) dist[j][j] = 0;
            else dist[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }
    // floyed warshall
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(dist[i][j] == INF) cout << 'I' << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

}