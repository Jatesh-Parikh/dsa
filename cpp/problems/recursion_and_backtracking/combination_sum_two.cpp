// Each element can be used at most once and duplicate combinations are not allowed

// Time Complexity: O(2 ^ n * k)
// Space Complexity: O(n) recursion stack
// where n = number of candidates, k = average length of a valid combination

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
    void find_combinations(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i-1]) continue;
            if (arr[i] > target) break;

            ds.push_back(arr[i]);
            find_combinations(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

    public:
    vector<vector<int>> combination_sum_two(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        find_combinations(0, target, candidates, ans, ds);
        return ans;
    }
};