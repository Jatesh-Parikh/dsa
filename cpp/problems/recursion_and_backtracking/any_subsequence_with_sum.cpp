// Time Complexity - O(2 ^ n)
// Space Complexity - O(n)

#include <iostream>
#include <vector>

using namespace std;

bool any_subsequence_with_sum(int index, int arr[], vector<int>& ds, int calculated_sum, int sum, int n) {
    if (index == n) {
        if (calculated_sum == sum) {
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
            return true;
        } else {
            return false;
        }
    }

    ds.push_back(arr[index]);
    calculated_sum += arr[index];
    if (any_subsequence_with_sum(index + 1, arr, ds, calculated_sum, sum, n)) return true;

    ds.pop_back();
    calculated_sum -= arr[index];
    if (any_subsequence_with_sum(index + 1, arr, ds, calculated_sum, sum, n)) return true;

    return false;
}

int main() {
    int arr[] = {1, 2, 1, 3};
    int n = 4;
    int sum = 2;

    vector<int> ds;

    any_subsequence_with_sum(0, arr, ds, 0, sum, n);

    return 0;
}