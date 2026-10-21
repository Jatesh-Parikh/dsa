#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
       // Time Complexity - O(n) 
       // Space Complexity - O(n) 
       vector<int> previous_smaller_element(vector<int>& arr) {
           int n = arr.size();
           vector<int> pge(n);
           stack<int> st;
           
           for (int i = 0; i <= n - 1; i++) {
                while (!st.empty() && st.top() <= arr[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    pge[i] = -1;
                } else {
                    pge[i] = st.top();
                }

                st.push(arr[i]);
           }

           return pge;
       }
};