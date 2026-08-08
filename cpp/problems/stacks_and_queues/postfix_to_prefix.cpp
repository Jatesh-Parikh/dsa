#include <string>
#include <stack>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        string postfix_to_prefix(string s) {
            stack<string> st;

            for (int i = 0; i < s.size(); i++) {
                if (isalnum(s[i])) {
                    st.push(string(1, s[i]));
                } else {
                    string t1 = st.top(); 
                    st.pop();
                    
                    string t2 = st.top(); 
                    st.pop();

                    string x = string(1, s[i]) + t2 + t1;
                    st.push(x);
                }
            }

            return st.top();
        }
};