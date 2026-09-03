// The stock must be sold at least k days after it is bought.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int k) {
        int i = 0, maxProfit = 0;
        for(int j = k-1; j < prices.size(); j++){
            maxProfit = max(maxProfit, prices[j] - prices[i]);
            if(prices[j-(k-1)] < prices[i])
                i = j-(k-1);
        }
        return maxProfit;
    }
};