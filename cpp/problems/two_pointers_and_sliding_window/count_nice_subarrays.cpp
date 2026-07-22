#include <vector>

using namespace std;

class Solutions {
    private:
        // Time Complexity - O(n)
        // Space Complexity - O(1)
        int func(vector<int>& arr, int k) {
            if (k == 0) return 0;

            int left = 0, right = 0, sum = 0, count = 0;
            int n = arr.size();

            while (right < n) {
                sum += arr[right] % 2;

                while (sum > k) {
                    sum -= arr[left] % 2;
                    left++;
                }

                count += right - left + 1;
                right++;
            }

            return count;
        }

    public:
        int count_nice_subarrays(vector<int>& arr, int k) {
            return func(arr, k) - func(arr, k - 1);
        }
};