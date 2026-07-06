// Time Complexity - O(2 ^ n)
// Space Complexity - O(n)

#include <iostream>

using namespace std;

int count_subsequences_with_sum(int index, int arr[], int calculated_sum, int sum, int n) {
    if (index == n) {
        if (calculated_sum == sum) {
            return 1;
        } else {
            return 0;
        }
    }

    calculated_sum += arr[index];
    int pick = count_subsequences_with_sum(index + 1, arr, calculated_sum, sum, n);

    calculated_sum -= arr[index];
    int not_pick = count_subsequences_with_sum(index + 1, arr, calculated_sum, sum, n);

    return pick + not_pick;
}

int main() {
    int arr[] = {1, 2, 1, 3};
    int n = 4;
    int sum = 2;

    cout << count_subsequences_with_sum(0, arr, 0, sum, n) << endl;

    return 0;
}