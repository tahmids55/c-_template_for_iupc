#include <iostream>
#include <vector>
#include <algorithm> // for sort, lower_bound, upper_bound, etc.
using namespace std;

int main() {
    // 1. Initialization
    vector<int> v = {5, 2, 8, 1, 3, 5, 5, 7};

    // 2. Modifiers
    v.push_back(10);          // Add at end
    v.pop_back();             // Remove last
    v.insert(v.begin() + 2, 6); // Insert at position
    v.erase(v.begin() + 1);   // Remove at position
    v.emplace_back(4);        // Efficient push_back
    v.emplace(v.begin(), 0);  // Efficient insert

    // 3. Element Access
    cout << "v[2]: " << v[2] << endl;       // Unchecked access
    cout << "v.at(3): " << v.at(3) << endl; // Checked access
    cout << "Front: " << v.front() << endl;  // First element
    cout << "Back: " << v.back() << endl;    // Last element
    int* ptr = v.data();                    // Raw pointer access

    // 4. Capacity
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Empty? " << v.empty() << endl;
    v.reserve(20);          // Pre-allocate memory
    v.shrink_to_fit();      // Reduce capacity to fit size

    // 5. Algorithms
    sort(v.begin(), v.end()); // Sort the vector
    reverse(v.begin(), v.end()); // Reverse
    auto lb = lower_bound(v.begin(), v.end(), 5); // First element >= 5
    auto ub = upper_bound(v.begin(), v.end(), 5); // First element > 5
    cout << "Lower bound of 5 at: " << (lb - v.begin()) << endl;
    cout << "Upper bound of 5 at: " << (ub - v.begin()) << endl;

    // 6. Iterators
    cout << "Vector: ";
    for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " ";

    // 7. Find and Count
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) cout << "\nFound 3 at: " << (it - v.begin());
    cout << "\nCount of 5: " << count(v.begin(), v.end(), 5);

    return 0;
}