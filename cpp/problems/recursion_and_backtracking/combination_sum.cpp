// Time Complexity - O (2 ^ t * k), where t is related to the target and k is the average length of a combination
// Space Complexity - O (k * x), where each combination can have at most k elements and there are x valid combinations

#include <vector>

using namespace std;

class Solution {
    private:
    void find_combination(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if (index == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[index] <= target) { // Pick
            ds.push_back(arr[index]);
            find_combination(index, target - arr[index], arr, ans, ds);
            ds.pop_back();
        }

        find_combination(index + 1, target, arr, ans, ds); // Not Pick
    }

    public:
    vector<vector<int>> combination_sum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        find_combination(0, target, candidates, ans, ds);

        return ans;
    }
};