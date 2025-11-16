#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct BIT {
    vector<int> tree;
    int n;
    BIT(int size) : n(size), tree(size + 1, 0) {}
    
    // Update the BIT with a given value at index idx
    void update(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    
    // Query the prefix sum up to idx
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int countInversions(vector<int>& arr) {
    int n = arr.size();
    int maxElement = *max_element(arr.begin(), arr.end());  // Maximum element in array
    BIT bit(maxElement);  // BIT with size equal to maximum element value

    int inversions = 0;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Count how many elements less than arr[i] have been processed
        inversions += bit.query(arr[i] - 1);
        
        // Update the BIT to include arr[i]
        bit.update(arr[i], 1);
    }

    return inversions;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Number of inversions: " << countInversions(arr) << endl; // Output: 6
    return 0;
}