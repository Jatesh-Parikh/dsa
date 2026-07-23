#include <vector>

using namespace std;

class Solution {
    private:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int func(vector<int>& arr, int goal) {
            if (goal < 0) return 0;

            int left = 0, right = 0, sum = 0, count = 0;
            int n = arr.size();

            while (right < n) {
                sum += arr[right];

                while (sum > goal) {
                    sum -= arr[left];
                    left++;
                }

                count += right - left + 1;
                right++; 
            }

            return count;
        }

    public:
        int count_subarrays(vector<int>& arr, int goal) {
            return func(arr, goal) - func(arr, goal - 1);
        }
};