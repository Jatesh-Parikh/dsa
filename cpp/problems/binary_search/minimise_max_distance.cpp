#include <vector>
#include <queue>

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

        // Time Complexity - O((n + k)logn)
        // Space Complexity - O(n)
        long double minimise_max_distance_better(vector<int>& arr, int k) {
            int n = arr.size();
            vector<int> how_many(n - 1, 0);
            priority_queue<pair<long double, int>> pq;

            for (int i = 0; i < n - 1; i++) {
                pq.push({ arr[i + 1] - arr[i], i });
            }

            for (int gas_station = 1; gas_station <= k; gas_station++) {
                auto top = pq.top(); 
                pq.pop();

                int max_section_index = top.second;
                how_many[max_section_index]++;
                long double diff = arr[max_section_index + 1] - arr[max_section_index];
                long double new_section_length = diff / (long double)(how_many[max_section_index] + 1);
                pq.push({ new_section_length, max_section_index });
            }

            return pq.top().first;
        }

        // Time Complexity - O()
        // Space Complexity - O()
        long double minimise_max_distance_optimal(vector<int>& arr, int k) {}
};