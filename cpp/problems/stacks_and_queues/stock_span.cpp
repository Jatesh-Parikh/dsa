// Find maximum consecutive days for which the stock price was less than or equal to current day.
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        vector<int> calculate_span(vector<int>& prices) {
            int n = prices.size();
            vector<int> span(n);
            stack<int> st;

            for (int i = 0; i <= n - 1; i++) {
                while (!st.empty() && prices[st.top()] <= prices[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    span[i] = i + 1;
                } else {
                    span[i] = i - st.top();
                }
            
                st.push(i);
            }

            return span;
        }
};