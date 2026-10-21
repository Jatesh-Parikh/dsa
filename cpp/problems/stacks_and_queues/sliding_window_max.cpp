#include <vector>
#include <deque>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n)
        vector<int> max_sliding_window(vector<int>& nums, int k) {
            deque<int> dq;
            vector<int> result;

            for (int i = 0; i < nums.size(); i++) {
                while (!dq.empty() && dq.front() <= i - k) { // remove elements outside the current window
                    dq.pop_front();
                }

                while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                    dq.pop_back();
                }

                dq.push_back(i);

                if (i >= k - 1) {
                    result.push_back(nums[dq.front()]);
                }
            }

            return result;
        }
};