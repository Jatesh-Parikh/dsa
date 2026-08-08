#include <stack>
#include <climits>

using namespace std;

class MinStack {
    public:
        stack<pair<int, int>> st;

        void push(int x) {
            if (st.empty()) {
                st.push({ x, x });
            } else {
                st.push({ x, min(x, st.top().second) });
            }
        }

        // Time Complexity - O(1)
        // Space Complexity - O(2N), as we're storing 2 elements in the stack
        int get_min() {
            return st.top().second;
        }

        int top() {
            return st.top().first;
        }
};

class MinStackOptimized {
    public:
        stack<int> st;
        int minimum = INT_MIN;

        void push(int val) {
            if (st.empty()) {
                st.push(val);
                minimum = val;
            } else {
                if (val > minimum) {
                    st.push(val);
                } else {
                    st.push(2 * val - minimum);
                    minimum = val;
                }
            }
        }

        void pop() {
            if (st.empty()) return;
            else {
                int x = st.top();
                st.pop();

                if (x < minimum) {
                    minimum = 2 * minimum - x;
                }
            }
        }

        int top() {
            if (st.empty()) return -1;
            else {
                int x = st.top();
                
                if (x < minimum) return minimum;
                else return x;
            }
        }

        // Time Complexity - O(1)
        // Space Complexity - O(N)
        int get_min() {
            return st.empty() ? -1 : minimum;
        }
};