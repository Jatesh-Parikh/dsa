#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(n)
        // Space Complexity - O(n) 
        vector<int> majority_element_two(vector<int>& arr) {
            vector<int> res;
            unordered_map<int, int> mpp;
            int minimum = arr.size() / 3 + 1;

            for (int i = 0; i < arr.size(); i++) {
                mpp[arr[i]] += 1;

                if(mpp[arr[i]] == minimum) res.push_back(arr[i]);
                if (res.size() == 2) break;
            }

            sort(res.begin(), res.end());
            return res;
        }

        // Time Complexity - O(n)
        // Space Complexity - O(1)
        vector<int> majority_element_two_optimal(vector<int>& arr) {
            int n = arr.size();
            int minimum = n / 3 + 1;
            int count1 = 0, el1 = INT_MIN, count2 = 0, el2 = INT_MIN;
            
            for (int i = 0; i < n; i++) {
                if (count1 == 0 && arr[i] != el2) {
                    count1 = 1;
                    el1 = arr[i];
                } else if (count2 == 0 && arr[i] != el1) {
                    count2 = 1;
                    el2 = arr[i];
                } else if (arr[i] == el1) {
                    count1++;
                } else if (arr[i] == el2) {
                    count2++;
                } else {
                    count1--;
                    count2--;
                }
            }

            vector<int> res;
            count1 = 0, count2 = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == el1) count1++;
                if (arr[i] == el2) count2++;
            }

            if(count1 >= minimum) res.push_back(el1);
            if(count2 >= minimum) res.push_back(el2);

            sort(res.begin(), res.end());
            return res;
        }
};