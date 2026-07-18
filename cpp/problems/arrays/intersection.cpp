#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n * m)
        // Space Complexity - O(m) 
        vector<int> intersection(vector<int>& a, int n, vector<int>& b, int m) {
            vector<int> ans;
            vector<int> vis(m, 0);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i] == b[j] && vis[j] == 0) {
                        ans.push_back(a[i]);
                        vis[j] = 1;
                        break;
                    }
                    if (b[j] > a[i]) break;
                }
            }

            return ans;
        }

        // Time Complexity - O(n + m)
        // Space Complexity - O(1) 
        vector<int> intersection_optimal(vector<int>& a, int n, vector<int>& b, int m) {
            vector<int> ans;
            
            int i = 0, j = 0;
            
            while (i < n && j < m) {
                if (a[i] < b[j]) {
                    i++;
                } else if (b[j] < a[i]) {
                    j++;
                } else {
                    ans.push_back(a[i]);
                    i++;
                    j++;
                }
            }

            return ans;
        }
};