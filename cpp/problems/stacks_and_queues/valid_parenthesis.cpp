#include <string>
#include <stack>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        bool valid_parenthesis(const string& s) {
            stack<char> st;

            for (char ch: s) {
                if (
                    ch == '(' ||
                    ch == '[' ||
                    ch == '{'
                ) {
                    st.push(ch);
                } else {
                    if (st.empty()) return false;
                    else {
                        char c = st.top();
                        st.pop();

                        if (
                            c == '(' && ch != ')' ||
                            c == '[' && ch != ']' ||
                            c == '{' && ch != '}'
                        ) return false;
                    }
                }
            }

            return st.empty();
        }
};