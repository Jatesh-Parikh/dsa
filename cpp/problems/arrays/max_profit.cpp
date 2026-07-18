#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int max_profit(vector<int>& prices) {
            int minimum = prices[0];
            int max_profit = 0;
            int n = prices.size();

            for (int i = 1; i < n; i++) {
                max_profit = max(max_profit, prices[i] - minimum);
                minimum = min(minimum, prices[i]);
            }

            return max_profit;
        }
};