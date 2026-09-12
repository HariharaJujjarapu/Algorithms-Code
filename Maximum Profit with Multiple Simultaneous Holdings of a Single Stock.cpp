#include <bits/stdc++.h>
using namespace std;

long long maxProfit(const vector<int>& prices) {
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    long long profit = 0;
    for (int price : prices) {
        pq.push(price);
        if (!pq.empty() && price > pq.top()) {
            profit += price - pq.top();
            pq.pop();
            pq.push(price);
        }
    }
    return profit;
}

int main() {
    // Example usage
    vector<int> prices = {1, 2, 3, 4};
    cout << maxProfit(prices) << endl; // Output: 4
    return 0;
}