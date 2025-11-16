//Generating Subsets
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, b, i;
    cin >> n;
    vector<int> v(n);
    for(auto &it : v) cin >> it;
    vector<vector<int> > subsets;
    for(b = 0; b < (1 << n); b++)
    {
        vector<int> element;
        for(i = 0; i < n; i++)
        {
            if(b & (1 << i)) element.push_back(v[i]);
        }
        subsets.push_back(element);
    }
    // for(auto sub : subsets)
    // {
    //     cout << "{";
    //     for(auto ele : sub)
    //     {
    //         cout << ele << ',';
    //     }
    //     cout << "}\n";
    // }
    for(i = 0; i < subsets.size(); i++)
    {
        cout << '{';
        for(int j = 0; j < subsets[i].size(); j++) {
            cout << subsets[i][j];
            if(j != subsets[i].size() - 1) cout << ',';
        }
        cout << "}\n";
    }
}