//MAximum/Minimum of all subarrays of size K
#include <bits/stdc++.h>
using namespace std;
vector<int> k_sized_subarray_max(vector<int> &arr, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int> > pq;
    for(int i = 0; i < arr.size(); i++)
    {
        if(i == k) ans.push_back(pq.top().first);
        if(i < k) pq.push({arr[i], i});
        else
        {
            pq.push({arr[i], i});
            while(pq.top().second <= i - k) pq.pop();
            ans.push_back(pq.top().first);
        }
    }
    return ans;
}
vector<int> k_sized_subarray_min(vector<int> &arr, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
    for(int i = 0; i < arr.size(); i++)
    {
        if(i == k) ans.push_back(pq.top().first);
        if(i < k) pq.push({arr[i], i});
        else
        {
            pq.push({arr[i], i});
            while(pq.top().second <= i - k) pq.pop();
            ans.push_back(pq.top().first);
        }
    }
    return ans;
}
int main()
{
    int n, k, i;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &it : v) cin >> it;
    vector<int> a(k_sized_subarray_max(v, k));
    vector<int> b(k_sized_subarray_min(v, k));
    for(i = 0; i < b.size(); i++)
    {
        if(i < b.size() - 1) cout << b[i] << ' ';
        else cout << b[i] << '\n';
    }
    for(i = 0; i < a.size(); i++)
    {
        if(i < a.size() - 1) cout << a[i] << ' ';
        else cout << a[i] << '\n';
    }
}