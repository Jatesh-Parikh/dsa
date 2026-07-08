// Time Complexity - O(n! * n)
// Space Complexity - O(n)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
    void recur_permute(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            recur_permute(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }

    public: 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recur_permute(0, nums, ans);
        return ans;
    }
};