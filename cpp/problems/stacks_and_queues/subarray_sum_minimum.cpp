#include <vector>
#include <stack>

using namespace std;

class Solution {
    public: 
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int subarray_sum_minimum(vector<int>& arr) {
            const long long MOD = 1e9 + 7;
            long long res = 0;

            stack<pair<int, int>> st;

            for (int i = 0; i < arr.size(); i++) {
                int n = arr[i];

                while (!st.empty() && n < st.top().second) {
                    auto [j, m] = st.top();
                    st.pop();

                    long long left = st.empty() ? j + 1 : j - st.top().first; 
                    long long right = i - j;

                    res = (res + m * left * right) % MOD;
                }

                st.push({ i, n });
            }

            while (!st.empty()) {
                auto [j, m] = st.top();
                st.pop();

                long long left = st.empty() ? j + 1 : j - st.top().first;
                long long right = arr.size() - j;

                res = (res + m * left * right) % MOD;
            }

            return res;
        }
};