#include <bits/stdc++.h>
using namespace std;
class ST{
    vector<int> seg, lazy;
    public:
    ST(int n)
    {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }
    void build(int indx, int lo, int hi, int arr[])
    {
        if(lo == hi)
        {
            seg[indx] = arr[lo];
            return;
        }
        int mid = (lo + hi) >> 1;
        build(2 * indx + 1, lo, mid, arr);
        build(2 * indx + 2, mid + 1, hi, arr);
        seg[indx] = seg[2 * indx + 1] + seg[2 * indx + 2];
    }
    void update(int indx, int lo, int hi, int l, int r, int val)
    {
        // update the previous remaining updates and propagate downwards
        if(lazy[indx] != 0)
        {
            seg[indx] += (hi - lo + 1) * lazy[indx];
            // propagate the lazy update downwards for the remaining nodes to get updated
            if(lo != hi)
            {
                lazy[2 * indx + 1] = lazy[indx];
                lazy[2 * indx + 2] = lazy[indx];
            }
            lazy[indx] = 0;
        }
        // no overlap = do nothing
        if(hi < l || r < lo) return;
        // complete overlap
        if(lo >= l && hi <= r)
        {
            seg[indx] += (hi - lo + 1) * val;
            if(lo != hi)
            {
                lazy[2 * indx + 1] += val;
                lazy[2 * indx + 2] += val;
            }
            return;
        }
        // no overlap
        int mid = (lo + hi) >> 1;
        update(2 * indx + 1, lo, mid, l, r, val);
        update(2 * indx + 2, mid + 1, hi, l, r, val);
        seg[indx] = seg[2 * indx + 1] + seg[2 * indx + 2];
    }
    int query(int indx, int lo, int hi, int l, int r)
    {
        // update if any updates are remaining as the nodes are stay fresh and updated
        if(lazy[indx] != 0)
        {
            seg[indx] += (hi - lo + 1) * lazy[indx];
            // propagate the lazy update downwards for the remaining nodes to get updated
            if(lo != hi)
            {
                lazy[2 * indx + 1] = lazy[indx];
                lazy[2 * indx + 2] = lazy[indx];
            }
            lazy[indx] = 0;
        }
        // no overlap
        if(hi < l || lo > r) return 0;
        // complete overlap
        if(lo >= l && hi <= r) return seg[indx];
        // partial
        int mid = (lo + hi) >> 1;
        int left = query(2 * indx + 1, lo, mid, l, r);
        int right = query(2 * indx + 2, mid + 1, hi, l, r);
        return left + right;
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    ST st(n + 1);
    st.build(0, 0, n - 1, arr);
    int q;
    cin >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(0, 0, n - 1, l, r) << '\n';
        }
        else{
            int l, r, val;
            cin >> l >> r >> val;
            st.update(0, 0, n - 1, l, r, val);
        }
    }
}
/*
Input:
5
1 2 3 4 5
3
1 0 4
2 1 3 2
1 0 4
typt 1 -> sum from l to r
type 2 -> add val from l to r
Output:
15
21
*/