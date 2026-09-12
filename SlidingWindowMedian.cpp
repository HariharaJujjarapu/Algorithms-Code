class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> low;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> high;
        vector<double> ans;
        vector<bool> Flag(nums.size());
        int l = 0, r = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // Insert
            if (low.empty() || nums[i] <= low.top().first) {
                low.push({nums[i], i});
                Flag[i] = true;
            } else {
                high.push({nums[i], i});
                Flag[i] = false;
            }

            /// rebalance(L,&l,&r,i);
            //	int out = i - k;
            if (i >= k) {
                if (Flag[i - k])
                    l++;
                else
                    r++;

                while (!low.empty() && low.top().second <= i - k) {

                    l--;
                    low.pop();
                }
                while (!high.empty() && high.top().second <= i - k) {
                    high.pop();
                    r--;
                }
            }

            while (high.size() - r > low.size() - l) {
                if (high.top().second <= i - k)
                    r--;
                else {
                    low.push(high.top());
                    Flag[high.top().second] = true;
                }

                high.pop();
            }
            while (low.size() - l > high.size() + 1 - r) {
                if (low.top().second <= i - k)
                    l--;
                else {
                    high.push(low.top());
                    Flag[low.top().second] = false;
                }
                low.pop();
            }

            while (l && low.top().second <= i - k) {
                l--;
                low.pop();
            }
            while (r && high.top().second <= i - k) {
                r--;
                high.pop();
            }
            if (i >= k - 1) {
                if (k & 1)
                    ans.push_back(low.top().first);
                else {
                    double t = low.top().first / 2.0;
                    t += high.top().first / 2.0;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};