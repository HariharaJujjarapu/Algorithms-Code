#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int> &arr, int k){
    int S = 0, S1 = 0, maxSum = INT_MIN;
    
    for(int i = 0; i < k; i++)
        S += arr[i];
    
    maxSum = max(maxSum, S);
    for(int i = k; i < arr.size(); i++){
        S += arr[i];
        
        S1 += arr[i-k];
        if(S1 < 0){
            S = S - S1;
            S1 = 0;
        }
        
        maxSum = max(maxSum, S);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {10, -100, 20, 30};
    int k = 2;
    cout << "Max Sub Array Sum : " << maxSubarraySum(arr, k);
}