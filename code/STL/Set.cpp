#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {5, 2, 8, 1, 3};

    // Insertion
    s.insert(4);        // Insert element
    s.emplace(6);       // Efficient insert

    // Deletion
    s.erase(2);         // Remove element
    auto it = s.find(3);
    if (it != s.end()) s.erase(it); // Remove by iterator

    // Lookup
    if (s.count(5)) cout << "5 exists in set\n";
    auto lb = s.lower_bound(4); // First element >= 4
    auto ub = s.upper_bound(4); // First element > 4

    // Iteration
    cout << "Set: ";
    for (int x : s) cout << x << " ";

    // Advanced
    auto [first, last] = s.equal_range(5); // Returns [lower, upper) bounds
    cout << "\nEqual range for 5: " << *first << " " << *last;

    return 0;
}