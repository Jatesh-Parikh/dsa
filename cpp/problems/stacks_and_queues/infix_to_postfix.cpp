#include <stack>
#include <string>

using namespace std;

class Solution {
    private:
        int priority(char op) {
            if (op == '^') {
                return 3;
            } else if (op == '/' || op == '*') {
                return 2;
            } else if (op == '+' || op == '-') {
                return 1;
            } else {
                return -1;
            }
        }
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        string infix_to_postfix(string s) {
            string ans = "";
            int i = 0;
            int n = s.size();
            stack<char> st;

            while (i < n) {
                if (
                    (s[i] >= 'A' && s[i] <= 'Z') ||
                    (s[i] >= 'a' && s[i] <= 'z') ||
                    (s[i] >= '0' && s[i] <= '9')
                ) {
                    ans += s[i];
                } else if (s[i] == '(') {
                    st.push(s[i]);
                } else if (s[i] == ')') {
                    while (!st.empty() && st.top() != '(') {
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                } else {
                    while (!st.empty() && (
                        priority(s[i]) < priority(st.top()) ||
                        (
                            priority(s[i]) == priority(st.top()) && s[i] != '^'
                        )
                    )) {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                i++;
            } 

            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }

            return ans;
        }
};