#include <string>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        string remove_k_digits(string num, int k) {
            string str;

            for (char digit : num) {
                while (!str.empty() && k > 0 && str.back() > digit) {
                    str.pop_back();
                    k--;
                }

                str.push_back(digit);
            }

            while (k > 0 && !str.empty()) {
                str.pop_back();
                k--;
            }

            int i = 0;
            while (i < str.size() && str[i] == '0') {
                i++;
            }

            str = str.substr(i);

            return str.empty() ? "0" : str;
        }
};
