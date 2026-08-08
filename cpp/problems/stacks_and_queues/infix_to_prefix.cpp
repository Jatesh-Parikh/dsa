#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    private:
        int priority(char op) {
            if (op == '^') return 3; 
            else if (op == '/' || op == '*') return 2;  
            else if (op == '+' || op == '-') return 1; 
            else return -1;
        }

        string infix_to_postfix(string s) {
            string ans = "";
            stack<char> st;

            for (int i = 0; i < s.size(); i++) {
                char ch = s[i];

                if (isalnum(ch)) {
                    ans += ch;
                } else if (ch == '(') {
                    st.push(ch);
                } else if (ch == ')') {
                    while (!st.empty() && st.top() != '(') {
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                } else {
                    while (
                        !st.empty() && 
                        (
                            priority(ch) < priority(st.top()) ||
                            (priority(ch) == priority(st.top()) && ch != '^')
                        )
                    ) {
                        ans += st.top();
                        st.pop();
                    }
                    st.push(ch);
                }    
            }

            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }

            return ans;
        }

    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        string infix_to_prefix(string s) {
            reverse(s.begin(), s.end());

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') s[i] = ')';
                else if (s[i] == ')') s[i] = '(';
            }

            string ans = infix_to_postfix(s);

            reverse(ans.begin(), ans.end());

            return ans;
        }
};