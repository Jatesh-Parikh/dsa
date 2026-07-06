// Time Complexity - O (2 ^ n * n)
// Space Complexity - O (n)

#include <vector>
#include <iostream>

using namespace std;

void all_subsequences_with_sum(int index, int arr[], vector<int>& ds, int s, int sum, int n) {
    if (index == n) {
        if (s == sum) {
            for (auto it : ds) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[index]);
    s += arr[index];
    all_subsequences_with_sum(index + 1, arr, ds, s, sum, n); // Pick

    ds.pop_back();
    s -= arr[index];
    all_subsequences_with_sum(index + 1, arr, ds, s, sum, n); // Not Pick
}

int main() {
    int arr[] = {1, 2, 1, 3};
    int n = 4;
    int sum = 2;

    vector<int> ds;

    all_subsequences_with_sum(0, arr, ds, 0, sum, n);

    return 0;
}