#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, maxProfit = 0;
        for(int j = 1; j < prices.size(); j++){
            maxProfit = max(maxProfit, prices[j] - prices[i]);
            if(prices[j] < prices[i])
                i = j;
        }
        return maxProfit;
    }
};