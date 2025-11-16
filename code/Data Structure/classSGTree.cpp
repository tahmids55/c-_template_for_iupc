class SGTree{
    vector<int> seg;
    public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
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
        seg[indx] = min(seg[2 * indx + 1], seg[2 * indx + 2]);
    }

    int query(int indx, int lo, int hi, int l, int r)
    {
        // no overlap
        if(r < lo || hi < l) return INT_MAX;
        // complete overlap
        if(lo >= l && hi <= r) return seg[indx];
        // partial overlap
        int mid = (lo + hi) >> 1;
        int left = query(2 * indx + 1, lo, mid, l, r);
        int right = query(2 * indx + 2, mid + 1, hi, l, r);
        return min(left, right);
    }

    void update(int indx, int lo, int hi, int i, int val)
    {
        if(lo == hi)
        {
            seg[indx] = val;
            return;
        }
        int mid = (lo + hi) >> 1;
        if(i <= mid) update(2 * indx + 1, lo, mid, i, val);
        else update(2 * indx + 2, mid + 1, hi, i, val);
        seg[indx] = min(seg[2 * indx + 1], seg[2 * indx + 2]);
    }
};

int main()
{
    int n1, i;
    cin >> n1;
    int arr1[n1];
    for(i = 0; i < n1; i++) cin >> arr1[i];
    SGTree seg1(n1);
    seg1.build(0, 0, n1 - 1, arr1);

    int n2;
    cin >> n2;
    int arr2[n2];
    for(i = 0; i < n2; i++) cin >> arr2[i];
    SGTree seg2(n2);
    seg2.build(0, 0, n2 - 1, arr2);

    int q;
    cin >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int min1 = seg1.query(0, 0, n1 - 1, l1, r1);
            int min2 = seg2.query(0, 0, n2 - 1, l2, r2);
            cout << min(min1, min2) << endl;
        }
        else
        {
            int arrNO, i, val;
            cin >> arrNO >> i >> val;
            if(arrNO == 1) 
            {
                seg1.update(0, 0, n1 - 1, i, val);
                arr1[i] = val;
            }
            else
            {
                seg2.update(0, 0, n2 - 1, i, val);
                arr2[i] = val;
            }
        }
    }
}
/*
Input:
10
0 2 4 2 1 3 9 8 -1 5
9
-3 -1 0 10 1 6 1 2 8
3
1 4 9 4 8
2 1 8 10
1 4 9 4 8
Output:
-1
1
*/