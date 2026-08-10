#include <vector>
#include <stack>

using namespace std;

class Solution {
    private:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        long long subarray_sum_minimum(vector<int>& arr) {
            long long res = 0;

            stack<pair<int, int>> st;

            for (int i = 0; i < arr.size(); i++) {
                int n = arr[i];

                while (!st.empty() && n < st.top().second) {
                    auto [j, m] = st.top();
                    st.pop();

                    long long left = st.empty() ? j + 1 : j - st.top().first; 
                    long long right = i - j;

                    res += m * left * right;
                }

                st.push({ i, n });
            }

            while (!st.empty()) {
                auto [j, m] = st.top();
                st.pop();

                long long left = st.empty() ? j + 1 : j - st.top().first;
                long long right = arr.size() - j;

                res += m * left * right;
            }

            return res;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        long long subarray_sum_maximum(vector<int>& arr) {
            long long res = 0;

            stack<pair<int, int>> st;

            for (int i = 0; i < arr.size(); i++) {
                int n = arr[i];

                while (!st.empty() && n > st.top().second) {
                    auto [j, m] = st.top();
                    st.pop();

                    long long left = st.empty() ? j + 1 : j - st.top().first; 
                    long long right = i - j;

                    res += m * left * right;
                }

                st.push({ i, n });
            }

            while (!st.empty()) {
                auto [j, m] = st.top();
                st.pop();

                long long left = st.empty() ? j + 1 : j - st.top().first;
                long long right = arr.size() - j;

                res += m * left * right;
            }

            return res;
        }
    
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        long long subarray_sum_ranges(vector<int>& arr) {
            return subarray_sum_maximum(arr) - subarray_sum_minimum(arr);
        }
};