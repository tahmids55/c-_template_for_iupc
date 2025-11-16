#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int calculateMex(unordered_set<int>& Set) {
    int mex = 0;
    while (Set.count(mex)) mex++;
    return mex;
}

int calculateGrundy(int n, vector<int>& moves) {
    if (n == 0) return 0;
    unordered_set<int> Set;
    for (int move : moves) {
        if (n >= move) Set.insert(calculateGrundy(n - move, moves));
    }
    return calculateMex(Set);
}

int main() {
    vector<int> moves = {1, 3, 4};
    cout << "Grundy number for n=5: " << calculateGrundy(5, moves) << endl; // Output: 2
    return 0;
}