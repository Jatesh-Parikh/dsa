#include <vector>

using namespace std;

class Solution {
    public:
        // Time Complexity - O(k * n + n)
        // Space Complexity - O(n)
        long double minimise_max_distance(vector<int>& arr, int k) {
            int n = arr.size();
            vector<int> how_many(n - 1, 0);

            for (int gas_stations = 1; gas_stations <= k; gas_stations++) {
                long double max_section = -1;
                int max_index = -1;

                for (int i = 0; i < n - 1; i++) {
                    long double diff = arr[i + 1] - arr[i];
                    long double section_length = diff / (long double)(how_many[i] + 1);

                    if (section_length > max_section) {
                        max_section = section_length;
                        max_index = i;
                    }
                }
                how_many[max_index]++;
            }

            long double max_ans = -1;

            for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                long double section_length = diff / (long double)(how_many[i] + 1);
                max_ans = max(max_ans, section_length);
            }

            return max_ans;
        }

};