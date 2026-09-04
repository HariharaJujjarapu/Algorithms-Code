#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
using namespace std;

int maxSubarraySum(vector<int> &arr, int k){
    int n = arr.size(), maxSum = INT_MIN;;
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i-1] + arr[i];

    deque<int> dq;
    for(int i = 0; i < n; i++){
        while(dq.front() < i - k)
            dq.pop_front();
        while(!dq.empty() && prefixSum[dq.back()] >= prefixSum[i])
            dq.pop_back();
        dq.push_back(i);
        maxSum = max(maxSum, prefixSum[dq.back()] - prefixSum[dq.front()]);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {-10, 20, -1, 2, 3};
    int k = 3;
    cout << "Max Sub Array Sum : " << maxSubarraySum(arr, k);
}