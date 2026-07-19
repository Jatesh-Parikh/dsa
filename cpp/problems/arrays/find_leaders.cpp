#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
    public: 
        // Time Complexity - O(n * logn)
        // Space Complexity - O(1)
        vector<int> find_leaders(vector<int>& arr) {
            int maximum = INT_MIN;
            int n = arr.size();
            
            vector<int> ans;

            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] > maximum) {
                    ans.push_back(arr[i]);
                    maximum = arr[i];
                }
            }

            sort(ans.begin(), ans.end());

            return ans;
        }
};