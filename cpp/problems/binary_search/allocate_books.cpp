#include <vector>
#include <climits>

using namespace std;

class Solution {
    private:
        int count_students(vector<int>& arr, int pages_per_student) {
            int students = 1, pages = 0;

            for (int i = 0; i < arr.size(); i++) {
                if (pages + arr[i] <= pages_per_student) {
                    pages += arr[i];
                } else {
                    students++;
                    pages = arr[i];
                }
            }

            return students;
        }
    
    public:
        // Time Complexity - O(n * log(sum - maximum  + 1))
        // Space Complexity - O(1)
        int find_pages(vector<int>& arr, int n, int m) {
            if (m > n) return -1;

            int maximum = INT_MIN, sum = 0;
            for (int i = 0; i < n; i++) {
                maximum = max(maximum, arr[i]);
                sum += arr[i];
            }   
            int low = maximum, high = sum;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int students = count_students(arr, mid);

                if (students > m) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return low;
        }
};