#include <vector>
#include <stack>

using namespace std;

class Solution {
    private:
        int largest_rectangle(vector<int>& arr) {
            int n = arr.size();
            int maximum = 0;
            stack<int> st;
            int element, pse, nse;

            for (int i = 0; i <= n - 1; i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    element = arr[st.top()]; st.pop();
                    nse = i;
                    pse = st.empty() ? -1 : st.top();

                    maximum = max(maximum, element * (nse - pse - 1));
                }

                st.push(i);
            }

            while (!st.empty()) {
                nse = n;
                element = arr[st.top()]; st.pop();
                pse = st.empty() ? -1 : st.top();

                maximum = max(maximum, element * (nse - pse -1));
            }

            return maximum;
        }

    public:
        // Time Complexity - O(n * m)
        // Space Complexity - O(n * m)
        int maximal_rectangle(vector<vector<int>>& arr) {
            int n = arr.size(); // rows
            int m = arr[0].size(); // columns
            vector<vector<int>> p_sum(n, vector<int>(m));
            int sum = 0;
            int maximum = 0;

            for (int i = 0; i < m; i++) {
                sum = 0;
                for (int j = 0; j < n; j++) {
                    if (arr[j][i] == 0) {
                        sum = 0;
                    } else {
                        sum++;
                    }
                    p_sum[j][i] = sum;                      
                }
            }

            for (int i = 0; i < n; i++) {
                maximum = max(maximum, largest_rectangle(p_sum[i]));
            }

            return maximum;
        }
};