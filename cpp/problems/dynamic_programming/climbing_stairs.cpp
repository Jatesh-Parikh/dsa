#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// Time Complexity - O(2 ^ n)
// Space Complexity - O(n)
int climbing_stairs_recursive(int n) {
    if (n == 0 || n == 1) return 1;

    return climbing_stairs_recursive(n - 1) + climbing_stairs_recursive(n - 2);
}

// Time Complexity - O(n), compute every value once
// Space Complexity - O(n), for both the unordered map and the recursion stack space 
int climbing_stairs_memoized(int n, unordered_map<int, int>& memo) {
    if (n == 0 || n == 1) return 1;

    if(memo.find(n) == memo.end()) {
        memo[n] = climbing_stairs_memoized(n - 1, memo) + climbing_stairs_memoized(n - 2, memo);
    }

    return memo[n];
}

// Time Complexity - O(n)
// Space Complexity - O(n), No recursion stack space used due to the iterative approach
int climbing_stairs_iterative(int n, vector<int>& arr) {
    if (n == 0 || n == 1) return 1;

    arr[0] = arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

// Time Complexity - O(n)
// Space Complexity - O(1)
int climbing_stairs_optimized(int n) {
    if (n == 0 || n == 1) return 1;

    int prev = 1, curr = 1;

    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = curr + prev;
        prev = temp; 
    }

    return curr;
}

int main() {
    int n = 12;
    unordered_map<int, int> memo;
    vector<int> arr(n + 1, -1);

    cout << climbing_stairs_recursive(n) << endl; 
    cout << climbing_stairs_memoized(n, memo) << endl; 
    cout << climbing_stairs_iterative(n, arr) << endl; 
    cout << climbing_stairs_optimized(n) << endl; 

    return 0;
}