#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 1. Initialization (Queue is a container adapter)
    queue<int> q;

    // 2. Modifiers (Only FIFO Operations)
    q.push(5);   // Add to back: {5}
    q.push(2);   // {5,2}
    q.push(8);   // {5,2,8}
    q.pop();     // Remove front: {2,8}
    q.emplace(1); // Efficient push: {2,8,1}

    // 3. Element Access (No Random Access)
    cout << "Front: " << q.front() << endl; // 2
    cout << "Back: " << q.back() << endl;   // 1

    // 4. Capacity
    cout << "Size: " << q.size() << endl;   // 3
    cout << "Empty? " << q.empty() << endl; // 0 (false)

    // 5. Iteration (No direct iterators, manual pop)
    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop(); // Destructive iteration
    }

    return 0;
}