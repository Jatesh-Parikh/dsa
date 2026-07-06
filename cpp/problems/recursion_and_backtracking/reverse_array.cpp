#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    swap(arr[left], arr[right]);
    
    reverse(arr, left + 1, right - 1);
};

void reverse_2(vector<int>& arr, int i, int n) {
    if (i >= n / 2) return;

    swap(arr[i], arr[n - i - 1]);

    reverse_2(arr, i + 1, n);
}

int main() {
    vector<int> arr = {3, 4, 1, 2, 8, 5, 7};

    reverse(arr, 0, arr.size() - 1);

    reverse_2(arr, 0, arr.size());

    for (auto it: arr) {
        cout << it << " ";
    }

    return 0;
}