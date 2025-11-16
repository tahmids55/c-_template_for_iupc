#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > g;
vector<vector<int> > timeLevel;
vector<vector<bool> > vis;
vector<vector<pair<int, int> > > parent;
vector<pair<int, int> > monsters, moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, sx, sy, ex, ey;
bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m && g[i][j] != '#';
}
bool isEscape(int x, int y, int timer)
{
    if(!isValid(x, y)) return false;
    if(timer >= timeLevel[x][y]) return false;
    if(x == 0 || y == 0 || x == n - 1 || y == m - 1) return true;
    return false;
}
bool bfs_escape(int sx, int sy)
{
    vis.clear();
    vis.resize(n + 1, vector<bool>(m + 1, false));
    queue<pair<pair<int, int>, int> > q;
    q.push({{sx, sy}, 0});
    vis[sx][sy] = true;
    while(!q.empty())
    {
        auto [x, y] = q.front().first;
        int timer = q.front().second;
        q.pop();
        timer++;
        for(int k = 0; k < 4; k++)
        {
            int X = x + moves[k].first;
            int Y = y + moves[k].second;
            if(isValid(X, Y) && !vis[X][Y] && g[X][Y] != 'M')
            {
                q.push({{X, Y}, timer});
                parent[X][Y] = {x, y};
                if(isEscape(X, Y, timer))
                {
                    ex = X;
                    ey = Y;
                    return true;
                }
                vis[X][Y] = true;
                
            }
        }
    }
    return false;
}
void precalcMonsters()
{
    queue<pair<pair<int, int>, int> > q;
    for(auto [x, y] : monsters) 
    {
        q.push({{x, y}, 0});
        vis[x][y] = true;
    }
    while(!q.empty())
    {
        auto [x, y] = q.front().first;
        int timer = q.front().second;
        q.pop();
        timer++;
        for(int k = 0; k < 4; k++)
        {
            int X = x + moves[k].first;
            int Y = y + moves[k].second;
            if(isValid(X, Y) && !vis[X][Y])
            {
                q.push({{X, Y}, timer});
                timeLevel[X][Y] = timer;
                vis[X][Y] = true;
            }
        }
    }
}
string path()
{
    string s;
    while(g[ex][ey] != 'A')
    {
        auto[px, py] = parent[ex][ey];
        if(px + 1 == ex && py == ey) s += 'D';
        if(px - 1 == ex && py == ey) s += 'U';
        if(px == ex && py + 1 == ey) s += 'R';
        if(px == ex && py - 1 == ey) s += 'L';
        tie(ex, ey) = parent[ex][ey];
    }
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    int i, j;
    cin >> n >> m;
    g.resize(n + 1, vector<char>(m + 1));
    timeLevel.resize(n + 1, vector<int>(m + 1, INT_MAX));
    vis.resize(n + 1, vector<bool>(m + 1, false));
    parent.resize(n + 1, vector<pair<int, int> > (m + 1));
    for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
    {
        cin >> g[i][j];
        if(g[i][j] == 'M') monsters.push_back({i, j});
        if(g[i][j] == 'A') sx = i, sy = j;
    }
    precalcMonsters();
    if(sx == 0 || sy == 0 || sx == n - 1 || sy == m - 1) cout << "YES\n0\n";
    else if(bfs_escape(sx, sy))
    {
        string p = path();
        cout << "YES\n" << p.size() << '\n' << p << '\n';
    }
    else cout << "NO\n";
}

/*
Input:

5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
Output:

YES
5
RRDDR
*/