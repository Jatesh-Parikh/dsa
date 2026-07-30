#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
       // Time Complexity - O(n) 
       // Space Complexity - O(n) 
       vector<int> previous_smaller_element(vector<int>& arr) {
           int n = arr.size();
           vector<int> pse(n);
           stack<int> st;
           
            for (int i = 0; i < n; i++) {
                while (!st.empty() && st.top() >= arr[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    pse[i] = -1;
                } else {
                    pse[i] = st.top();
                }

                st.push(arr[i]);
            }

           return pse;
       }
};