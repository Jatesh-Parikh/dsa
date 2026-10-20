#include <vector>
#include <stack>

using namespace std;

class Solution {
    private:
        // Time Complexity - O(n) 
        // Space Complexity - O(n) 
        vector<int> previous_smaller_element(vector<int>& arr) {
            int n = arr.size();
            vector<int> pse(n);
            stack<int> st;

            for (int i = 0; i <= n - 1; i++) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    pse[i] = -1;
                } else {
                    pse[i] = st.top();
                }

                st.push(i);
            }

            return pse;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        vector<int> next_smaller_element(vector<int>& arr) {
            int n = arr.size();
            vector<int> nse(n);
            stack<int> st;

            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    nse[i] = n;
                } else {
                    nse[i] = st.top();
                }

                st.push(i);
            }

            return nse;
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int largest_rectangle_naive(vector<int>& arr) {
            int n = arr.size();
            vector<int> nse;
            vector<int> pse;
            int maximum = 0;

            nse = next_smaller_element(arr);
            pse = previous_smaller_element(arr);

            for (int i = 0; i <= n - 1; i++) {
                maximum = max(maximum, arr[i] * (nse[i] - pse[i] - 1));
            }

            return maximum;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(n)
        int largest_rectangle_optimized(vector<int>& arr) {
            int n = arr.size();
            int max_area = 0;
            stack<int> st;
            int nse, pse, element;

            for (int i = 0; i <= n - 1; i++) {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    element = arr[st.top()]; st.pop();
                    nse = i;
                    pse = st.empty() ? -1 : st.top();

                    max_area = max(max_area, element * (nse - pse - 1));
                }

                st.push(i);
            }

            while (!st.empty()) {
                nse = n;
                element = arr[st.top()]; st.pop();
                pse = st.empty() ? -1 : st.top();

                max_area = max(max_area, element * (nse - pse - 1));
            }

            return max_area;
        }
};