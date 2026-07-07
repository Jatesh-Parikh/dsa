// Time Complexity - O(2^n * n) 
// Space Complexity - O(2^n * n), Auxiliary space - O(n)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
    void find_subsets(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
        ans.push_back(ds);

        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1]) continue;

            ds.push_back(nums[i]);
            find_subsets(i + 1, nums, ans, ds);
            ds.pop_back();
        }
    }

    public:
    vector<vector<int>> subset_sum_two(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        find_subsets(0, nums, ans, ds);
        return ans;
    }
};