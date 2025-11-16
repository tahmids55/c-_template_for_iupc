#include <bits/stdc++.h>
using namespace std;
int getNum(vector<int>& v)
{

    // Size of the vector
    int n = v.size();

    // Generate a random number
    srand(time(NULL));

    // Make sure the number is within
    // the index range
    int index = rand() % n;

    // Get random number from the vector
    int num = v[index];

    // Remove the number from the vector
    swap(v[index], v[n - 1]);
    v.pop_back();

    // Return the removed number
    return num;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));

    int n = rand() % 15 + 1;   // [5, 24]
    int q = rand() % 8 + 1;   // [1, 10]

    freopen("in.txt", "w", stdout);
    cout << 1 << endl;
    //cout << n << " " << q << "\n";
    cout << n << endl;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        v[i] = i + 1; 
    }
    while(v.size()){
        cout << getNum(v) << " ";
    }
    cout << endl;
    string s;
    for (int i = 0; i < n; i++) {
        s += char('0' + rand() % 2);
    }
    cout << s << endl;
    //cout << s << " " << q << endl;

    // for (int i = 0; i < q; i++) {
    //     int l = rand() % n + 1;
    //     int r = rand() % n + 1;
    //     if (l > r) swap(l, r);
    //     cout << l << " " << r << "\n";
    // }
}
