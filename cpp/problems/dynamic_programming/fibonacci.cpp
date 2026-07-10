// Dynamic Programming
// Caching the values to save time and compute
// Memoization --> Tabulation --> Space Optimization
// Top Down        Bottom Up (Staring from the base case)

#include <vector>
#include <iostream>

using namespace std;

// Time Complexity - O(n)
// Space Complexity - O(n) for both the arr and the recursion stack space
int fibonacci_memoized(int n, vector<int>& arr) {
    if (n <= 1) return n;

    if(arr[n] != -1) return arr[n];

    arr[n] = fibonacci_memoized(n - 1, arr) + fibonacci_memoized(n - 2, arr);

    return arr[n];
}

// Time Complexity - O(n)
// Space Complexity - O(n); No recursion stack space is used due to iterative approach
int fibonacci_iterative(int n, vector<int>& arr) {
    if(n <= 1) return n;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

// Time Complexity - O(n)
// Space Complexity - O(1)
int fibonacci_optimized(int n) {
    if(n <= 1) return n;

    int prev = 1, prev_2 = 0;

    for (int i = 2; i <= n; i++) {
        int curr = prev + prev_2;
        prev_2 = prev;
        prev = curr;
    }

    return prev;
}

int main() {
    int n = 50;
    vector<int> arr(n + 1, -1);

    cout << fibonacci_memoized(24, arr) << endl;

    fill(arr.begin(), arr.end(), -1);

    cout << fibonacci_iterative(24, arr) << endl;
    
    cout << fibonacci_optimized(24) << endl;

    return 0;
}