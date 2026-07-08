// Time Complexity - O(n ^ 2 * 2 ^ n)
// Space Complexity - O(2 ^ n * n)
// Auxiliary Space - O(n)

#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        bool is_palindrome(const string& s, int start, int end) {
            while (start < end) {
                if (s[start++] != s[end--]) return false;
            }
            return true;
        }

        void func(int index, const string& s, vector<string>& path, vector<vector<string>>& res) {
            if (index == s.size()) {
                res.push_back(path);
                return;
            }

            for (int i = index; i < s.size(); i++) {
                if (is_palindrome(s, index, i)) {
                    path.push_back(s.substr(index, i - index + 1));
                    func(i + 1, s, path, res);
                    path.pop_back();
                }
            }
        }

    public:
        vector<vector<string>> palindrome_partitioning(string s) {
            vector<vector<string>> res;
            vector<string> path;
            
            func(0, s, path, res);
            
            return res;
        }
};