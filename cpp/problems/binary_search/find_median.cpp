#include <vector>
#include <climits>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n + m)
        // Space Complexity - O(n + m)
        double find_median_brute(vector<int>& a, vector<int>& b) {
            vector<int> ans;
            int n = a.size(); 
            int m = b.size();
            int i = 0, j = 0;
            
            while (i < n && j < m) {
                if (a[i] < b[j]) {
                    ans.push_back(a[i++]);
                } else {
                    ans.push_back(b[j++]);
                }
            }

            while (i < n) ans.push_back(a[i++]);
            while (j < m) ans.push_back(b[j++]);

            int p = n + m;
            if (p % 2 == 1) {
                return ans[p / 2];
            }

            return (double)(((double)ans[p/2] + (double)ans[p/2 - 1]) / 2.0); 
        }

        // Time Complexity - O(n + m)
        // Space Complexity - O(1)
        double find_median_better(vector<int>& a, vector<int>& b) {
            int n = a.size();
            int m = b.size();
            int i = 0, j = 0;
            int p = n + m;
            int index2 = p / 2;
            int index1 = index2 - 1;
            int count= 0;
            int el1 = -1, el2 = -1;

            while (i < n && j < m) {
                if (a[i] < b[j]) {
                    if (count == index1) el1 = a[i];
                    if (count == index2) el2 = a[i];
                    count++;
                    i++;
                } else {
                    if (count == index1) el1 = b[j];
                    if (count == index2) el2 = b[j];
                    count++;
                    j++;
                }
            }

            while (i < n) {
                if (count == index1) el1 = a[i];
                if (count == index2) el2 = a[i];
                count++;
                i++;
            }

            while (j < m) {
                if (count == index1) el1 = b[j];
                if (count == index2) el2 = b[j];
                count++;
                j++;
            }

            if (p % 2 == 1) {
                return el2;
            }

            return (double)(((double)el1 + (double)el2) / 2.0);
        }

        // Time Complexity - O(log(min(n1, n2)))
        // Space Complexity - O(1)
        double find_median_optimal(vector<int>& a, vector<int>& b) {
            int n1 = a.size();
            int n2 = b.size();
            if (n1 > n2) return find_median_optimal(b, a);
            int low = 0, high = n1;
            int left = (n1 + n2 + 1) / 2;
            int n = n1 + n2;

            while (low <= high) {
                int mid1 = (low + high) / 2;
                int mid2 = left - mid1;
                int l1 = INT_MIN, l2 = INT_MIN; 
                int r1 = INT_MAX, r2 = INT_MAX;
                if (mid1 < n1) r1 = a[mid1];
                if (mid2 < n2) r2 = b[mid2];
                if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
                if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

                if (l1 <= r2 && l2 <= r1) {
                    if (n % 2 == 1) return max(l1, l2);
                    return (double) ((max(l1, l2) + min(r1, r2)) / 2.0);
                } else if (l1 > r2) {
                    high = mid1 - 1;
                } else {
                    low = mid1 + 1;
                }
            }

            return 0;
        }

};