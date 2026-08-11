#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        vector<int> next_smaller_element(vector<int>& arr) {
            int n = arr.size();
            stack<int> st;
            vector<int> nse(n);

            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && st.top() >= arr[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    nse[i] = -1;
                } else {
                    nse[i] = st.top();
                }

                st.push(arr[i]);
            }

            return nse;
        }
};