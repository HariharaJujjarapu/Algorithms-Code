#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int> &arr){
    int maxSum = INT_MIN, curSum = 0;
    for(int i = 0; i < arr.size();  i++){
        curSum += arr[i];
        if(curSum < 0)
            curSum = 0;
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {1, 5, -6, 3, 12, -9, 6, -5, 10};
    cout << "Max Sub Array Sum : " << maxSubarraySum(arr);
}