#include <bits/stdc++.h>
using namespace std;

class MedianHeap {
private:
    priority_queue<int> maxHeap;                              // lower half (max-heap)
    priority_queue<int, vector<int>, greater<int>> minHeap;   // upper half (min-heap)

    // Restore invariant: maxHeap.size() = (total+1)/2, minHeap.size() = total/2
    void rebalance() {
        int total = maxHeap.size() + minHeap.size();
        int targetMax = (total + 1) / 2;  // ceil(total/2)

        if (maxHeap.size() > targetMax) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < targetMax) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

public:
    // Insert an element
    void add(int x) {
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
        rebalance();
    }

    // Delete and return the median (top of maxHeap)
    int deleteMedian() {
        if (maxHeap.empty()) {
            throw runtime_error("No elements");
        }
        int median = maxHeap.top();
        maxHeap.pop();
        rebalance();
        return median;
    }

    // Get current median without removing
    int getMedian() const {
        return maxHeap.top();
    }
};

// Example Usage
int main() {
    MedianHeap mh;
    vector<int> nums = {1, 2, 3, 4, 5};

    for (int x : nums) {
        mh.add(x);
        cout << "Added " << x << ", median = " << mh.getMedian() << "\n";
    }

    cout << "Deleted median: " << mh.deleteMedian() << "\n";
    cout << "New median: " << mh.getMedian() << "\n";

    return 0;
}