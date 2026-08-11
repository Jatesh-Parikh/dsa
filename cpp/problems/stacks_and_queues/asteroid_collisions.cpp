#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        vector<int> asteroid_collisions(vector<int>& arr) {
            stack<int> st;
            vector<int> ans;

            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] > 0) st.push(arr[i]);
                else {
                    while (!st.empty() && st.top() > 0 && st.top() < abs(arr[i])) {
                        st.pop();
                    }
                }

                if (!st.empty() && st.top() == abs(arr[i])) st.pop();
                else if (st.empty() || st.top() < 0) st.push(arr[i]);
            }

            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }

            reverse(ans.begin(), ans.end());

            return ans;
        }
};