vector<int> a ,b ; 
vector<vector<int>> dp;
int recur(int i , int j){
    if(i == 0 or j == 0) return 0 ; 
    if(dp[i][j] != -1) return dp[i][j];
    int cnt = 0;
    if(a[i - 1] == b[j - 1]){
        cnt = 1 + recur(i - 1, j - 1);
    } else {
        cnt = max(recur(i , j - 1) , recur(i - 1 , j));
    }
    return dp[i][j] = cnt ; 
}

void solve(){
    int n , m ; 
    cin >> n >> m ; 
    a.assign(n , 0);
    b.assign(m , 0);
    dp.assign(n + 1, vector<int> (m + 1, -1));
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < m ; i++) cin >> b[i];

    recur(n, m);

    vector<int> ans ; 
    int i = n , j = m ; 
    while(i > 0 && j > 0){
        if(a[i - 1] == b[j - 1]){
            ans.pb(b[j - 1]);
            i--,j--;
        } else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        } else {
            j--;
        }
    } reverse(all(ans));
    cout << ans.size() << endl;
    for(auto u : ans){
        cout << u << " ";
    }
}