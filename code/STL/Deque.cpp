#include <iostream>
#include <deque>
#include <algorithm> // for sort, lower_bound, etc.
using namespace std;

int main() {
    // 1. Initialization
    deque<int> dq = {5, 2, 8, 1, 3};

    // 2. Modifiers (Front/Back Operations)
    dq.push_back(10);     // Add at end: {5,2,8,1,3,10}
    dq.push_front(0);     // Add at front: {0,5,2,8,1,3,10}
    dq.pop_back();        // Remove last: {0,5,2,8,1,3}
    dq.pop_front();       // Remove first: {5,2,8,1,3}
    dq.insert(dq.begin() + 2, 7); // Insert at pos 2: {5,2,7,8,1,3}
    dq.erase(dq.begin() + 1);     // Remove pos 1: {5,7,8,1,3}
    dq.emplace_back(4);   // Efficient push_back: {5,7,8,1,3,4}
    dq.emplace_front(9);  // Efficient push_front: {9,5,7,8,1,3,4}

    // 3. Element Access
    cout << "dq[2]: " << dq[2] << endl;       // Unchecked (7)
    cout << "dq.at(3): " << dq.at(3) << endl; // Checked (8)
    cout << "Front: " << dq.front() << endl;  // 9
    cout << "Back: " << dq.back() << endl;    // 4

    // 4. Capacity
    cout << "Size: " << dq.size() << endl;
    cout << "Empty? " << dq.empty() << endl;
    dq.shrink_to_fit();  // Reduce memory usage

    // 5. Algorithms (Requires Random Access)
    sort(dq.begin(), dq.end()); // {1,3,4,5,7,8,9}
    auto lb = lower_bound(dq.begin(), dq.end(), 5); // First >= 5
    auto ub = upper_bound(dq.begin(), dq.end(), 5); // First > 5
    cout << "Lower bound of 5 at: " << (lb - dq.begin()) << endl;
    cout << "Upper bound of 5 at: " << (ub - dq.begin()) << endl;

    // 6. Iteration
    cout << "Deque: ";
    for (int x : dq) cout << x << " ";

    // 7. Find and Count
    auto it = find(dq.begin(), dq.end(), 7);
    if (it != dq.end()) cout << "\nFound 7 at: " << (it - dq.begin());

    return 0;
}