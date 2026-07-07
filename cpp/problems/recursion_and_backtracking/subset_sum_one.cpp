// Time Complexity - O (n * 2 ^ n)
// Space Complexity - O (2 ^ n)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
    void func(int index, int sum, int N, vector<int>& arr, vector<int>& subset_sum) {
        if (index == N) {
            subset_sum.push_back(sum);
            return;
        }

        func(index + 1, sum + arr[index], N, arr, subset_sum);

        func(index + 1, sum, N, arr, subset_sum);
    }

    public:
    vector<int> subset_sum_one(vector<int> arr, int N) {
        vector<int> subset_sum;

        func(0, 0, N, arr, subset_sum);

        sort(subset_sum.begin(), subset_sum.end());

        return subset_sum;
    }
};