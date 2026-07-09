// Time Complexity - O(n * logn)
// Space Complexity - O(n)

#include <vector>

using namespace std;

class Solution {
    private:
        int merge(vector<int>& arr, int low, int mid, int high) {
            int count = 0;
            vector<int> temp;
            int left = low;
            int right = mid + 1;

            while (left <= mid && right <= high) {
                if (arr[left] <= arr[right]) {
                    temp.push_back(arr[left]);
                    left++;
                } else {
                    count += mid - left + 1;
                    temp.push_back(arr[right]);
                    right++;
                }
            }

            while (left <=  mid) {
                temp.push_back(arr[left]);
                left++;
            }

            while (right <= high) {
                temp.push_back(arr[right]);
                right++;
            }

            for (int i = 0; i < temp.size(); i++) {
                arr[low + i] = temp[i];
            }

            return count;
        }

        int merge_sort(vector<int>& arr, int low, int high) {
            int count = 0;

            if (low >= high) return count;
            
            int mid = low + (high - low) /2;
            
            count += merge_sort(arr, low, mid);
            count += merge_sort(arr, mid + 1, high);
            count += merge(arr, low, mid, high);
            
            return count;
        }
    
    public:
        int number_of_inversions(vector<int>& arr, int n) {
            int count = 0;
            count += merge_sort(arr, 0, n - 1);
            return count;
        }
};