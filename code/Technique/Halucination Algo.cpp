int n; 
bool valid(vector<vector<int>> &v , int i , int j){
    if(i >= n or i < 0 or j >= n or j < 0) return false;
    if(v[i][j] != 0) return false;
    return true;
}
void solve(){
    cin >> n ;
    int k = 1; 
    vector<vector<int>> v(n , vector<int> (n));
    string s = "";
    for(int i = 0 ; i < 500 ; i++){
        s += "DRUL";
    }
    pair<int,int> cur = {0 , 0};
    int res = n * n - 1 ; 
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == 'D'){
            for(int j = cur.ff ; j <= n ; j++){
                if(valid(v , j , cur.ss)){
                    v[j][cur.ss] = res;
                    res--;
                } else {
                    cur.ff = j - 1;
                    cur.ss++;
                    break;
                }
            }
        } else if(s[i] == 'R'){
            for(int j = cur.ss ; j <= n ; j++){
                if(valid(v , cur.ff , j)){
                    v[cur.ff][j] = res ;
                    res--;
                } else {
                    cur.ss = j - 1; 
                    cur.ff--;
                    break;
                }
            }
        } else if(s[i] == 'U'){
            for(int j = cur.ff ; j > -2 ; j--){
                if(valid(v , j , cur.ss)){
                    v[j][cur.ss] = res ;
                    res--;
                } else {
                    cur.ff = j + 1; 
                    cur.ss--;
                    break;
                }
            }
        } else {
            for(int j = cur.ss ; j > -2 ; j--){
                if(valid(v , cur.ff , j)){
                    v[cur.ff][j] = res ;
                    res--;
                } else {
                    cur.ss = j + 1; 
                    cur.ff++;
                    break;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
// g++ taki.cpp -o taki && taki <input.txt> output.txt