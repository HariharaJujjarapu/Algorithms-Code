// The stock must be sold at most 𝑘 days after it is bought.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int k) {
        int maxProfit = 0;
        deque<int> dq;

        for(int i = 0; i < prices.size(); i++){
            while(dq.front() < i-k)
                dq.pop_front();

            if(!dq.empty())
                maxProfit = max(maxProfit, prices[i] - prices[dq.front()]);

            while(!dq.empty() && prices[dq.back()] >= prices[i])
                dq.pop_back();

            dq.push_back(i);            
        }
        return maxProfit;
    }
};