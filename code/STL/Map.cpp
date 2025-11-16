#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m = {{"Alice", 25}, {"Bob", 30}};

    // Insertion
    m.insert({"Charlie", 35});
    m.emplace("Dave", 40);
    m["Eve"] = 28; // Direct assignment

    // Deletion
    m.erase("Bob"); // Remove by key
    auto it = m.find("Alice");
    if (it != m.end()) m.erase(it); // Remove by iterator

    // Lookup
    if (m.count("Eve")) cout << "Eve exists\n";
    auto lb = m.lower_bound("C"); // First key >= "C"
    auto ub = m.upper_bound("D"); // First key > "D"

    // Iteration
    cout << "Map:\n";
    for (auto &[key, val] : m) cout << key << ": " << val << endl;

    // Advanced
    auto [first, last] = m.equal_range("Charlie"); // [lower, upper) bounds
    cout << "Equal range for Charlie: " << first->first << " " << last->first;

    return 0;
}