#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us = {5, 2, 8, 1, 3};

    // Insertion
    us.insert(4);
    us.emplace(6);

    // Deletion
    us.erase(2);
    auto it = us.find(3);
    if (it != us.end()) us.erase(it);

    // Lookup
    if (us.count(5)) cout << "5 exists\n";

    // Bucket interface (for hash table)
    cout << "Bucket count: " << us.bucket_count() << endl;
    cout << "Load factor: " << us.load_factor() << endl;

    // Iteration
    cout << "Unordered Set: ";
    for (int x : us) cout << x << " ";

    return 0;
}