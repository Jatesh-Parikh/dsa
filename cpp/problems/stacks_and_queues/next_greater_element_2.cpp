// Circular array

#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        vector<int> next_greater_element_2(vector<int>& arr) {
            int n = arr.size();
            stack<int> st;
            vector<int> nge(n);

            for (int i = 2 * n - 1; i >= 0; i--) {
                int idx = i % n;

                while (!st.empty() && st.top() <= arr[idx]) {
                    st.pop();
                }

                if (i < n) {
                    if (st.empty()) {    
                        nge[i] = -1;
                    } else {
                        nge[i] = st.top();
                    }
                } 
                st.push(arr[idx]);
            }

            return nge;
        }
};