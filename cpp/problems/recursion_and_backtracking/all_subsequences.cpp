// Time Complexity - O(2 ^ n * n)
// Space Complexity - O(n)

#include <vector>
#include <iostream>

using namespace std;

void all_subsequences(int index, int arr[], vector<int>& ds, int n) {
    if (index == n) {
        for (auto it : ds) {
            cout << it << " ";
        } 
        cout << endl;
        return;
    }

    ds.push_back(arr[index]);
    all_subsequences(index + 1, arr, ds, n); // Pick
    
    ds.pop_back();
    all_subsequences(index + 1, arr, ds, n); // Not Pick
}

int main() {
    int arr[] = {3, 1, 2};
    int n = 3;
    
    vector<int> ds;

    all_subsequences(0, arr, ds, n);

    return 0;
}