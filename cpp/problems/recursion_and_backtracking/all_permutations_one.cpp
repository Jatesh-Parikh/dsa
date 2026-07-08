// Time Complexity - O (n! * n)
// Space Complexity - O(n)

#include <vector>

using namespace std;

class Solution {
    private:
    void recur_permute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                freq[i] = 1;
                ds.push_back(nums[i]);
                recur_permute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        recur_permute(ds, nums, ans, freq);
        return ans;
    }
};