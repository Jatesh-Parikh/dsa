#include <tuple>
#include <vector>

using namespace std;

class Solution {
    private:
        int lower_bound(vector<int>& arr, int k) {
            int n = arr.size();
            int low = 0, high = n - 1;
            int ans = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] >= k) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return ans;
        }

        int upper_bound(vector<int>& arr, int k) {
            int n = arr.size();
            int low = 0, high = n - 1;
            int ans = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] > k) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            return ans;
        }

    public:
        // Time Complexity - (logn)
        // Space Complexity - (1)
        tuple<int, int> find_first_last_ocurrences(vector<int>& arr, int target) {
            int lb = lower_bound(arr, target);

            if (lb == arr.size() || arr[lb] != target) {
                return {-1 , -1};
            }

            return { lb, upper_bound(arr, target) - 1 };
        }
};