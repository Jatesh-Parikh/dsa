#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        // Time Complexity - O((a + b) * log(a + b)) where a and b are the sizes of the two input arrays
        // Space Complexity - O(a + b)
        vector<int> union_brute(vector<int>& a, vector<int>& b) {
            set<int> st;

            for (int i = 0; i < a.size(); i++) {
                st.insert(a[i]);
            }

            for (int i = 0; i < b.size(); i++) {
                st.insert(b[i]);
            }

            vector<int> temp;
            for (auto it: st) {
                temp.push_back(it);
            }

            return temp;
        }

        // Time Complexity - O(a + b), where a and b are the sizes of the two input vectors
        // Space Complexity - O(1)
        vector<int> union_optimal(vector<int>& a, vector<int>& b) {
            int a_size = a.size();
            int b_size = b.size();

            vector<int> union_arr;

            int i = 0, j = 0;

            while (i < a_size && j < b_size) {
                if (a[i] <= b[j]) {
                    if (union_arr.size() == 0 || union_arr.back() != a[i]) {
                        union_arr.push_back(a[i]);
                    }
                    i++;
                } else {
                    if (union_arr.size() == 0 || union_arr.back() != b[j]) {
                        union_arr.push_back(b[j]);
                    }
                    j++;
                }
            }

            while (i < a_size) {
                if (union_arr.size() == 0 || union_arr.back() != a[i]) {
                        union_arr.push_back(a[i]);
                }
                i++;
            }

            while (j < b_size) {
                if (union_arr.size() == 0 || union_arr.back() != b[j]) {
                        union_arr.push_back(b[j]);
                }
                j++;
            }

            return union_arr;
        }
};